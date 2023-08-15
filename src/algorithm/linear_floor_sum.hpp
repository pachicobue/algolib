#pragma once
#include "../common.hpp"
/**
 * @brief \sum_{0<=i<N}floor((Ai+B)/C)
 * @attention オーバーフロー対策は無いので注意
 * 
 * @param N 
 * @param A 
 * @param B 
 * @param C 
 * @return i64 \sum_{0<=i<N}floor((Ai+B)/C)
 */
constexpr i64 linearFloorSum(i64 N, i64 A, i64 B, i64 C)
{
    assert(C != 0);
    if (N == 0) { return 0; }
    if (C < 0) { A = -A, B = -B, C = -C; }

    return Fix([&](auto self, i64 N, i64 A, i64 B, i64 C) -> i64 {
        const i64 a = floorDiv(A, C), b = floorDiv(B, C);
        i64 Ans = a * N * (N - 1) / 2 + b * N;
        A -= a * C, B -= b * C;
        if (A > 0) {
            const i64 H = (A * (N - 1) + B) / C;
            Ans += (H * (N - 1) - self(H, C, C - B - 1, A));
        }
        return Ans;
    })(N, A, B, C);
}
