#pragma once
#include "../common.hpp"
/**
 * @brief 有理数型
 * @note ∞,-∞ も含む
 * @attention オーバーフロー対策はしていないので注意
 *
 * @tparam T 整数型
 */
template<typename T> class Rational
{
public:
    /**
     * @brief コンストラクタ (0初期化)
     */
    constexpr Rational() : m_num{0}, m_den{1} {}
    /**
     * @brief コンストラクタ (分子指定)
     * 
     * @param v 整数
     */
    constexpr Rational(const T& v) : m_num{v}, m_den{1} {}
    /**
     * @brief コンストラクタ (分子,分母 指定)
     * 
     * @param num 分子
     * @param den 分母
     */
    constexpr Rational(const T& num, const T& den) { std::tie(m_num, m_den) = norm(num, den); }
    /**
     * @brief -x
     * 
     * @return Rational -x
     */
    constexpr friend Rational operator-(const Rational& x) { return {-x.m_num, x.m_den}; }
    /**
     * @brief x1 <- x1+x2
     * 
     * @param x1
     * @param x2 
     * @return Rational& x1
     */
    constexpr friend Rational& operator+=(Rational& x1, const Rational& x2)
    {
        return x1 = {x1.m_num * x2.m_den + x2.m_num * x1.m_den, x1.m_den * x2.m_den}, x1;
    }
    /**
     * @brief x1 <- x1-x2
     * 
     * @param x1 
     * @param x2 
     * @return Rational& x1
     */
    constexpr friend Rational& operator-=(Rational& x1, const Rational& x2)
    {
        return x1 = {x1.m_num * x2.m_den - x2.m_num * x1.m_den, x1.m_den * x2.m_den}, x1;
    }
    /**
     * @brief x1 <- x1*x2
     * 
     * @param x1 
     * @param x2 
     * @return Rational& x1
     */
    constexpr friend Rational& operator*=(Rational& x1, const Rational& x2)
    {
        const T g12 = std::gcd(x1.m_num, x2.m_den), g21 = std::gcd(x2.m_num, x1.m_den);
        return x1 = {(x1.m_num / g12) * (x2.m_num / g21), (x1.m_den / g21) * (x2.m_den / g12)}, x1;
    }
    /**
     * @brief x1 <- x1/x2
     * 
     * @param x1 
     * @param x2 
     * @return Rational& x1
     */
    constexpr friend Rational& operator/=(Rational& x1, const Rational& x2)
    {
        const T g12 = std::gcd(x1.m_num, x2.m_num), g21 = std::gcd(x2.m_den, x1.m_den);
        return x1 = {(x1.m_num / g12) * (x2.m_den / g21), (x1.m_den / g21) * (x2.m_num / g12)}, x1;
    }
    /**
     * @brief x1+x2
     * 
     * @param x1 
     * @param x2 
     * @return Rational x1+x2
     */
    constexpr friend Rational operator+(const Rational& x1, const Rational& x2)
    {
        auto ans = x1;
        return ans += x2;
    }
    /**
     * @brief x1-x2
     * 
     * @param x1 
     * @param x2 
     * @return Rational x1-x2
     */
    constexpr friend Rational operator-(const Rational& x1, const Rational& x2)
    {
        auto ans = x1;
        return ans -= x2;
    }
    /**
     * @brief x1*x2
     * 
     * @param x1 
     * @param x2 
     * @return Rational x1*x2
     */
    constexpr friend Rational operator*(const Rational& x1, const Rational& x2)
    {
        auto ans = x1;
        return ans *= x2;
    }
    /**
     * @brief x1/x2
     * 
     * @param x1 
     * @param x2 
     * @return Rational x1/x2
     */
    constexpr friend Rational operator/(const Rational& x1, const Rational& x2)
    {
        auto ans = x1;
        return ans /= x2;
    }
    /**
     * @brief x1==x2
     * 
     * @param x1 
     * @param x2 
     * @return true 一致
     * @return false 不一致
     */
    constexpr friend bool operator==(const Rational& x1, const Rational& x2) { return x1.m_num == x2.m_num and x1.m_den == x2.m_den; }
    /**
     * @brief x1<=>x2
     * 
     * @param x1
     * @param x2
     * @return 一貫比較結果
     */
    constexpr friend auto operator<=>(const Rational& x1, const Rational& x2)
    {
        if (x1 == x2) { return std::strong_ordering::equal; }
        if (x1.m_den == 0) { return x1.m_num <=> 0; }
        if (x2.m_den == 0) { return 0 <=> x2.m_num; }
        return x1.m_num * x2.m_den <=> x2.m_num * x1.m_den;
    }
    /**
     * @brief 分子,分母 のペア
     * 
     * @return Pair<T, T> {分子,分母}
     */
    constexpr Pair<T, T> val() const { return {m_num, m_den}; }
    /**
     * @brief 分子
     * 
     * @return T 分子
     */
    constexpr T num() const { return m_num; }
    /**
     * @brief 分母
     * 
     * @return T 分母
     */
    constexpr T den() const { return m_den; }
#ifdef HOGEPACHI
    friend Ostream& operator<<(Ostream& os, const Rational& x)
    {
        const auto& [den, num] = x;
        return os << den << "/" << num;
    }
#endif
private:
    static constexpr Pair<T, T> norm(T num, T den)
    {
        if (den < 0) { num = -num, den = -den; }
        const auto g = std::gcd(num, den);
        return {num / g, den / g};
    }
    T m_num, m_den;
};
