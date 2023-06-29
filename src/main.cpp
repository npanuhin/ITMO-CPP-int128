#include <iostream>

#include "expression/Expression.hpp"

int main() {
    Add expr(Multiply(Const(2), Variable("x")), Const(1));
    auto result = expr.eval({{"x", Int128(100)}, {"y", Int128(42)}});  // 201
    std::cout << result << std::endl;

    expr   = Const(2) * Variable("x") + Const(1);
    result = expr.eval({{"x", Int128(100)}, {"y", Int128(42)}});  // 201
    std::cout << result << std::endl;
}
