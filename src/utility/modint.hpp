#pragma once
#include "../common.hpp"
#include "../algorithm/ext_gcd.hpp"
template<u32 mod_, u32 root_, u32 max2p_>
class modint
{
    template<typename U = u32&>
    static U modRef()
    {
        static u32 s_mod = 0;
        return s_mod;
    }
    template<typename U = u32&>
    static U rootRef()
    {
        static u32 s_root = 0;
        return s_root;
    }
    template<typename U = u32&>
    static U max2pRef()
    {
        static u32 s_max2p = 0;
        return s_max2p;
    }

public:
    static_assert(mod_ <= LIMMAX<i32>, "mod(signed int size) only supported!");
    static constexpr bool isDynamic() { return (mod_ == 0); }
    template<typename U = const u32>
    static constexpr std::enable_if_t<mod_ != 0, U> mod()
    {
        return mod_;
    }
    template<typename U = const u32>
    static std::enable_if_t<mod_ == 0, U> mod()
    {
        return modRef();
    }
    template<typename U = const u32>
    static constexpr std::enable_if_t<mod_ != 0, U> root()
    {
        return root_;
    }
    template<typename U = const u32>
    static std::enable_if_t<mod_ == 0, U> root()
    {
        return rootRef();
    }
    template<typename U = const u32>
    static constexpr std::enable_if_t<mod_ != 0, U> max2p()
    {
        return max2p_;
    }
    template<typename U = const u32>
    static std::enable_if_t<mod_ == 0, U> max2p()
    {
        return max2pRef();
    }
    template<typename U = u32>
    static void setMod(std::enable_if_t<mod_ == 0, U> m)
    {
        assert(1 <= m and m <= LIMMAX<i32>);
        modRef() = m;
        sinvRef() = {1, 1};
        factRef() = {1, 1};
        ifactRef() = {1, 1};
    }
    template<typename U = u32>
    static void setRoot(std::enable_if_t<mod_ == 0, U> r)
    {
        rootRef() = r;
    }
    template<typename U = u32>
    static void setMax2p(std::enable_if_t<mod_ == 0, U> m)
    {
        max2pRef() = m;
    }
    constexpr modint() : m_val{0} {}
    constexpr modint(i64 v) : m_val{normll(v)} {}
    constexpr void setRaw(u32 v) { m_val = v; }
    constexpr modint operator-() const { return modint{0} - (*this); }
    constexpr modint& operator+=(const modint& m)
    {
        m_val = norm(m_val + m.val());
        return *this;
    }
    constexpr modint& operator-=(const modint& m)
    {
        m_val = norm(m_val + mod() - m.val());
        return *this;
    }
    constexpr modint& operator*=(const modint& m)
    {
        m_val = normll((i64)m_val * (i64)m.val() % (i64)mod());
        return *this;
    }
    constexpr modint& operator/=(const modint& m) { return *this *= m.inv(); }
    constexpr modint operator+(const modint& m) const
    {
        auto v = *this;
        return v += m;
    }
    constexpr modint operator-(const modint& m) const
    {
        auto v = *this;
        return v -= m;
    }
    constexpr modint operator*(const modint& m) const
    {
        auto v = *this;
        return v *= m;
    }
    constexpr modint operator/(const modint& m) const
    {
        auto v = *this;
        return v /= m;
    }
    constexpr bool operator==(const modint& m) const { return m_val == m.val(); }
    constexpr bool operator!=(const modint& m) const { return not(*this == m); }
    friend Istream& operator>>(Istream& is, modint& m)
    {
        i64 v;
        return is >> v, m = v, is;
    }
    friend Ostream& operator<<(Ostream& os, const modint& m) { return os << m.val(); }
    constexpr u32 val() const { return m_val; }
    template<typename I>
    constexpr modint pow(I n) const
    {
        return powerInt(*this, n);
    }
    constexpr modint inv() const { return inverse<i32>(m_val, mod()); }
    static modint sinv(u32 n)
    {
        auto& is = sinvRef();
        for (u32 i = (u32)is.size(); i <= n; i++) { is.push_back(-is[mod() % i] * (mod() / i)); }
        return is[n];
    }
    static modint fact(u32 n)
    {
        auto& fs = factRef();
        for (u32 i = (u32)fs.size(); i <= n; i++) { fs.push_back(fs.back() * i); }
        return fs[n];
    }
    static modint ifact(u32 n)
    {
        auto& ifs = ifactRef();
        for (u32 i = (u32)ifs.size(); i <= n; i++) { ifs.push_back(ifs.back() * sinv(i)); }
        return ifs[n];
    }
    static modint perm(int n, int k) { return k > n or k < 0 ? modint{0} : fact(n) * ifact(n - k); }
    static modint comb(int n, int k)
    {
        return k > n or k < 0 ? modint{0} : fact(n) * ifact(n - k) * ifact(k);
    }

private:
    static Vec<modint>& sinvRef()
    {
        static Vec<modint> is{1, 1};
        return is;
    }
    static Vec<modint>& factRef()
    {
        static Vec<modint> fs{1, 1};
        return fs;
    }
    static Vec<modint>& ifactRef()
    {
        static Vec<modint> ifs{1, 1};
        return ifs;
    }
    static constexpr u32 norm(u32 x) { return x < mod() ? x : x - mod(); }
    static constexpr u32 normll(i64 x) { return norm(u32(x % (i64)mod() + (i64)mod())); }
    u32 m_val;
};
using modint_1000000007 = modint<1000000007, 5, 1>;
using modint_998244353 = modint<998244353, 3, 23>;
template<int id>
using modint_dynamic = modint<0, 0, id>;
