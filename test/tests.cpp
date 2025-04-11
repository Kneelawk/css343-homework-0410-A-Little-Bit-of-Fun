#include "bit_writer.h"
#include <gtest/gtest.h>

TEST(a_little_bit_of_fun, constructor) {
    BitWriter b;
    std::vector<uint8_t> out;
    EXPECT_EQ(0, b.getData(out));
    EXPECT_TRUE(out.empty());
}

TEST(a_little_bit_of_fun, write_one_bit) {
    BitWriter b;
    std::vector<uint8_t> out;
    const std::vector<uint8_t> expected = {1};

    b.write(true);

    EXPECT_EQ(1, b.getData(out));
    EXPECT_EQ(expected, out);
}

TEST(a_little_bit_of_fun, write_twelve_bits) {
    BitWriter b;
    std::vector<uint8_t> out;
    const std::vector<uint8_t> expected = {0xAA, 0x0A};

    bool bit = false;
    for (int i = 0; i < 12; i++) {
        b.write(bit);
        bit = !bit;
    }

    EXPECT_EQ(12, b.getData(out));
    EXPECT_EQ(expected, out);
}

TEST(a_little_bit_of_fun, write_eleven_bits) {
    BitWriter b;
    std::vector<uint8_t> out;
    const std::vector<uint8_t> expected = {0xAA, 0x02};

    bool bit = false;
    for (int i = 0; i < 11; i++) {
        b.write(bit);
        bit = !bit;
    }

    EXPECT_EQ(11, b.getData(out));
    EXPECT_EQ(expected, out);
}

TEST(a_little_bit_of_fun, simple_to_hex_string) {
    const std::vector<uint8_t> vec = {0xDE, 0xAD, 0xBE, 0xEF};
    const std::string result = toHexString(vec);
    EXPECT_EQ("DEADBEEF", result);
}

TEST(a_little_bit_of_fun, delim_to_hex_string) {
    const std::vector<uint8_t> vec = {0xDE, 0xAD, 0xBE, 0xEF};
    const std::string result = toHexString(vec, "-");
    EXPECT_EQ("DE-AD-BE-EF", result);
}
