#include <bitset>
#include <iostream>

#include "int128/Int128.hpp"

int main() {
    // std::bitset<64> test(uint64_t(1) << 40);
    // std::cout << test << std::endl;

    // Int128 a(2);
    // Int128 b(-3);
    // std::cout << a.bit_string() << std::endl;
    // std::cout << std::endl;
    // std::cout << b.bit_string() << std::endl;
    // std::cout << std::endl;
    // std::cout << (a + b).bit_string() << std::endl;

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

    // Int128 a("-136592078868714369726000292318326650528");
    // Int128 b("109049884421922508591792876277019054036");

    // std::cout << a.bit

    // std::string NUM1 = "-42331917115048286369321807834015434053";
    // std::string NUM2 = "-29256914613596052498173063890724085253";
    // std::string NUM3 = "109049884421922508591792876277019054036";
    // std::string NUM4 = "-137230788039330516817402106788765031062";
    // std::string NUM5 = "12730643003264005858585894694590097558";

    // std::cout << Int128(NUM3).bit_string() << std::endl;
    // std::cout << Int128(NUM5).bit_string() << std::endl;

    // std::cout << std::endl << std::endl;

    // std::cout << (Int128(NUM3) / Int128(NUM5)).bit_string() << std::endl;

    auto a = Int128("-137230788039330516817402106788765031062");
    auto b = Int128("-137230788039330516817402106788765031060");

    auto c = a - b;

    std::cout << a.bit_string() << std::endl;
    std::cout << (-b).bit_string() << std::endl;

    std::cout << std::endl;

    // std::cout << (a + (-b)).bit_string() << std::endl;

    std::cout << c.bit_string() << std::endl;

    std::cout << c.str() << std::endl;
}
