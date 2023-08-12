#pragma once
#include "../common.hpp"
constexpr bool millerRabin(u64 n, const Vec<u64>& as)
{
    const auto d = (n - 1) >> lowBit(n - 1);
    for (auto a : as) {
        if (n <= a) { break; }
        auto s = d, x = powerMod(a, s, n);
        while (x != 1 and x != n - 1 and s != n - 1) { s <<= 1, (x *= x) %= n; }
        if (x != n - 1 and s % 2 == 0) { return false; }
    }
    return true;
}
constexpr bool isPrime(u64 n)
{
    if (n == 1) { return false; }
    if (n % 2 == 0) { return n == 2; }
    if (n <= 341531_u64) {
        return millerRabin(n, {9345883071009581737_u64});
    } else if (n <= 1050535501_u64) {
        return millerRabin(n, {336781006125_u64, 9639812373923155_u64});
    } else if (n <= 350269456337_u64) {
        return millerRabin(n, {4230279247111683200_u64, 14694767155120705706_u64, 16641139526367750375_u64});
    } else if (n <= 55245642489451_u64) {
        return millerRabin(n, {2_u64, 141889084524735_u64, 1199124725622454117_u64, 11096072698276303650_u64});
    } else if (n <= 7999252175582851_u64) {
        return millerRabin(n, {2_u64, 4130806001517_u64, 149795463772692060_u64, 186635894390467037_u64, 3967304179347715805_u64});
    } else if (n < 585226005592931977_u64) {
        return millerRabin(
            n, {2_u64, 123635709730000_u64, 9233062284813009_u64, 43835965440333360_u64, 761179012939631437_u64, 1263739024124850375_u64});
    } else {
        return millerRabin(n, {2_u64, 325_u64, 9375_u64, 28178_u64, 450775_u64, 9780504_u64, 1795265022_u64});
    }
}
