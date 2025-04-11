//
// Created by cyan on 4/10/25.
//

#ifndef BIT_WRITER_H
#define BIT_WRITER_H
#include <cstdint>
#include <vector>

class BitWriter {
    std::vector<uint8_t> bytes;
    uint8_t bitIndex;

public:
    /// Constructs a new BitWriter.
    BitWriter(): bitIndex(0) {
    }

    // no destructor needed, as the default one does everything we want it to

    /// Adds a bit to the BitWriter's internal state.
    void write(bool bitValue);

    /// Copies all bytes to out, returning the number of bytes written.
    size_t getData(std::vector<uint8_t> &out);
};

#endif //BIT_WRITER_H
