//
// Created by cyan on 4/10/25.
//

#include "bit_writer.h"

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

size_t BitWriter::getData(std::vector<uint8_t> &out) {
    if (bytes.empty()) {
        return 0;
    }

    // copy bytes to out
    out = bytes;

    return (bytes.size() - 1) * 8 + bitIndex;
}
