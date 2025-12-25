//
//  address.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//

#pragma once

#include <string>
#include <regex>
#include <cstdio>
#include <cstdlib>
#include <cassert>

struct address_t {
    static bool mode32;

    int segment{-1};
    int offset{-1};
    operator bool()
    {
        return segment != -1;
    }
    address_t() {}
    address_t(long s, long o) : segment{(int)s}, offset{(int)o}
    {
        assert(o>=0);
    }
    address_t(int s, int o) : segment{s}, offset{o}
    {
        assert(o>=0);
    }
    bool isValid() const
    {
        return segment != -1;
    }
    int linearOffset() const
    {
        if (mode32)
            return offset;
        else
            return segment*0x10+offset;
    }
    bool operator == (const address_t& b) const
    {
        return segment == b.segment && offset == b.offset;
    }
    bool operator != (const address_t& b) const
    {
        return segment != b.segment || offset != b.offset;
    }
    static address_t fromString(const std::string& s)
    {
        std::regex functionSegofs("^([0-9a-fA-f]+):([0-9a-fA-f]+)$");
        std::smatch matches;
        if (std::regex_search(s, matches, functionSegofs))
        {
            std::string strSeg = matches.str(1);
            std::string strOfs = matches.str(2);
            int addrSeg = (int)strtol(strSeg.c_str(), nullptr, 16);
            int addrOfs = (int)strtol(strOfs.c_str(), nullptr, 16);
            return {addrSeg, addrOfs};
        }
        assert(0);
        return {0, 0};
    }
    
    std::string toString() const
    {
        char temp[128];
        snprintf(temp, sizeof(temp), "%04x:%04x", segment, offset);
        return temp;
    }

//    std::string toLinearString() const
//    {
//        char temp[128];
//        snprintf(temp, sizeof(temp), "%x", linearOffset());
//        return temp;
//    }

//    bool operator<(const address_t& other) const {
//        if (segment != other.segment)
//            return segment < other.segment;
//        return offset < other.offset;
//    }
//    bool operator>(const address_t& other) const {
//        if (segment != other.segment)
//            return segment > other.segment;
//        return offset > other.offset;
//    }
//    bool operator<=(const address_t& other) const {
//        return !(*this > other);
//    }
//    bool operator>=(const address_t& other) const {
//        return !(*this < other);
//    }
    auto operator<=>(const address_t& other) const = default;
};

//struct cmp_adress_t { // TODO: remove!
//    bool operator()(const address_t& a, const address_t& b) const {
//        if (a.segment != b.segment)
//            return a.segment < b.segment;
//        return a.offset < b.offset;
//        //return a.segment*0x10+a.offset < b.segment*0x10+b.offset;
//    }
//};
//

inline bool address_t::mode32{false};
