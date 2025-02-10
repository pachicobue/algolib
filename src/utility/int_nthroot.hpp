#pragma once
#include <cassert>
#include "../internal/irange.hpp"
#include "../internal/type.hpp"
#include "bin_search.hpp"
/**
 * @brief floor(A^(1/K))
 *
 * @param A 非負整数 (u64なので注意)
 * @param K 非負整数
 * @return u64 floor(A^(1/K))
 */
constexpr auto intNthRoot(u64 A, int K) -> u64 {
    assert(K > 0);
    if (A == 0) {
        return 0;
    }
    if (K == 1) {
        return A;
    }
    if (K > 64) {
        return 1;
    }
    return binSearch(1_i64 << 32, 1_i64, [&](i64 a) {
        u64 x = (u64)1;
        LOOP (K) {
            if (x > A / a) {
                return false;
            }
            x *= a;
        }
        return true;
    });
}
/**
 * @brief floor(sqrt(A))
 *
 * @param A 非負整数 (u64なので注意)
 * @return u64 floor(sqrt(A))
 */
constexpr auto intSqrt(u64 A) -> u64 {
    return intNthRoot(A, 2);
}
