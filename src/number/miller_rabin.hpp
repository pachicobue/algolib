#pragma once
#include "../common.hpp"
#include "../utility/modint.hpp"
/**
 * @brief Miller Rabin
 * 
 * @param X 素数判定する値
 * @param as テスト用シード数列
 * @return true Xが素数
 * @return false Xが合成数
 */
constexpr bool millerRabin(u64 X, const Vec<u64>& as)
{
    using mint = modint_dynamic_reserved<81165>;
    mint::setMod(X);
    const u64 d = (X - 1) >> order2(X - 1);
    for (u64 a : as) {
        if (X <= a) { break; }
        u64 s  = d;
        mint x = mint(a).pow(s);
        while (x != 1 and x != X - 1 and s != X - 1) { s *= 2, x *= x; }
        if (x != X - 1 and s % 2 == 0) { return false; }
    }
    return true;
}
/**
 * @brief 素数判定
 * @see https://zenn.dev/kaki_xxx/articles/40a92b43200215
 * 
 * @param X 
 * @return true Xが素数
 * @return false Xが合成数
 */
constexpr bool isPrime(u64 X)
{
    if (X == 1) { return false; }
    if (X % 2 == 0) { return X == 2; }
    if (X < 4759123141_u64) {
        return millerRabin(X, {2_u64, 7_u64, 61_u64});
    } else {
        return millerRabin(X, {2_u64, 325_u64, 9375_u64, 28178_u64, 450775_u64, 9780504_u64, 1795265022_u64});
    }
}
