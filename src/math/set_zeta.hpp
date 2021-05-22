#pragma once
#include "../misc/common.hpp"
template<typename T>
Vec<T> setZeta(const Vec<T>& xs, const bool subset)
{
    const int N = ceil2(xs.size());
    Vec<T> ys(N);
    for (int i = 0; i < (int)xs.size(); i++) {
        ys[i] = xs[i];
    }
    for (int i = 1; i < N; i <<= 1) {
        for (int j = 0; j < N; j++) {
            if ((j & i) == 0) {
                (subset ? ys[j | i] : ys[j]) += (subset ? ys[j] : ys[j | i]);
            }
        }
    }
    return ys;
}
