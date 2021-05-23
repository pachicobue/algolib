#pragma once
#include "../misc/common.hpp"
template<typename T>
Vec<T> setZeta(const Vec<T>& xs, const bool subset)
{
    const int N = ceil2(xs.size());
    Vec<T> ys(N);
    for (int i : rep(xs.size())) {
        ys[i] = xs[i];
    }
    for (int i = 1; i < N; i <<= 1) {
        for (int j : rep(N)) {
            if ((j & i) == 0) {
                if (subset) {
                    ys[j | i] += ys[j];
                } else {
                    ys[j] += ys[j | i];
                }
            }
        }
    }
    return ys;
}
