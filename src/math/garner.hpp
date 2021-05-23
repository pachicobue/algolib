#pragma once
#include "../misc/common.hpp"
template<typename T>
Vec<T> garner(const Vec<T>& xs, const Vec<T>& ms)
{
    const int N = (int)xs.size();
    Vec<T> as(N);
    for (int i : rep(N)) {
        const T xi = xs[i], mod = ms[i];
        T p = 1, sum = 0;
        for (int j : rep(i)) {
            const T xj = xs[j];
            (sum += p * as[j] % mod) %= mod;
            (p *= (xi + mod - xj)) %= mod;
        }
        const T res = (xi + mod - sum) % mod;
        as[i] = res * modPower(p, mod - 2, mod) % mod;
    }
    return as;
}
