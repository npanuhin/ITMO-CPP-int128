#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <iostream>
#include <memory>
#include <unordered_map>
#include <utility>

#include "int128/Int128.hpp"

class Expression {
public:
    virtual ~Expression()                                                               = default;
    virtual Int128 eval(const std::unordered_map<std::string, Int128>& variables) const = 0;
    virtual std::unique_ptr<Expression> clone() const                                   = 0;
    virtual void print(std::ostream& os) const                                          = 0;
};

class Const: public Expression {
private:
    Int128 value;

public:
    explicit Const(const Int128& value) : value(value) {}
    explicit Const(const int64_t value) : value(value) {}

    Int128 eval(const std::unordered_map<std::string, Int128>&) const override;
    std::unique_ptr<Expression> clone() const override;
    void print(std::ostream& os) const override;
};

class Variable: public Expression {
private:
    std::string name;

public:
    explicit Variable(std::string name) : name(std::move(name)) {}

    Int128 eval(const std::unordered_map<std::string, Int128>& variables) const override;
    std::unique_ptr<Expression> clone() const override;
    void print(std::ostream& os) const override;
};

class Negate: public Expression {
private:
    std::unique_ptr<Expression> expr;

public:
    explicit Negate(std::unique_ptr<Expression> expr) : expr(std::move(expr)) {}
    explicit Negate(const Expression& expr) : expr(expr.clone()) {}

    Int128 eval(const std::unordered_map<std::string, Int128>& variables) const override;
    std::unique_ptr<Expression> clone() const override;
    void print(std::ostream& os) const override;
};

class Add: public Expression {
private:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

public:
    Add(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : left(std::move(left)), right(std::move(right)) {}
    Add(const Expression& left, const Expression& right) : left(left.clone()), right(right.clone()) {}

    Int128 eval(const std::unordered_map<std::string, Int128>& variables) const override;
    std::unique_ptr<Expression> clone() const override;
    void print(std::ostream& os) const override;
};

class Subtract: public Expression {
private:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

public:
    Subtract(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : left(std::move(left)), right(std::move(right)) {}
    Subtract(const Expression& left, const Expression& right) : left(left.clone()), right(right.clone()) {}

    Int128 eval(const std::unordered_map<std::string, Int128>& variables) const override;
    std::unique_ptr<Expression> clone() const override;
    void print(std::ostream& os) const override;
};

class Multiply: public Expression {
private:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

public:
    Multiply(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : left(std::move(left)), right(std::move(right)) {}
    Multiply(const Expression& left, const Expression& right) : left(left.clone()), right(right.clone()) {}

    Int128 eval(const std::unordered_map<std::string, Int128>& variables) const override;
    std::unique_ptr<Expression> clone() const override;
    void print(std::ostream& os) const override;
};

class Divide: public Expression {
private:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

public:
    Divide(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : left(std::move(left)), right(std::move(right)) {}
    Divide(const Expression& left, const Expression& right) : left(left.clone()), right(right.clone()) {}

    Int128 eval(const std::unordered_map<std::string, Int128>& variables) const override;
    std::unique_ptr<Expression> clone() const override;
    void print(std::ostream& os) const override;
};

// Helper function for convenient expression construction
Add operator+(const Expression& left, const Expression& right);
Subtract operator-(const Expression& left, const Expression& right);
Multiply operator*(const Expression& left, const Expression& right);
Divide operator/(const Expression& left, const Expression& right);

// Operator for streaming expression to output
std::ostream& operator<<(std::ostream& os, const Expression& expr);

#endif  // EXPRESSION_HPP
