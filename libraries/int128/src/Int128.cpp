#include "int128/Int128.hpp"

#include <bitset>
#include <iostream>

// Конструирование без аргументов
Int128::Int128() : high(0), low(0) {}

// Конструирование от int64_t
Int128::Int128(int64_t num) : high(0) {
    low  = static_cast<uint64_t>(num);
    high = static_cast<uint64_t>(num < 0 ? ~0 : 0);
}

// Конструирование от int64_t(high) и uint64_t(low)
Int128::Int128(int64_t high, uint64_t low) : high(high), low(low) {}

// Конструирование от std::string_view
Int128::Int128(std::string_view str) : high(0), low(0) {
    bool is_negative = false;
    size_t start     = 0;
    if (str[0] == '-') {
        is_negative = true;
        start       = 1;
    }
    for (size_t i = start; i < str.size(); ++i) {
        *this *= Int128(10);
        *this += Int128(str[i] - '0');
    }
    if (is_negative) {
        *this = -*this;
    }
}

// Явное приведение к int64_t
Int128::operator int64_t() const {
    return low;
}

// Явное приведение к double
Int128::operator double() const {
    uint64_t sign_bit =
        (high >> 63) << 63;  // Bit 1 in 64th place if `high` is negative (has bit in 64th place), else 0
    uint64_t low_bits = low & ~(uint64_t(1) << 63);  // `low` without first bit
    return static_cast<double>(sign_bit | low_bits);
}

// Перевод в строку: std::string str()
std::string Int128::str() const {
    if (!low && !high) {
        return "0";
    }

    // bool is_negative = high & (uint64_t(1) << 63);

    // std::string result;
    // uint64_t tmp_low = low;
    // uint64_t tmp_high = high;
    // if (is_negative) {
    //     tmp_low = ~tmp_low;
    //     tmp_high = ~tmp_high;
    //     tmp_low += 1;
    //     if (tmp_low == 0) {
    //         tmp_high += 1;
    //     }
    // }

    // while (tmp_high != 0) {
    //     char digit = tmp_high % 10;
    //     result += digit + '0';
    //     tmp_high /= 10;
    // }
    // while (tmp_low != 0) {
    //     char digit = tmp_low % 10;
    //     result += digit + '0';
    //     tmp_low /= 10;
    // }
    // if (is_negative) {
    //     result += '-';
    // }
    // std::reverse(result.begin(), result.end());
    // return result;
}

// Сложение: +, +=
Int128 Int128::operator+(const Int128 &rhs) const {
    Int128 result;
    result.low  = low + rhs.low;
    result.high = high + rhs.high;
    if (result.low < low) {
        ++result.high;
    }
    return result;
}
Int128 &Int128::operator+=(const Int128 &rhs) {
    *this = *this + rhs;
    return *this;
}

// Вычитание: -, -=
Int128 Int128::operator-(const Int128 &rhs) const {
    return *this + -rhs;
}
Int128 &Int128::operator-=(const Int128 &rhs) {
    *this = *this - rhs;
    return *this;
}

// Умножение: *, *=
Int128 Int128::operator*(const Int128 &_rhs) const {
    Int128 result;
    Int128 lhs = *this;
    Int128 rhs = _rhs;
    while (rhs != ZERO) {
        if (rhs.low & 1) {
            result += lhs;
        }
        lhs += lhs;
        rhs >>= 1;
    }
    return result;
}
Int128 &Int128::operator*=(const Int128 &rhs) {
    *this = *this * rhs;
    return *this;
}

// Деление: /, /=

// Унарный минус: -
Int128 Int128::operator-() const {
    return ~*this + ONE;
}

// Сравнение на равенство: ==, !=
bool Int128::operator==(const Int128 &rhs) const {
    return high == rhs.high && low == rhs.low;
}
bool Int128::operator!=(const Int128 &rhs) const {
    return !(*this == rhs);
}

// Вывод в поток: <<
std::ostream &operator<<(std::ostream &out, const Int128 &num) {
    return out << num.str();
}

// ====================================================== Custom =======================================================

// Строка из бит с разделителем
std::string Int128::bit_string(bool separator) const {
    std::bitset<64> high_bits(high);
    std::bitset<64> low_bits(low);
    std::string result = high_bits.to_string();
    if (separator) {
        result += '|';
    }
    result += low_bits.to_string();
    return result;
}

// Побитовое NOT (~)
Int128 Int128::operator~() const {
    return Int128(~high, ~low);
}

// Константы 0 и 1
const Int128 Int128::ZERO = Int128(0);
const Int128 Int128::ONE  = Int128(1);

// Битовый сдвиг влево
Int128 Int128::operator<<(int shift) const {
    if (shift == 0) {
        return *this;
    }
    Int128 result;
    if (shift >= 64) {
        result.high = low << (shift - 64);
    } else {
        result.high = (high << shift) | (low >> (64 - shift));
        result.low  = low << shift;
    }
    return result;
}
Int128 &Int128::operator<<=(int shift) {
    *this = *this << shift;
    return *this;
}

// Битовый сдвиг вправо
Int128 Int128::operator>>(int shift) const {
    if (shift == 0) {
        return *this;
    }
    Int128 result;
    if (shift >= 64) {
        result.low = static_cast<uint64_t>(high) >> (shift - 64);
    } else {
        result.low  = (low >> shift) | (high << (64 - shift));
        result.high = static_cast<int64_t>(static_cast<uint64_t>(high) >> shift);  // TODO
    }
    return result;
}
Int128 &Int128::operator>>=(int shift) {
    *this = *this >> shift;
    return *this;
}

// Деление: /, /=
Int128 Int128::operator/(const Int128 &_rhs) const {
    // Int128 lhs = *this;
    // Int128 rhs = _rhs;
    // bool is_negative = (lhs.high & (uint64_t(1) << 63)) ^ (rhs.high & (uint64_t(1) << 63));
    // if (lhs.high & (uint64_t(1) << 63)) {
    //     lhs = -lhs;
    // }
    // if (rhs.high & (uint64_t(1) << 63)) {
    //     rhs = -rhs;
    // }
    // Int128 result;
    // for (int i = 127; i >= 0; --i) {
    //     result <<= 1;
    //     if (lhs >= rhs) {
    //         lhs -= rhs;
    //         result += Int128(1);
    //     }
    //     rhs >>= 1;
    // }
    // if (is_negative) {
    //     result = -result;
    // }
    // return result;
    return ONE;
}
Int128 &Int128::operator/=(const Int128 &rhs) {
    *this = *this / rhs;
    return *this;
}

// Остаток от деления: %, %=
Int128 Int128::operator%(const Int128 &rhs) const {
    return *this - (*this / rhs) * rhs;
}
Int128 &Int128::operator%=(const Int128 &rhs) {
    *this = *this % rhs;
    return *this;
}

// Сравнение: <, <=
bool Int128::operator<(const Int128 &rhs) const {
    if (high == rhs.high) {
        return low < rhs.low;
    }
    return high < rhs.high;
}
bool Int128::operator<=(const Int128 &rhs) const {
    return *this < rhs || *this == rhs;
}

// Сравнение: >, >=
bool Int128::operator>(const Int128 &rhs) const {
    return rhs < *this;
}
bool Int128::operator>=(const Int128 &rhs) const {
    return rhs <= *this;
}
