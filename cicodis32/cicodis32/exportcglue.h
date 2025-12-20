//
//  expotcglue.h
//  cicodis32
//
//  Created by Gabriel Valky on 05/12/2025.
//
// TODO: remove
void printHeading(std::shared_ptr<Options> options, shared<Loader> loader, Analyser& analyser)
{
    printf("#include \"cico%s.h\"\n", options->arch == arch_t::arch16 ? "16" : "32");
    
    if (options->usePrintf)
        printf("#include <stdio.h>");
    printf("\n");

    if (options->relocations)
        printf("%s\n", loader->GetMain().c_str());

    if (options->declarations)
    {
        for (address_t proc : analyser.AllMethods())
            printf("void sub_%x();\n", proc.linearOffset());
        printf("\n");
    }

    auto IndirectOrigins = [](std::vector<indirectJump_t> tab)
    {
        std::set<address_t> org;
        for (const indirectJump_t& j : tab)
            org.insert(j.origin);
        return org;
    };
    
    if (options->jit)
    {
        printf(R"(#include <stdio.h>

void indirectCall(int s, int o, int orgs, int orgo)
{
    switch (orgs*0x10000+orgo)
    {
)");
        for (address_t org : IndirectOrigins(options->indirectCalls))
        {
            printf(R"(        case 0x%x: 
            switch (s*0x10000+o)
            {
)", org.segment*0x10000 + org.offset);
            
            for (const indirectJump_t& j : options->indirectCalls)
            {
                if (j.origin == org)
                    printf("                case 0x%x: sub_%x(); return;\n", j.target.segment*0x10000 + j.target.offset, j.target.linearOffset());
            }
            printf(R"(            }
            break;
)");
        }
        printf(R"(    }
    printf("\nMISSING INDIRECT CALL %%04x:%%04x @ %%04x:%%04x\n", s, o, orgs, orgo);
    exit(3);
}

void indirectJump(int s, int o, int orgs, int orgo, int pars, int paro)
{
    switch (orgs*0x10000+orgo)
    {
)");
        for (address_t org : IndirectOrigins(options->indirectJumps))
        {
            printf(R"(        case 0x%x: 
            switch (s*0x10000+o)
            {
)", org.segment*0x10000 + org.offset);
            
            for (const indirectJump_t& j : options->indirectJumps)
            {
                if (j.origin == org)
                    printf("                case 0x%x: sub_%x(); return;\n", j.target.segment*0x10000 + j.target.offset, j.target.linearOffset());
            }
            printf(R"(            }
            break;
)");
        }
        printf(R"(    }
    printf("\nMISSING INDIRECT JUMP %%04x:%%04x @ %%04x:%%04x/%%04x:%%04x\n", s, o, orgs, orgo, pars, paro);
    exit(3);
}

)");
    }
/*
    bool anyIndirectTable = false;
    for (auto t : options->jumpTables)
        if (t->selector == "indirect")
            anyIndirectTable = true;

    if (anyIndirectTable)
    {
        printf("void indirectCall(int seg, int ofs)\n{\n");
        for (auto table : options->jumpTables)
            if (table->selector == "indirect")
            {
                std::set<int> used;
                printf("    if (seg == 0x%04x)\n    {\n", table->instruction.segment);
                printf("        switch (ofs)\n");
                printf("        {\n");
                for (int i : table->elements)
                {
                    if (!table->IsValid(i))
                        continue;
                    int v = table->GetTarget(i).offset;
                    if (used.find(v) != used.end())
                        continue;
                    used.insert(v);
                    printf("            case 0x%x: sub_%x(); return;\n", table->GetTarget(i).offset, table->GetTarget(i).linearOffset());
                }
                
                printf("        }\n");
                printf("    }\n");
            }
        printf("    stop(\"ind\");\n");
        printf("}\n\n");
    }
 */
}

void printFooter(std::shared_ptr<Options> options, shared<Loader> loader, Analyser& analyser)
{
    if (options->relocations)
        printf("%s\n", loader->GetFooter().c_str());

    std::vector<int> procMap;
    for (address_t proc : analyser.AllMethods())
    {
        for (const auto& [begin, end] : analyser.GetProcRanges(proc))
        {
            procMap.push_back(proc.linearOffset());
            procMap.push_back(begin.segment);
            procMap.push_back(begin.offset);
            procMap.push_back(end.segment);
            procMap.push_back(end.offset);
        }
    }
/*
    printf("int GetProcAt(int seg, int ofs)\n");
    printf("{\n");
    if (options->marks.size())
    {
        printf("    int marks[] = {\n");
        for (address_t mark : options->marks)
            printf("0x%04x, 0x%04x, ", mark.segment, mark.offset);
        printf("    };\n");
        printf("    for (int i=0; i<sizeof(marks)/sizeof(marks[0]); i+=2)\n");
        printf("        if (seg == marks[i] && ofs == marks[i+1])\n");
        printf("            return 0;\n");
        printf("\n");
    }
    printf("    int map[] = {\n");
    for (int i=0; i<procMap.size(); i++)
    {
        if (i%10 == 0)
            printf("        ");
        printf("0x%x, ", procMap[i]);
        if (i%10 == 9)
            printf("\n");
    }
    printf("    };\n");
    printf("\n");
    printf("    for (int i=0; i<sizeof(map)/sizeof(map[0]); i+=5)\n");
    printf("        if (seg * 16 + ofs >= map[i+1]*16 + map[i+2] && seg * 16 + ofs < map[i+3]*16 + map[i+4])\n");
    printf("            return map[i];\n");
    printf("    return 0;\n");
    printf("}\n");
*/
}

StatementIr BuildGlobalIndirectTable(std::shared_ptr<Options> options)
{
    std::vector<std::pair<shared<OperandIr>, shared<StatementIr>>> opSwitchCases;
    std::set<uint32_t> used;
    
    for (auto table : options->jumpTables)
        if (table->selector == "indirect")
        {
            for (int i : table->elements)
            {
                if (!table->IsValid(i))
                    continue;
                int v = table->GetTarget(i).segment*0x10000 + table->GetTarget(i).offset;
                if (used.find(v) != used.end())
                    continue;
                used.insert(v);
                opSwitchCases.push_back({
                    std::make_shared<OperandIr>(OperandIr{OperandIr::Type_t::Const, (int)v, 4}),
                    std::make_shared<StatementIr>(StatementIr{.type = StatementIr::Type_t::DirectCall, .target = table->GetTarget(i)})
                });
            }
        }
    
    return StatementIr{
        .type = StatementIr::Type_t::Switch,
        .address = {0, 0},
        .opSwitchSelector = "seg*0x10000 + ofs",
        .opSwitchCases = opSwitchCases
    };
}
