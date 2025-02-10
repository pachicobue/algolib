#pragma once
#include "../internal.hpp"
/**
 * @brief 約数列挙
 *
 * @param N
 * @return Vec<i64> Nの約数列
 */
inline auto divisors(const i64 N) -> Vec<i64> {
    Vec<i64> head, tail;
    for (i64 i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            head.push_back(i);
            if (i * i != N) {
                tail.push_back(N / i);
            }
        }
    }
    seqReverse(tail), seqConcat(head, tail);
    return head;
}
