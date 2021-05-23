#pragma once
#include "../misc/common.hpp"
template<typename T>
struct rational
{
    rational() : num{0}, den{1} {}
    rational(T n) : num{n}, den{1} {}
    rational(T n, T d) : num{n}, den{d}
    {
        if (den < 0) { num = -num, den = -den; }
        const T g = std::gcd(den, num);
        num /= g, den /= g;
    }
    rational operator-() const
    {
        rational ans = *this;
        ans.num = -ans.num;
        return ans;
    }
    rational operator+(const rational& r) const
    {
        if (den == 0) { return (*this); }
        if (r.den == 0) { return r; }
        const auto [n1, d1] = *this;
        const auto [n2, d2] = r;
        const T d = std::lcm(d1, d2);
        const T n = n1 * (d / d1) + n2 * (d / d2);
        return {n, d};
    }
    rational operator-(const rational& r) const
    {
        return (*this) + -r;
    }
    rational operator*(const rational& r) const
    {
        if (num == 0 or r.num == 0) { return 0; }
        if (den == 0 or r.den == 0) { return {(num > 0) * (r.num > 0), 0}; }
        const auto [n1, d1] = *this;
        const auto [n2, d2] = r;
        const T d = std::lcm(d1, d2);
        const T n = n1 * (d / d1) + n2 * (d / d2);
        return {n, d};
    }
    T num, den;
};
