//
// Created by cyan on 4/10/25.
//

#include <sstream>

#include "bit_writer.h"

#include <iomanip>

void BitWriter::write(const bool bitValue) {
    if (bytes.empty() || bitIndex >= 8) {
        bitIndex = 0;
        bytes.push_back(0);
    }

    if (bitValue) {
        const size_t i = bytes.size() - 1;
        bytes[i] = bytes[i] | 1 << bitIndex;
    }

    bitIndex++;
}

size_t BitWriter::getData(std::vector<uint8_t> &out) const {
    if (bytes.empty()) {
        return 0;
    }

    // copy bytes to out
    out = bytes;

    return (bytes.size() - 1) * 8 + bitIndex;
}

std::string toHexString(const std::vector<uint8_t> &bytes, const std::string &delim) {
    std::stringstream ss;
    ss << std::hex << std::uppercase << std::setfill('0');

    bool first = true;
    for (const uint8_t byte: bytes) {
        if (!first) {
            ss << delim;
        }
        ss << std::setw(2) << static_cast<int>(byte);
        first = false;
    }

    return ss.str();
}
