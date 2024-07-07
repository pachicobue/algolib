#pragma once
#include <cassert>
#include <numeric>
#include "../internal.hpp"
#include "../utility/int_nthroot.hpp"
#include "../utility/modint.hpp"
#include "../utility/rng.hpp"
#include "miller_rabin.hpp"
/**
 * @brief Pollard's rho algorithm
 * @see https://qiita.com/t_fuki/items/7cd50de54d3c5d063b4a
 *
 * @param X (1以上)
 * @return u64 Xの非自明な約数 (Xが素数の場合はXを返す)
 */
inline auto pollardRho(u64 X) -> u64 {
    assert(1 <= X and X <= (u64)LIMMAX<i64>);
    if (X % 2 == 0) { return 2; }
    if (X == 1 or isPrime(X)) { return X; }
    using mint = modint_dynamic_reserved<77726>;
    mint::setMod(X);
    auto f = [&](mint x, mint c) { return x * x + c; };
    const u64 gcdBlock = intNthRoot(X, 8);
    while (true) {
        const u64 a = rng64.val<u64>(0, X - 1);
        const mint c = rng64.val(2_u64, X - 1);
        mint x = a, y = a, sx = x, sy = y;
        mint p = 1;
        u64 g = 1;
        while (g == 1) {
            sx = x, sy = y;
            LOOP (gcdBlock) { x = f(x, c), y = f(f(y, c), c), p *= (x - y); }
            g = std::gcd(X, p.val());
        }
        if (g == X) {
            x = sx, y = sy, g = 1;
            while (g == 1) { x = f(x, c), y = f(f(y, c), c), g = std::gcd(X, (x - y).val()); }
        }
        if (g != X) { return g; }
    }
    return X;
}
/**
 * @brief 高速素因数分解
 *
 * @param X 素因数分解する値
 * @return Vec<Pair<u64,int>> 素因数分解
 */
inline auto primeFactors(u64 X) -> Vec<Pair<u64, int>> {
    Vec<u64> Ans;
    Fix([&](auto dfs, u64 x) -> void {
        while (x % 2 == 0) { x /= 2, Ans.push_back(2); }
        if (x == 1) { return; }
        const u64 d = pollardRho(x);
        if (d == x) { return Ans.push_back(d), void(); }
        dfs(d), dfs(x / d);
    })(X);
    return seqSort(Ans), seqRleVec(Ans);
}
/**
 * @brief 約数列挙
 *
 * @param factors 素因数分解
 * @return Vec<u64> 約数列 (ソート済み)
 */
inline auto divisors(const Vec<Pair<u64, int>>& factors) -> Vec<u64> {
    Vec<u64> Ans{1};
    for (const auto& [p, e] : factors) {
        const int dn = (int)Ans.size();
        u64 pe = p;
        LOOP (e) {
            for (int j : rep(dn)) { Ans.push_back(Ans[j] * pe); }
            pe *= p;
        }
    }
    return seqSort(Ans), Ans;
}
