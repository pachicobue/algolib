#pragma once
#include <iostream>

#include "../misc/common.hpp"
struct modinfo
{
    void set_mod(const u32 nmod) { mod = nmod; }
    u32 mod, root, max2p;
};
template<const modinfo& info>
class modint
{
public:
    static constexpr const u32& mod   = info.mod;
    static constexpr const u32& root  = info.root;
    static constexpr const u32& max2p = info.max2p;

    constexpr modint() : m_val{0} {}
    constexpr modint(const i64 v) : m_val{normll(v)} {}
    constexpr void set_raw(const u32 v) { m_val = v; }
    constexpr modint operator-() const { return modint{0} - (*this); }
    constexpr modint& operator+=(const modint& m) { return m_val = norm(m_val + m()), *this; }
    constexpr modint& operator-=(const modint& m) { return m_val = norm(m_val + mod - m()), *this; }
    constexpr modint& operator*=(const modint& m) { return m_val = normll((i64)m_val * (i64)m() % (i64)mod), *this; }
    constexpr modint& operator/=(const modint& m) { return *this *= m.inv(); }
    constexpr modint operator+(const modint& m) const { return modint{*this} += m; }
    constexpr modint operator-(const modint& m) const { return modint{*this} -= m; }
    constexpr modint operator*(const modint& m) const { return modint{*this} *= m; }
    constexpr modint operator/(const modint& m) const { return modint{*this} /= m; }
    constexpr bool operator==(const modint& m) const { return m_val == m(); }
    constexpr bool operator!=(const modint& m) const { return not(*this == m); }
    friend std::istream& operator>>(std::istream& is, modint& m)
    {
        i64 v;
        return is >> v, m = v, is;
    }
    friend std::ostream& operator<<(std::ostream& os, const modint& m) { return os << m(); }
    constexpr u32 get() const { return m_val; }
    constexpr u32 operator()() const { return m_val; }
    template<typename Int>
    constexpr modint pow(Int n) const { return power(*this, n); }
    constexpr modint inv() const { return pow(mod - 2); }
    static modint sinv(const u32 n)
    {
        static std::vector<modint> is{1, 1};
        for (u32 i = (u32)is.size(); i <= n; i++) { is.push_back(-is[mod % i] * (mod / i)); }
        return is[n];
    }
    static modint fact(const u32 n)
    {
        static std::vector<modint> fs{1, 1};
        for (u32 i = (u32)fs.size(); i <= n; i++) { fs.push_back(fs.back() * i); }
        return fs[n];
    }
    static modint ifact(const u32 n)
    {
        static std::vector<modint> ifs{1, 1};
        for (u32 i = (u32)ifs.size(); i <= n; i++) { ifs.push_back(ifs.back() * sinv(i)); }
        return ifs[n];
    }
    static modint comb(const int n, const int k) { return k > n or k < 0 ? modint{0} : fact(n) * ifact(n - k) * ifact(k); }

private:
    static constexpr u32 norm(const u32 x) { return x < mod ? x : x - mod; }
    static constexpr u32 normll(const i64 x) { return norm(u32(x % (i64)mod + (i64)mod)); }
    u32 m_val;
};
constexpr modinfo modinfo_1000000007 = {1000000007, 5, 1};
constexpr modinfo modinfo_998244353  = {998244353, 3, 23};
using modint_1000000007              = modint<modinfo_1000000007>;
using modint_998244353               = modint<modinfo_998244353>;
