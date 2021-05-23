#pragma once
#include "../misc/common.hpp"
#include "prime_enumerate.hpp"
template<typename T>
Vec<T> divisorsZeta(const Vec<T>& xs, bool subset)
{
    const int N = (int)xs.size();
    auto ys = xs;
    for (const int p : primeVec(N)) {
        if (subset) {
            for (int i = 1; i * p < N; i++) {
                ys[i * p] += ys[i];
            }
        } else {
            for (int i = (N - 1) / p; i >= 1; i--) {
                ys[i] += ys[i * p];
            }
        }
    }
    return ys;
}
