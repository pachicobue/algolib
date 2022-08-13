#pragma once
#include "../common.hpp"
template<typename T>
Vec<T> setHadamard(const Vec<T>& xs, bool rev = false)
{
    const int N = ceil2(xs.size());
    Vec<T> ys(N);
    for (int i : rep(xs.size())) { ys[i] = xs[i]; }
    for (int i = 1; i < N; i <<= 1) {
        for (int j : rep(N)) {
            if ((j & i) == 0) {
                const T x = ys[j], y = ys[j | i];
                ys[j] = x + y, ys[j | i] = x - y;
            }
        }
    }
    if (rev) {
        const T iN = T{1} / N;
        for (auto& y : ys) { y *= iN; }
    }
    return ys;
}
