#pragma once
#include "../common.hpp"
template<u64 mod_, u64 root_, u64 max2p_>
class modint64
{
    template<typename U = u64&>
    static U modRef()
    {
        static u64 s_mod = 0;
        return s_mod;
    }
    template<typename U = u64&>
    static U rootRef()
    {
        static u64 s_root = 0;
        return s_root;
    }
    template<typename U = u64&>
    static U max2pRef()
    {
        static u64 s_max2p = 0;
        return s_max2p;
    }

public:
    static constexpr bool isDynamic()
    {
        return (mod_ == 0);
    }
    template<typename U = const u64>
    static constexpr std::enable_if_t<mod_ != 0, U> mod()
    {
        return mod_;
    }
    template<typename U = const u64>
    static std::enable_if_t<mod_ == 0, U> mod()
    {
        return modRef();
    }
    template<typename U = const u64>
    static constexpr std::enable_if_t<mod_ != 0, U> root()
    {
        return root_;
    }
    template<typename U = const u64>
    static std::enable_if_t<mod_ == 0, U> root()
    {
        return rootRef();
    }
    template<typename U = const u64>
    static constexpr std::enable_if_t<mod_ != 0, U> max2p()
    {
        return max2p_;
    }
    template<typename U = const u64>
    static std::enable_if_t<mod_ == 0, U> max2p()
    {
        return max2pRef();
    }
    template<typename U = u64>
    static void setMod(std::enable_if_t<mod_ == 0, U> m)
    {
        modRef() = m;
    }
    template<typename U = u64>
    static void setRoot(std::enable_if_t<mod_ == 0, U> r)
    {
        rootRef() = r;
    }
    template<typename U = u64>
    static void setMax2p(std::enable_if_t<mod_ == 0, U> m)
    {
        max2pRef() = m;
    }
    constexpr modint64() : m_val{0} {}
    constexpr modint64(const i64 v) : m_val{normLL(v)} {}
    constexpr void setRaw(const u64 v)
    {
        m_val = v;
    }
    constexpr modint64 operator+() const
    {
        return *this;
    }
    constexpr modint64 operator-() const
    {
        return modint64{0} - (*this);
    }
    constexpr modint64& operator+=(const modint64& m)
    {
        m_val = norm(m_val + m.val());
        return *this;
    }
    constexpr modint64& operator-=(const modint64& m)
    {
        m_val = norm(m_val + mod() - m.val());
        return *this;
    }
    constexpr modint64& operator*=(const modint64& m)
    {
        m_val = normLL((i128)m_val * (i128)m.val() % (i128)mod());
        return *this;
    }
    constexpr modint64& operator/=(const modint64& m)
    {
        return *this *= m.inv();
    }
    constexpr modint64 operator+(const modint64& m) const
    {
        auto v = *this;
        return v += m;
    }
    constexpr modint64 operator-(const modint64& m) const
    {
        auto v = *this;
        return v -= m;
    }
    constexpr modint64 operator*(const modint64& m) const
    {
        auto v = *this;
        return v *= m;
    }
    constexpr modint64 operator/(const modint64& m) const
    {
        auto v = *this;
        return v /= m;
    }
    constexpr bool operator==(const modint64& m) const
    {
        return m_val == m.val();
    }
    constexpr bool operator!=(const modint64& m) const
    {
        return not(*this == m);
    }
    friend Istream& operator>>(Istream& is, modint64& m)
    {
        i64 v;
        return is >> v, m = v, is;
    }
    friend Ostream& operator<<(Ostream& os, const modint64& m)
    {
        return os << m.val();
    }
    constexpr u64 val() const
    {
        return m_val;
    }
    template<typename I>
    constexpr modint64 pow(I n) const
    {
        return powerInt(*this, n);
    }
    constexpr modint64 inv() const
    {
        return pow(mod() - 2);
    }
    modint64 sinv() const
    {
        return sinv(m_val);
    }
    static modint64 fact(u32 n)
    {
        static Vec<modint64> fs{1, 1};
        for (u32 i = (u32)fs.size(); i <= n; i++) {
            fs.push_back(fs.back() * i);
        }
        return fs[n];
    }
    static modint64 ifact(u32 n)
    {
        static Vec<modint64> ifs{1, 1};
        for (u32 i = (u32)ifs.size(); i <= n; i++) {
            ifs.push_back(ifs.back() * sinv(i));
        }
        return ifs[n];
    }
    static modint64 perm(int n, int k)
    {
        return k > n or k < 0 ? modint64{0} : fact(n) * ifact(n - k);
    }
    static modint64 comb(int n, int k)
    {
        return k > n or k < 0 ? modint64{0} : fact(n) * ifact(n - k) * ifact(k);
    }

private:
    static constexpr u64 norm(const u64 x)
    {
        return x < mod() ? x : x - mod();
    }
    static constexpr u64 normLL(const i64 x)
    {
        return norm(u64((i128)x % (i128)mod() + (i128)mod()));
    }
    static modint64 sinv(u32 n)
    {
        static Vec<modint64> is{1, 1};
        for (u32 i = (u32)is.size(); i <= n; i++) {
            is.push_back(-is[mod() % i] * (mod() / i));
        }
        return is[n];
    }
    u64 m_val;
};
template<int id>
using modint64_dynamic = modint64<0, 0, id>;
