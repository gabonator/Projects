//
//  alleg40tools.h
//  cicorunwin
//
//  Created by Gabriel Valky on 11/01/2026.
//
#include <fstream>

std::vector<uint8_t> load_file(const std::string& filename) {
    // Open file in binary mode at end to get size
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file)
        return {};

    std::streamsize size = file.tellg();
    if (size < 0) throw std::runtime_error("Failed to get file size");

    file.seekg(0, std::ios::beg);

    std::vector<uint8_t> buffer(static_cast<size_t>(size));
    if (!file.read(reinterpret_cast<char*>(buffer.data()), size))
        throw std::runtime_error("Failed to read file: " + filename);

    return buffer;
}
// LZSS decompression for Allegro 4 (memory version)
std::vector<uint8_t> decompress_lzss(const std::vector<uint8_t>& input)
{
    std::vector<uint8_t> output;
    
    if (input.size() < 4)
        return {};
    if (memcmp(input.data(), "slh.", 4) == 0)
    {
        output.assign(input.begin() + 4, input.end());
        return output;
    }
    if (memcmp(input.data(), "slh!", 4) != 0)
        return {};

    const int N = 4096;
     const int F = 18;
     const int THRESHOLD = 2;

     
     std::vector<uint8_t> text_buf(N + F - 1, 0);
     int r = N - F;
     unsigned int flags = 0;

     size_t in_pos = 4;
     auto get_byte = [&](int& b) -> bool {
         if (in_pos >= input.size()) return false;
         b = input[in_pos++];
         return true;
     };

     while (true) {
         // Load new flags byte if needed
         if (((flags >>= 1) & 0x100) == 0) {
             int c;
             if (!get_byte(c)) break;
             flags = c | 0xFF00;
         }

         if (flags & 1) {
             // Literal byte
             int c;
             if (!get_byte(c)) break;
             output.push_back(static_cast<uint8_t>(c));
             text_buf[r++] = static_cast<uint8_t>(c);
             r &= (N - 1);
         } else {
             // Reference to previous string
             int i, j;
             if (!get_byte(i)) break;
             if (!get_byte(j)) break;

             i |= ((j & 0xF0) << 4);
             j = (j & 0x0F) + THRESHOLD;

             for (int k = 0; k <= j; k++) {
                 uint8_t c = text_buf[(i + k) & (N - 1)];
                 output.push_back(c);
                 text_buf[r++] = c;
                 r &= (N - 1);
             }
         }
     }

     return output;
 }

struct dataresource_t {
    enum class type_e { PAL, BMP, FONT, SAMP } type;
    std::string name;              // NAME property
    std::vector<uint8_t> payload;  // raw payload
};

// helper: convert 4 bytes big-endian to uint32_t
static uint32_t be32(const std::vector<uint8_t>& data, size_t pos) {
    if (pos + 4 > data.size()) throw std::runtime_error("Unexpected EOF");
    return (data[pos]<<24)|(data[pos+1]<<16)|(data[pos+2]<<8)|data[pos+3];
}

// helper: read 4-byte string
static std::string read4(const std::vector<uint8_t>& data, size_t pos) {
    if (pos + 4 > data.size()) throw std::runtime_error("Unexpected EOF");
    return std::string(reinterpret_cast<const char*>(&data[pos]), 4);
}

std::vector<dataresource_t> load_allegro_datafile(const std::vector<uint8_t>& filedata) {
    size_t pos = 0;

    if (filedata.size() < 8) throw std::runtime_error("File too small");

    std::string magic = read4(filedata, pos);
    pos += 4;
    if (magic != "ALL.") throw std::runtime_error("Not an Allegro datafile");

    uint32_t object_count = be32(filedata, pos);
    pos += 4;

    std::vector<dataresource_t> resources;

    for (uint32_t obj = 0; obj < object_count; ++obj) {
        std::string orig_name;

        // Read properties
        while (true) {
            if (pos + 4 > filedata.size()) throw std::runtime_error("Unexpected EOF");
            std::string id = read4(filedata, pos);

            if (id == "prop") {
                pos += 4;
                if (pos + 4 > filedata.size()) throw std::runtime_error("Unexpected EOF");
                std::string pname = read4(filedata, pos);
                pos += 4;

                uint32_t len = be32(filedata, pos);
                pos += 4;

                if (pos + len > filedata.size()) throw std::runtime_error("Unexpected EOF");
                std::string val(reinterpret_cast<const char*>(&filedata[pos]), len);
                pos += len;

                if (pname == "NAME") orig_name = val;
                continue;
            }

            // payload
            if (pos + 8 > filedata.size()) throw std::runtime_error("Unexpected EOF");
            std::string payload_type = read4(filedata, pos);
            pos += 4;
            uint32_t payload_size = be32(filedata, pos);
            pos += 4;
            uint32_t payload_size2 = be32(filedata, pos);
            pos += 4;
            assert(payload_size == payload_size2);

            if (pos + payload_size > filedata.size()) throw std::runtime_error("Unexpected EOF");

            dataresource_t res;

            if (payload_type == "PAL ") res.type = dataresource_t::type_e::PAL;
            else if (payload_type == "BMP ") res.type = dataresource_t::type_e::BMP;
            else if (payload_type == "FONT") res.type = dataresource_t::type_e::FONT;
            else if (payload_type == "SAMP") res.type = dataresource_t::type_e::SAMP;
            else if (payload_type == "info")
            {
                pos += payload_size;
                break;
            }
            else throw std::runtime_error("Unknown payload type: " + payload_type);

            res.name = orig_name;
            res.payload.assign(filedata.begin() + pos, filedata.begin() + pos + payload_size);
            pos += payload_size;

            resources.push_back(std::move(res));
            break; // done with this object
        }
    }

    return resources;
}
