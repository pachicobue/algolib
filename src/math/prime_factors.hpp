#pragma once
#include "../common.hpp"
#include "../utility/rng.hpp"
#include "is_prime.hpp"
template<typename mint>
u64 pollardRho(u64 n)
{
    if (n % 2 == 0) { return 2; }
    if (isPrime(n)) { return n; }
    mint c;
    auto f = [&](const mint& x) { return x * x + c; };
    while (true) {
        mint x, y, ys, q = 1;
        y = rng64.val<u64>(0, n - 2) + 2;
        c = rng64.val<u64>(0, n - 2) + 2;
        u64 d = 1;
        constexpr u32 dk = 128;
        for (u32 r = 1; d == 1; r <<= 1) {
            x = y;
            for (u32 i = 0; i < r; i++) {
                y = f(y);
            }
            for (u32 k = 0; k < r and d == 1; k += dk) {
                ys = y;
                for (u32 i = 0; i < dk and i < r - k; i++) {
                    q *= x - (y = f(y));
                }
                d = std::gcd((u64)q.val(), n);
            }
        }
        if (d == n) {
            do {
                d = std::gcd(u64((x - (ys = f(ys))).val()), n);
            } while (d == 1);
        }
        if (d != n) { return d; }
    }
    return n;
}
Map<u64, int> primeFactors(u64 n)
{
    using mint = modint_dynamic<287687412>;
    using mint64 = modint64_dynamic<4832432>;
    Map<u64, int> ans;
    Fix([&](auto dfs, u64 x) -> void {
        while ((x & 1) == 0) {
            x >>= 1, ans[2]++;
        }
        if (x == 1) { return; }
        u64 p;
        if (x < (1ULL << 30)) {
            mint::setMod(x);
            p = pollardRho<mint>(x);
        } else {
            mint64::setMod(x);
            p = pollardRho<mint64>(x);
        }
        if (p == x) {
            ans[p]++;
            return;
        }
        dfs(p), dfs(x / p);
    })(n);
    return ans;
}
Vec<u64> divisors(const u64 n)
{
    const auto fs = primeFactors(n);
    Vec<u64> ds{1};
    for (const auto& [p, e] : fs) {
        u64 pe = p;
        const u32 dn = ds.size();
        for (i32 i = 0; i < e; i++, pe *= p) {
            for (u32 j = 0; j < dn; j++) {
                ds.push_back(ds[j] * pe);
            }
        }
    }
    return ds;
}
