#pragma once
#include "../common.hpp"
template<typename T>
class Rational
{
public:
    constexpr Rational() : m_num{0}, m_den{1} {}
    constexpr Rational(const T& v) : m_num{v}, m_den{1} {}
    constexpr Rational(const T& num, const T& den) { std::tie(m_num, m_den) = norm(num, den); }
    constexpr Rational operator-() const
    {
        auto ans = *this;
        ans.m_num = -ans.m_num;
        return ans;
    }
    constexpr Rational& operator+=(const Rational& x2)
    {
        const auto& [n, d] = norm(m_num * x2.m_den + x2.m_num * m_den, m_den * x2.m_den);
        return setRaw(n, d), *this;
    }
    constexpr Rational& operator-=(const Rational& x2)
    {
        const auto& [n, d] = norm(m_num * x2.m_den - x2.m_num * m_den, m_den * x2.m_den);
        return setRaw(n, d), *this;
    }
    constexpr Rational& operator*=(const Rational& x2)
    {
        const T g12 = std::gcd(m_num, x2.m_den), g21 = std::gcd(x2.m_num, m_den);
        return setRaw((m_num / g12) * (x2.m_num / g21), (m_den / g21) * (x2.m_den / g12)), *this;
    }
    constexpr Rational& operator/=(const Rational& x2)
    {
        const T g12 = std::gcd(m_num, x2.m_num), g21 = std::gcd(x2.m_den, m_den);
        return setRaw((m_num / g12) * (x2.m_den / g21), (m_den / g21) * (x2.m_num / g12)), *this;
    }
    constexpr Rational operator+(const Rational& x2) const
    {
        auto v = *this;
        return v += x2;
    }
    constexpr Rational operator-(const Rational& x2) const
    {
        auto v = *this;
        return v -= x2;
    }
    constexpr Rational operator*(const Rational& x2) const
    {
        auto v = *this;
        return v *= x2;
    }
    constexpr Rational operator/(const Rational& x2) const
    {
        auto v = *this;
        return v /= x2;
    }
    constexpr bool operator==(const Rational& x2) const
    {
        return m_num == x2.m_num and m_den == x2.m_den;
    }
    constexpr bool operator<(const Rational& x2) const
    {
        if (x2.m_den == 0) { return x2.m_num > 0; }
        if (m_den == 0) { return m_num < 0; }
        return m_num * x2.m_den < x2.m_num * m_den;
    }
    constexpr bool operator>(const Rational& x2) const
    {
        if (x2.m_den == 0) { return x2.m_num < 0; }
        if (m_den == 0) { return m_num > 0; }
        return m_num * x2.m_den > x2.m_num * m_den;
    }
    constexpr bool operator<=(const Rational& x2) const { return not(*this > x2); }
    constexpr bool operator>=(const Rational& x2) const { return not(*this < x2); }
    friend Ostream& operator<<(Ostream& os, const Rational& x)
    {
        const auto& [den, num] = x;
        return os << den << "/" << num;
    }
    constexpr void setRaw(T num, T den) { m_num = num, m_den = den; }
    constexpr Pair<T, T> val() const { return {m_num, m_den}; }
    constexpr T num() const { return m_num; }
    constexpr T den() const { return m_den; }

private:
    static constexpr Pair<T, T> norm(T num, T den)
    {
        if (den < 0) { num = -num, den = -den; }
        const auto g = std::gcd(num, den);
        return {num / g, den / g};
    }
    T m_num, m_den;
};
