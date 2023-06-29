#include "expression/Expression.hpp"

// Const
Int128 Const::eval(const std::unordered_map<std::string, Int128> &) const {
    return value;
}
std::unique_ptr<Expression> Const::clone() const {
    return std::make_unique<Const>(value);
}
void Const::print(std::ostream &os) const {
    os << value;
}

// Variable
Int128 Variable::eval(const std::unordered_map<std::string, Int128> &variables) const {
    auto it = variables.find(name);
    if (it != variables.end()) {
        return it->second;
    }
    return Int128(0);  // Default value if variable not found
}
std::unique_ptr<Expression> Variable::clone() const {
    return std::make_unique<Variable>(name);
}
void Variable::print(std::ostream &os) const {
    os << name;
}

// Negate
Int128 Negate::eval(const std::unordered_map<std::string, Int128> &variables) const {
    return -expr->eval(variables);
}
std::unique_ptr<Expression> Negate::clone() const {
    return std::make_unique<Negate>(expr->clone());
}
void Negate::print(std::ostream &os) const {
    os << "-(";
    expr->print(os);
    os << ")";
}

// Add
Int128 Add::eval(const std::unordered_map<std::string, Int128> &variables) const {
    return left->eval(variables) + right->eval(variables);
}
std::unique_ptr<Expression> Add::clone() const {
    return std::make_unique<Add>(left->clone(), right->clone());
}
void Add::print(std::ostream &os) const {
    os << "(";
    left->print(os);
    os << " + ";
    right->print(os);
    os << ")";
}

// Subtract
Int128 Subtract::eval(const std::unordered_map<std::string, Int128> &variables) const {
    return left->eval(variables) - right->eval(variables);
}
std::unique_ptr<Expression> Subtract::clone() const {
    return std::make_unique<Subtract>(left->clone(), right->clone());
}
void Subtract::print(std::ostream &os) const {
    os << "(";
    left->print(os);
    os << " - ";
    right->print(os);
    os << ")";
}

// Multiply
Int128 Multiply::eval(const std::unordered_map<std::string, Int128> &variables) const {
    return left->eval(variables) * right->eval(variables);
}
std::unique_ptr<Expression> Multiply::clone() const {
    return std::make_unique<Multiply>(left->clone(), right->clone());
}
void Multiply::print(std::ostream &os) const {
    os << "(";
    left->print(os);
    os << " * ";
    right->print(os);
    os << ")";
}

// Divide
Int128 Divide::eval(const std::unordered_map<std::string, Int128> &variables) const {
    Int128 divisor = right->eval(variables);
    if (divisor == Int128::ZERO) {
        throw std::runtime_error("Division by zero");
    }
    return left->eval(variables) / divisor;
}
std::unique_ptr<Expression> Divide::clone() const {
    return std::make_unique<Divide>(left->clone(), right->clone());
}
void Divide::print(std::ostream &os) const {
    os << "(";
    left->print(os);
    os << " / ";
    right->print(os);
    os << ")";
}

// Helper function for convenient expression construction
Add operator+(const Expression &left, const Expression &right) {
    return {left.clone(), right.clone()};
}
Subtract operator-(const Expression &left, const Expression &right) {
    return {left.clone(), right.clone()};
}
Multiply operator*(const Expression &left, const Expression &right) {
    return {left.clone(), right.clone()};
}
Divide operator/(const Expression &left, const Expression &right) {
    return {left.clone(), right.clone()};
}

// Operator for streaming expression to output
std::ostream &operator<<(std::ostream &os, const Expression &expr) {
    expr.print(os);
    return os;
}
