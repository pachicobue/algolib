#pragma once
#include "../common.hpp"
#include "../utility/modint.hpp"
#include "../utility/modint64.hpp"
template<typename mint>
bool millerRabin(u64 n, const Vec<u64>& as)
{
    auto d = n - 1;
    for (; (d & 1) == 0; d >>= 1) {}
    for (const u64 a : as) {
        if (n <= a) { break; }
        auto s = d;
        mint x = mint(a).pow(s);
        while (x.val() != 1 and x.val() != n - 1 and s != n - 1) { x *= x, s <<= 1; }
        if (x.val() != n - 1 and s % 2 == 0) { return false; }
    }
    return true;
}
inline bool isPrime(u64 n)
{
    using mint = modint_dynamic<873293817>;
    using mint64 = modint64_dynamic<828271328>;
    if (n == 1) { return false; }
    if ((n & 1) == 0) { return n == 2; }
    if (n < (1ULL << 30)) {
        mint::setMod(n);
        return millerRabin<mint>(n, {2, 7, 61});
    } else {
        mint64::setMod(n);
        return millerRabin<mint64>(n, {2, 325, 9375, 28178, 450775, 9780504});
    }
}
