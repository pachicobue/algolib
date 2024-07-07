#pragma once
#include <cassert>
#include "../algorithm/ext_gcd.hpp"
#include "../internal.hpp"
/**
 * @brief Modint
 * @note x.val()がi64に収まることは保証される
 *
 * @tparam Mod 剰余 (2^63 -1 以下)
 * @tparam dynamic 動的にmodを変えたい場合 True を指定
 */
template <u64 Mod, bool dynamic = false>
requires(dynamic or (0 < Mod and Mod <= (u64)LIMMAX<i64>))
class modint {
public:
    /**
     * @brief 動的modintかどうか
     *
     * @return true 動的
     * @return false 静的
     */
    static constexpr auto isDynamic() -> bool { return dynamic; }
    /**
     * @brief Mod
     *
     * @return 剰余
     */
    static constexpr auto mod() -> u64 {
        if constexpr (dynamic) {
            return modRef();
        } else {
            return Mod;
        }
    }
    /**
     * @brief Mod更新 (動的Modintのみ)
     *
     * @param m 剰余
     */
    static constexpr auto setMod(u64 m) -> void
        requires dynamic
    {
        assert(0 < m and m <= LIMMAX<i64>);
        modRef() = m, sinvRef() = factRef() = ifactRef() = {1, 1};
    }
    /**
     * @brief コンストラクタ (0初期化)
     */
    constexpr modint() : m_val{0} {}
    /**
     * @brief コンストラクタ (値指定)
     *
     * @param v 値
     */
    constexpr modint(i64 v) : m_val{normll(v)} {}
    /**
     * @brief -m
     *
     * @param m
     * @return modint -m
     */
    constexpr friend auto operator-(const modint& x) -> modint { return modint{0} - x; }
    /**
     * @brief x1 <- x1+x2
     *
     * @param x1
     * @param x2
     * @return modint& x1
     */
    constexpr friend auto operator+=(modint& x1, const modint& x2) -> modint& { return x1.m_val = norm(x1.m_val + x2.m_val), x1; }
    /**
     * @brief x1 <- x1-x2
     *
     * @param x1
     * @param x2
     * @return modint& x1
     */
    constexpr friend auto operator-=(modint& x1, const modint& x2) -> modint& { return x1.m_val = norm(x1.m_val + mod() - x2.m_val), x1; }
    /**
     * @brief x1 <- x1*x2
     *
     * @param x1
     * @param x2
     * @return modint& x1
     */
    constexpr friend auto operator*=(modint& x1, const modint& x2) -> modint& {
        if constexpr (dynamic) {
            if (mod() <= (u64)LIMMAX<u32>) {
                return (x1.m_val *= x2.m_val) %= mod(), x1;
            } else {
                return x1.m_val = (u64)((u128)x1.m_val * (u128)x2.m_val % (u128)mod()), x1;
            }
        } else {
            if constexpr (Mod <= (u64)LIMMAX<u32>) {
                return (x1.m_val *= x2.m_val) %= mod(), x1;
            } else {
                return x1.m_val = (u64)((u128)x1.m_val * (u128)x2.m_val % (u128)mod()), x1;
            }
        }
    }
    /**
     * @brief x1 <- x1/x2
     *
     * @param x1
     * @param x2
     * @return modint& x1
     */
    constexpr friend auto operator/=(modint& x1, const modint& x2) -> modint& { return x1 *= x2.inv(); }
    /**
     * @brief x1+x2
     *
     * @param x1
     * @param x2
     * @return modint x1+x2
     */
    constexpr friend auto operator+(const modint& x1, const modint& x2) -> modint {
        auto ans = x1;
        return ans += x2;
    }
    /**
     * @brief x1-x2
     *
     * @param x1
     * @param x2
     * @return modint x1-x2
     */
    constexpr friend auto operator-(const modint& x1, const modint& x2) -> modint {
        auto ans = x1;
        return ans -= x2;
    }
    /**
     * @brief x1*x2
     *
     * @param x1
     * @param x2
     * @return modint x1*x2
     */
    constexpr friend auto operator*(const modint& x1, const modint& x2) -> modint {
        auto ans = x1;
        return ans *= x2;
    }
    /**
     * @brief x1/x2
     *
     * @param x1
     * @param x2
     * @return modint x1/x2
     */
    constexpr friend auto operator/(const modint& x1, const modint& x2) -> modint {
        auto ans = x1;
        return ans /= x2;
    }
    /**
     * @brief x1 <=> x2
     * @attention 不等号は本来定義出来ないが、Map,Setに使いたいので定義
     */
    constexpr friend auto operator<=>(const modint& x1, const modint& x2) = default;
    /**
     * @brief modintの入力
     *
     * @param is 入力stream
     * @param m
     * @return Istream& istream
     */
    friend auto operator>>(Istream& is, modint& x) -> Istream& {
        i64 v;
        return is >> v, x = v, is;
    }
    /**
     * @brief modintの出力
     *
     * @param os 出力stream
     * @param m
     * @return Ostream& ostream
     */
    friend auto operator<<(Ostream& os, const modint& x) -> Ostream& { return os << x.m_val; }
    /**
     * @brief modintの内部値
     *
     * @return u64 値
     */
    constexpr auto val() const -> u64 { return m_val; }
    /**
     * @brief 累乗
     *
     * @param n 指数
     * @return modint 累乗
     */
    constexpr auto pow(i64 n) const -> modint { return powerInt(*this, n); }
    /**
     * @brief 逆数
     * @attention 正確には xy=gcd(x,mod) となる y を返す
     *
     * @return modint 逆数
     */
    constexpr auto inv() const -> modint { return inverseMod(m_val, mod()); }
    /**
     * @brief 正整数nの逆数
     * @attention 均し線形かかるので注意
     *
     * @param n
     * @return modint 1/n
     */
    static auto sinv(int n) -> modint {
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
     * @return modint n!
     */
    static auto fact(int n) -> modint {
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
     * @return modint 1/n!
     */
    static auto ifact(int n) -> modint {
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
     * @return modint P(n,k)
     */
    static auto perm(int n, int k) -> modint { return k > n or k < 0 ? modint{0} : fact(n) * ifact(n - k); }
    /**
     * @brief C(n,K)
     * @attention 均し線形かかるので注意
     *
     * @param n
     * @param k
     * @return modint C(n,k)
     */
    static auto comb(int n, int k) -> modint { return k > n or k < 0 ? modint{0} : fact(n) * ifact(n - k) * ifact(k); }
private:
    static auto modRef() -> u64& requires dynamic
    {
        static u64 mod_ = 0;
        return mod_;
    }
    static auto sinvRef() -> Vec<modint>& {
        static Vec<modint> is{1, 1};
        return is;
    }
    static auto factRef() -> Vec<modint>& {
        static Vec<modint> fs{1, 1};
        return fs;
    }
    static auto ifactRef() -> Vec<modint>& {
        static Vec<modint> ifs{1, 1};
        return ifs;
    }
    static constexpr auto norm(u64 x) -> u64 { return x < mod() ? x : x - mod(); } // 0 <= x < mod*2
    static constexpr auto normll(i64 x) -> u64 {
        x %= (i64)mod();
        return norm(u64(x < 0 ? x + (i64)mod() : x));
    }
    u64 m_val;
};
using modint_1000000007 = modint<1000000007, false>;
using modint_998244353 = modint<998244353, false>;
template <u64 id>
requires(id < (u64)LIMMAX<i64>)
using modint_dynamic = modint<id, true>;
template <u64 id>
requires(id < (u64)LIMMAX<i64>)
using modint_dynamic_reserved = modint<id | (1_u64 << 63), true>; // ライブラリ内で使用する ID
