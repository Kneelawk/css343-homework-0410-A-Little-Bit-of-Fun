#include <bit_writer.h>
#include <iostream>

int main() {
    BitWriter b;
    std::vector<uint8_t> out;

    bool bit = false;
    for (int i = 0; i < 12; i++) {
        b.write(bit);
        bit = !bit;
    }

    std::cout << b.getData(out) << " bits written\n";
    std::cout << toHexString(out, "-") << '\n';
}
