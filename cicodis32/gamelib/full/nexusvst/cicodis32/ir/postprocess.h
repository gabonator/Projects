//
//  postprocess.h
//  cicodis32
//
//  SEH (Structured Exception Handling) cleanup pass.
//  1. Detects ALL SEH prologues (not just the first one)
//  2. Keeps the SEH prologue pushes (so all esp+N offsets remain correct)
//  3. Replaces fs: reads with constant 0, removes fs: writes
//  4. Fixes stack balance by adjusting epilogue esp+= values
//  5. Removes stop("stack_unbalanced") / stop("stack_below") only AFTER fixing
//

#pragma once

// --- Pattern matchers ---

static bool IsFsRead(const StatementIr& st)
{
    if (st.type == StatementIr::Type_t::Assignment && st.opin1)
    {
        if (st.opin1->type == OperandIr::Type_t::Memory && st.opin1->memSegment == "fs")
            return true;
    }
    if (st.type == StatementIr::Type_t::Function && st.opin1)
    {
        if (st.opin1->type == OperandIr::Type_t::Memory && st.opin1->memSegment == "fs")
            return true;
    }
    return false;
}

static bool IsFsWrite(const StatementIr& st)
{
    if (st.type == StatementIr::Type_t::Assignment && st.opd)
    {
        if (st.opd->type == OperandIr::Type_t::Memory && st.opd->memSegment == "fs")
            return true;
    }
    return false;
}

static bool IsSEHPushConst(const StatementIr& st)
{
    return st.type == StatementIr::Type_t::Function
        && st.func == "push32"
        && st.opin1
        && st.opin1->type == OperandIr::Type_t::Const;
}

static bool IsPush32Reg(const StatementIr& st)
{
    return st.type == StatementIr::Type_t::Function
        && st.func == "push32"
        && st.opin1
        && st.opin1->type == OperandIr::Type_t::Register;
}

static bool IsStopStackUnbalanced(const StatementIr& st)
{
    return st.type == StatementIr::Type_t::Stop
        && (st.stop.find("stack_unbalanced") != std::string::npos
            || st.stop.find("stack_below") != std::string::npos);
}

// Parse deficit from either "stack_below, N/M" or "stack_unbalanced, N/M"
// Returns the amount to ADD to the preceding esp+= to fix the balance.
// Returns 0 if not parseable.
static int ParseStackDeficit(const std::string& stop)
{
    // Look for ", N/M" pattern in the stop message
    auto comma = stop.find(", ");
    if (comma == std::string::npos) return 0;
    auto rest = stop.substr(comma + 2);
    auto slash = rest.find('/');
    if (slash == std::string::npos) return 0;
    int expected = std::atoi(rest.substr(0, slash).c_str());
    int actual = std::atoi(rest.substr(slash + 1).c_str());
    int deficit = expected - actual;
    // Sanity check: deficit should be positive and small (< 64 bytes)
    if (deficit > 0 && deficit <= 64)
        return deficit;
    return 0;
}

// Check if statement is: esp += <const>  (Binary: esp = esp + const)
static bool IsEspAdd(const StatementIr& st, uint64_t* outValue = nullptr)
{
    if (st.type == StatementIr::Type_t::Binary
        && st.opd && st.opd->type == OperandIr::Type_t::Register && st.opd->regName == "esp"
        && st.opin1 && st.opin1->type == OperandIr::Type_t::Register && st.opin1->regName == "esp"
        && st.oper == "+"
        && st.opin2 && st.opin2->type == OperandIr::Type_t::Const)
    {
        if (outValue) *outValue = st.opin2->constValue;
        return true;
    }
    return false;
}


// --- Main SEH cleanup ---

void RemoveSEH(shared<ProcIr> prog)
{
    auto& lines = prog->lines;
    if (lines.size() < 5)
        return;

    // --- Phase 1: Detect and mark ALL SEH prologues ---
    // Scan the ENTIRE function (not just first 20 lines) for the pattern:
    //   push32(0xffffffff), push32(<handler>), [fs read], push32(<reg>), [fs write]
    bool hasAnySEH = false;

    for (size_t i = 0; i + 4 < lines.size(); i++)
    {
        // Look for push32(0xffffffff)
        if (!IsSEHPushConst(lines[i]))
            continue;
        if (lines[i].opin1->constValue != 0xffffffff
            && lines[i].opin1->constValue != (uint64_t)(int32_t)-1)
            continue;

        // Look ahead for push32(<handler_addr>) within next 3 lines
        bool foundHandler = false;
        size_t handlerIdx = 0;
        for (size_t j = i + 1; j < std::min(i + 4, lines.size()); j++)
        {
            if (IsSEHPushConst(lines[j]) && lines[j].opin1->constValue >= 0x10000000)
            {
                foundHandler = true;
                handlerIdx = j;
                break;
            }
        }
        if (!foundHandler)
            continue;

        // Look for fs read and push32(reg) nearby (within next 5 lines after handler)
        bool foundFsRead = false;
        bool foundRegPush = false;
        for (size_t j = handlerIdx + 1; j < std::min(handlerIdx + 5, lines.size()); j++)
        {
            if (IsFsRead(lines[j]))
                foundFsRead = true;
            if (IsPush32Reg(lines[j]) && foundFsRead)
                foundRegPush = true;
        }

        if (foundFsRead && foundRegPush)
        {
            // Mark the SEH prologue
            lines[i].comment = "SEH prologue";
            lines[handlerIdx].comment = "SEH prologue";
            hasAnySEH = true;

            // Mark the push32(reg) after fs read
            for (size_t j = handlerIdx + 1; j < std::min(handlerIdx + 5, lines.size()); j++)
            {
                if (IsFsRead(lines[j]) && lines[j].type == StatementIr::Type_t::Assignment && lines[j].opd)
                {
                    lines[j].opin1 = std::make_shared<OperandIr>(OperandIr{OperandIr::Type_t::Const, 0, 4});
                    lines[j].comment = "SEH: fs read replaced with 0";
                }
                else if (IsFsRead(lines[j]))
                {
                    lines[j].type = StatementIr::Type_t::Comment;
                    lines[j].comment = "SEH removed";
                }
                if (IsPush32Reg(lines[j]) && !lines[j].comment.empty() == false)
                {
                    // Only mark the first reg push after fs read as SEH prologue
                    if (foundFsRead)
                    {
                        lines[j].comment = "SEH prologue";
                        break;
                    }
                }
            }
        }
    }

    // --- Phase 2: Remove all fs: reads and writes (for ALL functions) ---
    for (auto& st : lines)
    {
        if (IsFsWrite(st))
        {
            st.type = StatementIr::Type_t::Comment;
            st.comment = "SEH removed";
        }
        if (IsFsRead(st) && st.type == StatementIr::Type_t::Assignment && st.opd)
        {
            st.opin1 = std::make_shared<OperandIr>(OperandIr{OperandIr::Type_t::Const, 0, 4});
            st.comment = "SEH: fs read replaced with 0";
        }
        else if (IsFsRead(st))
        {
            st.type = StatementIr::Type_t::Comment;
            st.comment = "SEH removed";
        }
    }

    // --- Phase 3: Fix stack balance at each stop with deficit info ---
    // Both "stack_below, N/M" and "stack_unbalanced, N/M" can be auto-fixed.
    for (size_t i = 0; i < lines.size(); i++)
    {
        auto& st = lines[i];
        if (st.type != StatementIr::Type_t::Stop)
            continue;

        // Try to parse deficit from the stop message
        int deficit = ParseStackDeficit(st.stop);
        if (deficit > 0)
        {
            // Search backwards for the nearest esp += K
            bool fixed = false;
            for (int j = (int)i - 1; j >= 0 && j >= (int)i - 10; j--)
            {
                uint64_t espVal = 0;
                if (IsEspAdd(lines[j], &espVal))
                {
                    // Increase the esp+= by the deficit
                    lines[j].opin2 = std::make_shared<OperandIr>(
                        OperandIr{OperandIr::Type_t::Const, espVal + deficit, 4});
                    lines[j].comment = utils::format("SEH fixed: was +%d, deficit %d", (int)espVal, deficit);
                    st.type = StatementIr::Type_t::Comment;
                    st.comment = utils::format("SEH fixed (was %s)", st.stop.c_str());
                    fixed = true;
                    break;
                }
            }
            if (fixed) continue;
        }

        // For stops without parseable deficit, just remove the marker
        if (IsStopStackUnbalanced(st))
        {
            st.type = StatementIr::Type_t::Comment;
            st.comment = utils::format("SEH removed (was %s)", st.stop.c_str());
        }
    }
}
