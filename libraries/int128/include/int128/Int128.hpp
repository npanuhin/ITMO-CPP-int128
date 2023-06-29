#ifndef INT128_SOLVER_HPP
#define INT128_SOLVER_HPP

#include <cstdint>
#include <iostream>

class Int128 {
    int64_t high;
    uint64_t low;

public:
    // Конструирование без аргументов
    Int128();

    // Конструирование от int64_t
    explicit Int128(int64_t num);

    // Конструирование от std::string_view
    explicit Int128(std::string_view str);

    // Явное приведение к int64_t
    operator int64_t() const;

    // Явное приведение к double
    operator double() const;

    // Перевод в строку: std::string str()
    std::string str() const;

    // Сложение: +, +=
    Int128 operator+(const Int128& rhs) const;
    Int128& operator+=(const Int128& rhs);

    // Вычитание: -, -=
    Int128 operator-(const Int128& rhs) const;
    Int128& operator-=(const Int128& rhs);

    // Умножение: *, *=
    Int128 operator*(const Int128& rhs) const;
    Int128& operator*=(const Int128& rhs);

    // Деление: /, /=

    // Унарный минус: -
    Int128 operator-() const;

    // Сравнение на равенство: ==, !=
    bool operator==(const Int128& rhs) const;
    bool operator!=(const Int128& rhs) const;

    // Вывод в поток: <<
    friend std::ostream& operator<<(std::ostream& out, const Int128& board);

    // ============================== Custom ==============================

private:
    // Конструирование от int64_t(high) и uint64_t(low)
    explicit Int128(int64_t high, uint64_t low);

public:
    // Строка из бит (с разделителем)
    std::string bit_string(bool separator = false) const;

    // Побитовое NOT (~)
    Int128 operator~() const;

    // Константы 0 и 1
    static const Int128 ZERO;
    static const Int128 ONE;

    // Битовый сдвиг влево
    Int128 operator<<(int shift) const;
    Int128& operator<<=(int shift);

    // Битовый сдвиг вправо
    Int128 operator>>(int shift) const;
    Int128& operator>>=(int shift);

    // Деление: /, /=
    Int128 operator/(const Int128& rhs) const;
    Int128& operator/=(const Int128& rhs);

    // Остаток от деления: %, %=
    Int128 operator%(const Int128& rhs) const;
    Int128& operator%=(const Int128& rhs);

    // Сравнение: <, <=
    bool operator<(const Int128& rhs) const;
    bool operator<=(const Int128& rhs) const;

    // Сравнение: >, >=
    bool operator>(const Int128& rhs) const;
    bool operator>=(const Int128& rhs) const;
};

#endif  // INT128_SOLVER_HPP
