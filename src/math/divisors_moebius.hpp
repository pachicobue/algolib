#pragma once
#include "../common.hpp"
#include "primes.hpp"
template<typename T>
Vec<T> divisorsMoebius(const Vec<T>& xs, bool subset)
{
    const int N = (int)xs.size();
    auto ys = xs;
    for (const int p : primes(N)) {
        if (subset) {
            for (int i = (N - 1) / p; i >= 1; i--) {
                ys[i * p] -= ys[i];
            }
        } else {
            for (int i = 1; i * p < N; i++) {
                ys[i] -= ys[i * p];
            }
        }
    }
    return ys;
}
