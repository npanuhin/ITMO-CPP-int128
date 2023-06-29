#include <bitset>
#include <iostream>

#include "int128/Int128.hpp"

int main() {
    // std::bitset<64> test(uint64_t(1) << 40);
    // std::cout << test << std::endl;

    // Int128 a(2);
    // Int128 b(3);
    // std::cout << a << ' ' << b << std::endl;

    // Int128 a(369), b(-286);

    // std::cout << a.bit_string() << std::endl << b.bit_string() << std::endl;

    // std::cout << std::endl;

    // std::cout << a << std::endl << b << std::endl;

    // std::cout << std::endl;

    // std::cout << -a << std::endl << -b << std::endl;

    // Int128 a(INT64_MAX);
    // std::cout << a << std::endl;

    // for (int i = 0; i < 128; ++i) {
    //     // Print the same in bits using bitset
    //     // std::bitset<64> test((uint64_t)(1) << i);
    //     // std::cout << i << ":\t" << test << std::endl;

    //     std::string expected = std::string(127 - i, '0') + std::string(1, '1') + std::string(i, '0');
    //     std::cout << i << std::endl << (Int128(1) << i).bit_string() << std::endl << expected << std::endl;
    // }

    // Int128 x = Int128(1);
    // x <<= 70;

    // std::string expected = std::string(127 - 70, '0') + std::string(1, '1') + std::string(70, '0');
    // std::cout << x.bit_string() << std::endl << expected << std::endl;

    // x <<= 2;

    // expected = std::string(127 - 72, '0') + std::string(1, '1') + std::string(72, '0');
    // std::cout << x.bit_string() << std::endl << expected << std::endl;
}
