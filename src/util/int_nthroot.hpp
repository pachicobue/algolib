#pragma once
#include "../common.hpp"
#include "bin_search.hpp"

inline u64 intNthRoot(u64 a, u64 k)
{
    if (a == 0) { return 0; }
    if (k == 1) { return a; }
    if (k >= 64) { return 1; }
    auto satPow = [&](const u128& a, int k) {
        u128 x = 1;
        LOOP (k) {
            x *= a;
            if (x >= (u128(1) << 64)) { break; }
        }
        return x;
    };
    return binSearch(1_i64 << 32, 1_i64, [&](i64 x) { return satPow(x, k) <= a; });
}
