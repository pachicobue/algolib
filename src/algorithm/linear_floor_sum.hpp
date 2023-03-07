#pragma once
#include "../common.hpp"

template<typename T = i64>
T linearFloorSum(i64 N, i64 A, i64 B, i64 C)
{
    // hogehoge
    assert(C != 0);
    if (C < 0) { return linearFloorSum<T>(N, -A, -B, -C); }
    if (A == 0) { return T{N} * floorDiv(B, C); }
    if (0 <= A and A < C and 0 <= B and B < C) {
        const i64 M = ((i128)A * (N - 1) + B) / C;
        return T{N - 1} * M - linearFloorSum<T>(M, C, C - B - 1, A);
    } else {
        const i64 a = floorDiv(A, C);
        const i64 b = floorDiv(B, C);
        return T{N} * (N - 1) / 2 * a + T{N} * b + linearFloorSum<T>(N, A - a * C, B - b * C, C);
    }
}
