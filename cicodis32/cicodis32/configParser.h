//
//  configParser.h
//  cicodis32
//
//  Created on 05/12/2025.
//

#pragma once

class ConfigParser {
public:
    static bool ParseConfiguration(const std::vector<uint8_t>& fileContents, std::shared_ptr<Options> options);
    
private:
    static void ParseConfigLine(const std::string& line, std::shared_ptr<Options> options);
    static void ParseConfigObject(CJson& json, std::shared_ptr<Options> options);
    static void ParseIndirectCall(CJson& json, std::shared_ptr<Options> options);
    static void ParseIndirectJump(CJson& json, std::shared_ptr<Options> options);
    static void ParseJumpTable(CJson& json, std::shared_ptr<Options> options);
    static void ParseInject(CJson& json, std::shared_ptr<Options> options);
    static void ParseMarks(CJson& json, std::shared_ptr<Options> options);
    static void ParseOverlay(CJson& json, std::shared_ptr<Options> options);
    static void ParseHint(CJson& json, std::shared_ptr<Options> options);
};


bool ConfigParser::ParseConfiguration(const std::vector<uint8_t>& fileContents, std::shared_ptr<Options> options)
{
    if (fileContents.empty())
        return false;
    
    const char* strJson = (const char*)&fileContents[0];
    
    for (std::string line : utils::split(strJson, "\n"))
    {
        if (line.empty() || line.starts_with("//"))
            continue;
        
        ParseConfigLine(line, options);
    }
    
    return true;
}

void ConfigParser::ParseConfigLine(const std::string& line, std::shared_ptr<Options> options)
{
    CJson json(line.c_str());
    
    if (json["id"] == "config")
    {
        ParseConfigObject(json, options);
    }
    else if (json["id"] == "indirectCall")
    {
        ParseIndirectCall(json, options);
    }
    else if (json["id"] == "indirectJump")
    {
        ParseIndirectJump(json, options);
    }
    else if (json["id"] == "jumpTable")
    {
        ParseJumpTable(json, options);
    }
    else if (json["id"] == "inject")
    {
        ParseInject(json, options);
    }
    else if (json["id"] == "marks")
    {
        ParseMarks(json, options);
    }
    else if (json["id"] == "overlay")
    {
        ParseOverlay(json, options);
    }
    else if (json["id"] == "hint" && json["label"])
    {
        ParseHint(json, options);
    }
    else
    {
        printf("Wrong json: '%s'\n", line.c_str());
        assert(0);
    }
}

void ConfigParser::ParseConfigObject(CJson& json, std::shared_ptr<Options> options)
{
    json.ForEach([&](const CSubstring& k, const CSubstring& v){
        char temp[1024];
        k.ToString(temp, 1024);
        if (k == "id")
            return;
        if (k == "loader")
            v.ToString(options->loader, sizeof(options->loader));
        else if (k == "executable")
            v.ToString(options->exec, sizeof(options->exec));
        else if (k == "architecture" && v == "arch16")
            options->arch = arch_t::arch16;
        else if (k == "architecture" && v == "arch32")
        {
            address_t::mode32 = true;
            options->arch = arch_t::arch32;
        }
        else if (k == "loadAddressShift")
            options->loadAddressShift = CConversion(v).ToInt();
        else if (k == "loadAddress")
            options->loadAddress = CConversion(v).ToInt();
        else if (k == "start" && v == "false")
            options->start = false;
        else if (k == "verbose" && v == "true")
            options->verbose = true;
        else if (k == "verboseAsm" && v == "true")
            options->verboseAsm = true;
        else if (k == "verboseAsm" && v == "false")
            options->verboseAsm = false;
        else if (k == "printf" && v == "true")
            options->usePrintf = true;
        else if (k == "jit" && v == "true")
            options->jit = true;
        else if (k == "verboseAddr" && v == "false")
        {
            options->printProcAddress = false;
            options->printLabelAddress = false;
        }
        else if (k == "recursive" && v == "false")
            options->recursive = false;
        else if (k == "relocations" && v == "false")
            options->relocations = false;
        else if (k == "declarations" && v == "false")
            options->declarations = false;
        else if (k == "stackShiftAlways" && v == "true")
            options->stackShiftAlways = true;
        else if (k == "procList")
        {
            CJson(v).ForEach([&](const CSubstring& v)
            {
                std::string strAddr = CJson(v).GetString();
                if (strAddr.find("+") != std::string::npos)
                {
                    int plus = (int)strAddr.find("+");
                    std::string modifier = strAddr.substr(plus);
                    strAddr = strAddr.substr(0, plus);
                    procRequest_t req = procRequest_t::none;
                    if (modifier == "+returnZero")
                        req = procRequest_t((int)procRequest_t::returnZero | (int)procRequest_t::callNear);
                    else if (modifier == "+returnCarry+returnZero")
                        req = procRequest_t((int)procRequest_t::returnZero | (int)procRequest_t::returnCarry | (int)procRequest_t::callNear);
                    else
                        assert(0);
                    options->procModifiers.insert({address_t::fromString(strAddr), req});
                }
                options->procList.push_back(address_t::fromString(strAddr));
            });
        }
        else if (k == "isolate")
        {
            CJson(v).ForEach([&](const CSubstring& v)
            {
                options->isolateLabels.insert(address_t::fromString(CJson(v).GetString()));
            });
        }
        else if (k == "terminator")
        {
            CJson(v).ForEach([&](const CSubstring& v)
            {
                options->terminators.insert(address_t::fromString(CJson(v).GetString()));
            });
        }
        else
        {
            char temp1[128];
            char temp2[128];
            printf("Wrong attribute: %s=%s\n", k.ToString(temp1, 128), v.ToString(temp2, 128));
            assert(0);
        }
    });
}

void ConfigParser::ParseIndirectCall(CJson& json, std::shared_ptr<Options> options)
{
    address_t target = address_t::fromString(json["target"].GetString());
    address_t origin = address_t::fromString(json["origin"].GetString());
    options->indirectCalls.push_back({.target = target, .origin = origin});
}

void ConfigParser::ParseIndirectJump(CJson& json, std::shared_ptr<Options> options)
{
    address_t target = address_t::fromString(json["target"].GetString());
    address_t parent = address_t::fromString(json["parent"].GetString());
    address_t origin = address_t::fromString(json["origin"].GetString());
    options->indirectJumps.push_back({.target = target, .parent = parent, .origin = origin});
}

void ConfigParser::ParseJumpTable(CJson& json, std::shared_ptr<Options> options)
{
    if (json["callsFar"])
    {
        std::vector<uint16_t> targets;
        std::vector<int> elements;

        address_t instruction = address_t::fromString(json["addr"].GetString());
        CJson(json["callsFar"]).ForEach([&](const CSubstring& v)
        {
            address_t target = address_t::fromString(CJson(v).GetString());
            targets.push_back(target.offset);
            targets.push_back(target.segment);
            elements.push_back((int)elements.size());
        });
        uint16_t* ptargets = new uint16_t[targets.size()];
        memcpy(ptargets, &targets[0], sizeof(uint16_t) * targets.size());
        
        std::shared_ptr<jumpTable_t> jt = std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = instruction, .baseptr = (uint8_t*)ptargets, .release = true,
            .type = jumpTable_t::switch_e::CallDwords, .useCaseOffset = true, .elements = elements});
        
        options->jumpTables.push_back(jt);
    }
    else if (json["callsNear"])
    {
        std::vector<uint16_t> targets;
        std::vector<int> elements;

        address_t instruction = address_t::fromString(json["addr"].GetString());
        CJson(json["callsNear"]).ForEach([&](const CSubstring& v)
        {
            address_t target = address_t::fromString(CJson(v).GetString());
            assert(target.segment == instruction.segment);
            targets.push_back(target.offset);
            elements.push_back((int)elements.size());
        });
        uint16_t* ptargets = new uint16_t[targets.size()];
        memcpy(ptargets, &targets[0], sizeof(uint16_t) * targets.size());
        
        std::shared_ptr<jumpTable_t> jt = std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = instruction, .baseptr = (uint8_t*)ptargets, .release = true,
            .type = jumpTable_t::switch_e::CallWords, .useCaseOffset = true, .elements = elements});
        
        options->jumpTables.push_back(jt);
    }
    else if (json["calls32"])
    {
        std::vector<uint32_t> targets;
        std::vector<int> elements;

        address_t instruction = address_t::fromString(json["addr"].GetString());
        CJson(json["calls32"]).ForEach([&](const CSubstring& v)
        {
            address_t target = address_t::fromString(CJson(v).GetString());
            assert(target.segment == instruction.segment);
            targets.push_back(target.offset);
            elements.push_back((int)elements.size());
        });
        uint32_t* ptargets = new uint32_t[targets.size()];
        memcpy(ptargets, &targets[0], sizeof(uint32_t) * targets.size());
        
        std::shared_ptr<jumpTable_t> jt = std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = instruction, .baseptr = (uint8_t*)ptargets, .release = true,
            .type = jumpTable_t::switch_e::Call32, .useCaseOffset = true, .elements = elements});
        
        options->jumpTables.push_back(jt);
    }
    else if (json["jumps"])
    {
        std::vector<uint16_t> targets;
        std::vector<int> elements;

        address_t instruction = address_t::fromString(json["addr"].GetString());
        CJson(json["jumps"]).ForEach([&](const CSubstring& v)
        {
            address_t target = address_t::fromString(CJson(v).GetString());
            assert(target.segment == instruction.segment);
            targets.push_back(target.offset);
            elements.push_back((int)elements.size());
        });
        uint16_t* ptargets = new uint16_t[targets.size()];
        memcpy(ptargets, &targets[0], sizeof(uint16_t) * targets.size());
        
        std::shared_ptr<jumpTable_t> jt = std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = instruction, .baseptr = (uint8_t*)ptargets, .release = true,
            .type = jumpTable_t::switch_e::JumpWords, .useCaseOffset = true, .elements = elements});
        
        options->jumpTables.push_back(jt);
    }
    else if (json["jumps32"])
    {
        std::vector<uint32_t> targets;
        std::vector<int> elements;

        address_t instruction = address_t::fromString(json["addr"].GetString());
        CJson(json["jumps32"]).ForEach([&](const CSubstring& v)
        {
            address_t target = address_t::fromString(CJson(v).GetString());
            assert(target.segment == instruction.segment);
            targets.push_back(target.offset);
            elements.push_back((int)elements.size());
        });
        uint32_t* ptargets = new uint32_t[targets.size()];
        memcpy(ptargets, &targets[0], sizeof(uint32_t) * targets.size());
        
        std::shared_ptr<jumpTable_t> jt = std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = instruction, .baseptr = (uint8_t*)ptargets, .release = true,
            .type = jumpTable_t::switch_e::Jump32, .useCaseOffset = true, .elements = elements});
        
        options->jumpTables.push_back(jt);
    }
    else
    {
        address_t instruction = address_t::fromString(json["addr"].GetString());
        address_t table = address_t::fromString(json["table"].GetString());
        
        std::string strType = json["type"].GetString();
        std::string selector = json["selector"].GetString();
        int minaddr = json["filterMin"] ? json["filterMin"].GetNumber() : 0;
        
        bool useCaseOffset = json["useCaseOffset"] ? json["useCaseOffset"].GetBoolean() : false;

        std::vector<int> elements;

        if (json["entries"].IsArray())
        {
            CJson(json["entries"]).ForEach([&](const CSubstring& v)
            {
                elements.push_back(CJson(v).GetNumber());
            });
        }
        else
        {
            int entries = json["entries"].GetNumber();
            for (int i=0; i<entries; i++)
                elements.push_back(i);
        }
        
        jumpTable_t::switch_e type = jumpTable_t::switch_e::None;
        if (strType == "jumpwords")
            type = jumpTable_t::switch_e::JumpWords;
        else if (strType == "callwords")
            type = jumpTable_t::switch_e::CallWords;
        else if (strType == "calldwords")
            type = jumpTable_t::switch_e::CallDwords;
        else if (strType == "jumpfix")
            type = jumpTable_t::switch_e::JumpFix;
        else if (strType == "jump32")
            type = jumpTable_t::switch_e::Jump32;
        else if (strType == "call32")
            type = jumpTable_t::switch_e::Call32;
        else
            assert(0);
        
        std::shared_ptr<jumpTable_t> jt = std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = instruction, .table = table, .type = type, .elements = elements, .selector = selector,
            .minaddr = minaddr, .useCaseOffset = useCaseOffset});
        
        options->jumpTables.push_back(jt);
    }
}

void ConfigParser::ParseInject(CJson& json, std::shared_ptr<Options> options)
{
    options->inject.insert({address_t::fromString(json["addr"].GetString()), json["text"].GetString()});
}

void ConfigParser::ParseMarks(CJson& json, std::shared_ptr<Options> options)
{
    CJson(json["marks"]).ForEach([&](const CSubstring& v)
    {
        options->marks.insert(address_t::fromString(CJson(v).GetString()));
    });
}

void ConfigParser::ParseOverlay(CJson& json, std::shared_ptr<Options> options)
{
    options->overlayBase = address_t::fromString(json["addr"].GetString());
    CJson(json["bytes"]).ForEach([&](const CSubstring& v)
    {
        int b = CJson(v).GetNumber();
        options->overlayBytes.push_back(b);
    });
}

void ConfigParser::ParseHint(CJson& json, std::shared_ptr<Options> options)
{
    hint_t hint{
        .string = false, // movsb/movsw/lodsb/lodsw/...
        .label = json["label"].GetString(),
        .pattern = json["pattern"].GetString(),
        .direction = json["direction"] ? json["direction"].GetString() : "",
        .type = hint_t::typeFromString(json["type"].GetString())
    };

    if (hint.label == "*")
    {
        options->memHintDefault = hint;
    }
    else
    {
        options->memHints.push_back(hint);
        //auto& vect = options->memHints[hint.label];
        //vect.push_back(hint);
        
        hint.string = true;
        if (hint.pattern == "ds, esi")
        {
            hint.pattern = "DS_ESI";
            options->memHints.push_back(hint);
        }
        if (hint.pattern == "es, edi")
        {
            hint.pattern = "ES_EDI";
            options->memHints.push_back(hint);
        }
        if (hint.pattern == "ds")
        {
            hint.pattern = "DS_SI";
            options->memHints.push_back(hint);
        }
        if (hint.pattern == "es")
        {
            hint.pattern = "ES_DI";
            options->memHints.push_back(hint);
        }

    }
}
