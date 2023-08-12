#pragma once
#include "../common.hpp"
#include "../algorithm/ext_gcd.hpp"
#include "../number/primitive_root.hpp"
/**
 * @brief Modint
 * 
 * @tparam Mod 剰余 (2^63 -1 以下)
 * @tparam dynamic 動的にmodを変えたい場合
 */
template<u64 Mod, bool dynamic = false>
    requires(dynamic or (0 < Mod and Mod <= (u64)LIMMAX<i64>))
class modint
{
public:
    /**
     * @brief 動的modintかどうか
     * 
     * @return true 動的
     * @return false 静的
     */
    static constexpr bool isDynamic() { return dynamic; }
    /**
     * @brief Mod (静的Modint)
     * 
     * @return 剰余
     */
    static constexpr u64 mod()
        requires(not dynamic)
    {
        return Mod;
    }
    /**
     * @brief Mod (動的Modint)
     * 
     * @return 剰余
     */
    static constexpr u64 mod()
        requires dynamic
    {
        return modRef();
    }
    /**
     * @brief Mod更新 (動的Modintのみ)
     * 
     * @param m 剰余
     */
    static void setMod(u64 m)
        requires dynamic
    {
        assert(0 < m and m < LIMMAX<u64> / 2);
        modRef() = m;
    }
    /**
     * @brief コンストラクタ
     */
    constexpr modint() : m_val{0} {}
    /**
     * @brief コンストラクタ
     * 
     * @param v 値
     */
    constexpr modint(i64 v) : m_val{normll(v)} {}
    /**
     * @brief -1倍
     * 
     * @param m 
     * @return modint -m
     */
    constexpr friend modint operator-(const modint& m) { return modint{0} - m; }
    /**
     * @brief modint同士の足し算
     * 
     * @param m1 
     * @param m2 
     * @return modint& self
     */
    constexpr friend modint& operator+=(modint& m1, const modint& m2) { return m1.m_val = norm(m1.m_val + m2.m_val), m1; }
    /**
     * @brief modint同士の引き算
     * 
     * @param m1 
     * @param m2 
     * @return modint& self
     */
    constexpr friend modint& operator-=(modint& m1, const modint& m2) { return m1.m_val = norm(m1.m_val + mod() - m2.m_val), m1; }
    /**
     * @brief modint同士の掛け算
     * 
     * @param m1 
     * @param m2 
     * @return modint& self
     */
    constexpr friend modint& operator*=(modint& m1, const modint& m2)
    {
        if constexpr (dynamic) {
            if (mod() <= (u64)LIMMAX<u32>) {
                return (m1.m_val *= m2.m_val) %= mod(), m1;
            } else {
                return m1.m_val = ((u128)m1.m_val * m2.m_val % mod()), m1;
            }
        } else {
            if constexpr (mod() <= (u64)LIMMAX<u32>) {
                return (m1.m_val *= m2.m_val()) %= mod(), m1;
            } else {
                return m1.m_val = ((u128)m1.m_val * m2.m_val % mod()), m1;
            }
        }
    }
    /**
     * @brief modint同士の割り算
     * 
     * @param m1 
     * @param m2 
     * @return modint& self
     */
    constexpr friend modint& operator/=(modint& m1, const modint& m2) { return m1 *= m2.inv(); }
    /**
     * @brief modint同士の和
     * 
     * @param m1 
     * @param m2 
     * @return modint 和
     */
    constexpr friend modint operator+(const modint& m1, const modint& m2)
    {
        auto ans = m1;
        return ans += m2;
    }
    /**
     * @brief modint同士の差
     * 
     * @param m1 
     * @param m2 
     * @return modint 差
     */
    constexpr friend modint operator-(const modint& m1, const modint& m2)
    {
        auto ans = m1;
        return ans -= m2;
    }
    /**
     * @brief modint同士の積
     * 
     * @param m1 
     * @param m2 
     * @return modint 積
     */
    constexpr friend modint operator*(const modint& m1, const modint& m2)
    {
        auto ans = m1;
        return ans *= m2;
    }
    /**
     * @brief modint同士の商
     * 
     * @param m1 
     * @param m2 
     * @return modint 商
     */
    constexpr friend modint operator/(const modint& m1, const modint& m2)
    {
        auto ans = m1;
        return ans /= m2;
    }
    /**
     * @brief modint同士の比較
     * 
     * @param m1 
     * @param m2 
     * @return true 一致
     * @return false 不一致
     */
    constexpr friend bool operator==(const modint& m1, const modint& m2) { return m1.m_val == m2.m_val; }
    /**
     * @brief modintの入力
     * 
     * @param is 入力stream
     * @param m 
     * @return Istream& istream
     */
    friend Istream& operator>>(Istream& is, modint& m)
    {
        i64 v;
        return is >> v, m = v, is;
    }
    /**
     * @brief modintの出力
     * 
     * @param os 出力stream
     * @param m 
     * @return Ostream& ostream
     */
    friend Ostream& operator<<(Ostream& os, const modint& m) { return os << m.m_val; }
    /**
     * @brief modintの内部値
     * 
     * @return u64 値
     */
    constexpr u64 val() const { return m_val; }
    /**
     * @brief modintの累乗
     * 
     * @param n 指数
     * @return modint 累乗
     */
    constexpr modint pow(i64 n) const { return powerInt(*this, n); }
    /**
     * @brief modintの逆数
     * @attention 正確には xy=gcd(x,mod) となる y を返す
     * 
     * @return modint 逆数
     */
    constexpr modint inv() const { return inverseMod(m_val, mod()); }
private:
    static u64& modRef()
        requires dynamic
    {
        static u64 mod_ = 0;
        return mod_;
    }
    static constexpr u64 norm(u64 x) { return x < mod() ? x : x - mod(); }  // 0 <= x < mod*2
    static constexpr u64 normll(i64 x) { return norm(u64(x % (i64)mod() + (i64)mod())); }
    u64 m_val;
};
using modint_1000000007               = modint<1000000007, false>;
using modint_998244353                = modint<998244353, false>;
template<u64 id> using modint_dynamic = modint<id, true>;
