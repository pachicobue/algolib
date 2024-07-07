#pragma once
#include <cassert>
#include "../algorithm/ext_gcd.hpp"
#include "../internal.hpp"
/**
 * @brief x (mod 2^61-1)
 * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
 */
class modint_2p61m1 {
public:
    /**
     * @brief Mod
     *
     * @return 剰余
     */
    static constexpr auto mod() -> u64 { return (1_u64 << 61) - 1; }
    /**
     * @brief コンストラクタ (0初期化)
     */
    constexpr modint_2p61m1() : m_val{0} {}
    /**
     * @brief コンストラクタ (値指定)
     *
     * @param v 値
     */
    constexpr modint_2p61m1(i64 v) : m_val{normll(v)} {}
    /**
     * @brief -m
     *
     * @param m
     * @return modint_2p61m1 -m
     */
    constexpr friend auto operator-(const modint_2p61m1& x) -> modint_2p61m1 { return modint_2p61m1{0} - x; }
    /**
     * @brief x1 <- x1+x2
     *
     * @param x1
     * @param x2
     * @return modint_2p61m1& x1
     */
    constexpr friend auto operator+=(modint_2p61m1& x1, const modint_2p61m1& x2) -> modint_2p61m1& {
        return x1.m_val = norm(x1.m_val + x2.m_val), x1;
    }
    /**
     * @brief x1 <- x1-x2
     *
     * @param x1
     * @param x2
     * @return modint_2p61m1& x1
     */
    constexpr friend auto operator-=(modint_2p61m1& x1, const modint_2p61m1& x2) -> modint_2p61m1& {
        return x1.m_val = norm(x1.m_val + mod() - x2.m_val), x1;
    }
    /**
     * @brief x1 <- x1*x2
     *
     * @param x1
     * @param x2
     * @return modint_2p61m1& x1
     */
    constexpr friend auto operator*=(modint_2p61m1& x1, const modint_2p61m1& x2) -> modint_2p61m1& {
        return x1.m_val = mul(x1.m_val, x2.m_val), x1;
    }
    /**
     * @brief x1 <- x1/x2
     *
     * @param x1
     * @param x2
     * @return modint_2p61m1& x1
     */
    constexpr friend auto operator/=(modint_2p61m1& x1, const modint_2p61m1& x2) -> modint_2p61m1& { return x1 *= x2.inv(); }
    /**
     * @brief x1+x2
     *
     * @param x1
     * @param x2
     * @return modint_2p61m1 x1+x2
     */
    constexpr friend auto operator+(const modint_2p61m1& x1, const modint_2p61m1& x2) -> modint_2p61m1 {
        auto ans = x1;
        return ans += x2;
    }
    /**
     * @brief x1-x2
     *
     * @param x1
     * @param x2
     * @return modint_2p61m1 x1-x2
     */
    constexpr friend auto operator-(const modint_2p61m1& x1, const modint_2p61m1& x2) -> modint_2p61m1 {
        auto ans = x1;
        return ans -= x2;
    }
    /**
     * @brief x1*x2
     *
     * @param x1
     * @param x2
     * @return modint_2p61m1 x1*x2
     */
    constexpr friend auto operator*(const modint_2p61m1& x1, const modint_2p61m1& x2) -> modint_2p61m1 {
        auto ans = x1;
        return ans *= x2;
    }
    /**
     * @brief x1/x2
     *
     * @param x1
     * @param x2
     * @return modint_2p61m1 x1/x2
     */
    constexpr friend auto operator/(const modint_2p61m1& x1, const modint_2p61m1& x2) -> modint_2p61m1 {
        auto ans = x1;
        return ans /= x2;
    }
    /**
     * @brief x1 == x2
     *
     * @param x1
     * @param x2
     * @return true 一致
     * @return false 不一致
     */
    constexpr friend auto operator==(const modint_2p61m1& x1, const modint_2p61m1& x2) -> bool { return x1.m_val == x2.m_val; }
    /**
     * @brief modint_2p61m1の入力
     *
     * @param is 入力stream
     * @param m
     * @return Istream& istream
     */
    friend auto operator>>(Istream& is, modint_2p61m1& x) -> Istream& {
        i64 v;
        return is >> v, x = v, is;
    }
    /**
     * @brief modint_2p61m1の出力
     *
     * @param os 出力stream
     * @param m
     * @return Ostream& ostream
     */
    friend auto operator<<(Ostream& os, const modint_2p61m1& x) -> Ostream& { return os << x.m_val; }
    /**
     * @brief modint_2p61m1の内部値
     *
     * @return u64 値
     */
    constexpr auto val() const -> u64 { return m_val; }
    /**
     * @brief 累乗
     *
     * @param n 指数
     * @return modint_2p61m1 累乗
     */
    constexpr auto pow(i64 n) const -> modint_2p61m1 { return powerInt(*this, n); }
    /**
     * @brief 逆数
     * @attention 正確には xy=gcd(x,mod) となる y を返す
     *
     * @return modint_2p61m1 逆数
     */
    constexpr auto inv() const -> modint_2p61m1 { return inverseMod(m_val, mod()); }
    /**
     * @brief 正整数nの逆数
     * @attention 均し線形かかるので注意
     *
     * @param n
     * @return modint_2p61m1 1/n
     */
    static auto sinv(int n) -> modint_2p61m1 {
        assert(1 <= n);
        auto& is = sinvRef();
        for (int i : irange((int)is.size(), n + 1)) { is.push_back(-is[mod() % i] * (mod() / i)); }
        return is[n];
    }
    /**
     * @brief 非負整数nの階乗
     * @attention 均し線形かかるので注意
     *
     * @param n
     * @return modint_2p61m1 n!
     */
    static auto fact(int n) -> modint_2p61m1 {
        assert(0 <= n);
        auto& fs = factRef();
        for (int i : irange((int)fs.size(), n + 1)) { fs.push_back(fs.back() * i); }
        return fs[n];
    }
    /**
     * @brief 非負整数nの階乗の逆数
     * @attention 均し線形かかるので注意
     *
     * @param n
     * @return modint_2p61m1 1/n!
     */
    static auto ifact(int n) -> modint_2p61m1 {
        auto& ifs = ifactRef();
        for (int i : irange((int)ifs.size(), n + 1)) { ifs.push_back(ifs.back() * sinv(i)); }
        return ifs[n];
    }
    /**
     * @brief P(n,k)
     * @attention 均し線形かかるので注意
     *
     * @param n
     * @param k
     * @return modint_2p61m1 P(n,k)
     */
    static auto perm(int n, int k) -> modint_2p61m1 { return k > n or k < 0 ? modint_2p61m1{0} : fact(n) * ifact(n - k); }
    /**
     * @brief C(n,K)
     * @attention 均し線形かかるので注意
     *
     * @param n
     * @param k
     * @return modint_2p61m1 C(n,k)
     */
    static auto comb(int n, int k) -> modint_2p61m1 { return k > n or k < 0 ? modint_2p61m1{0} : fact(n) * ifact(n - k) * ifact(k); }
private:
    static auto sinvRef() -> Vec<modint_2p61m1>& {
        static Vec<modint_2p61m1> is{1, 1};
        return is;
    }
    static auto factRef() -> Vec<modint_2p61m1>& {
        static Vec<modint_2p61m1> fs{1, 1};
        return fs;
    }
    static auto ifactRef() -> Vec<modint_2p61m1>& {
        static Vec<modint_2p61m1> ifs{1, 1};
        return ifs;
    }
    static constexpr auto mul(u64 x, u64 y) -> u64 {
        const u128 t = (u128)x * y;
        return norm((t >> 61) + (t & mod()));
    }
    static constexpr auto norm(u64 x) -> u64 { return x < mod() ? x : x - mod(); } // 0 <= x < mod*2
    static constexpr auto normull(u64 x) -> u64 { return norm((x >> 61) + (x & mod())); }
    static constexpr auto normll(i64 x) -> u64 { return (x >= 0 ? normull((u64)x) : mod() - normull(u64(-x))); }
    u64 m_val;
};
