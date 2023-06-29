#include <catch2/catch_test_macros.hpp>
#include <vector>

#include "expression/Expression.hpp"

std::string NUM1_STR = "-42331917115048286369321807834015434053";
std::string NUM2_STR = "-29256914613596052498173063890724085253";
std::string NUM3_STR = "109049884421922508591792876277019054036";
std::string NUM4_STR = "-137230788039330516817402106788765031062";
std::string NUM5_STR = "12730643003264005858585894694590097558";

namespace {

auto NUM1 = Int128(NUM1_STR);
auto NUM2 = Int128(NUM2_STR);
auto NUM3 = Int128(NUM3_STR);
auto NUM4 = Int128(NUM4_STR);
auto NUM5 = Int128(NUM5_STR);

}  // anonymous namespace

std::vector<Int128> NUMBERS = {NUM1, NUM2, NUM3, NUM4, NUM5};

TEST_CASE("Expression", "[expression]") {
    SECTION("Sample test") {
        Add expr(Multiply(Const(2), Variable("x")), Const(1));
        auto result = expr.eval({{"x", Int128(100)}, {"y", Int128(42)}});  // 201
        REQUIRE(result == Int128(201));
    }
    SECTION("Addition") {
        for (auto number1 : NUMBERS) {
            for (auto number2 : NUMBERS) {
                auto result = Add(Const(number1), Const(number2)).eval();
                REQUIRE(result == number1 + number2);
            }
        }
    }
    SECTION("Subtraction") {
        for (auto number1 : NUMBERS) {
            for (auto number2 : NUMBERS) {
                auto result = Subtract(Const(number1), Const(number2)).eval();
                REQUIRE(result == number1 - number2);
            }
        }
    }
    SECTION("Multiplication") {
        for (auto number1 : NUMBERS) {
            for (auto number2 : NUMBERS) {
                auto result = Multiply(Const(number1), Const(number2)).eval();
                REQUIRE(result == number1 * number2);
            }
        }
    }
    SECTION("Division") {
        for (auto number1 : NUMBERS) {
            for (auto number2 : NUMBERS) {
                if (number2 == Int128(0)) {
                    continue;
                }
                auto result = Divide(Const(number1), Const(number2)).eval();
                REQUIRE(result == number1 / number2);
            }
        }
    }
    SECTION("Negate") {
        for (auto number : NUMBERS) {
            auto result = Negate(Const(number)).eval();
            REQUIRE(result == -number);
        }
    }
}
