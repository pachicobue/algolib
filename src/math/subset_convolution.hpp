#pragma once
#include "../misc/common.hpp"
template<typename T>
Vec<T> subsetConvolute(const Vec<T>& f, const Vec<T>& g)
{
    const int l = clog(std::max(f.size(), g.size()));
    const int N = 1 << l;
    auto F = Vec<Vec<T>>(N, Vec<T>(l + 1, 0));
    auto G = Vec<Vec<T>>(N, Vec<T>(l + 1, 0));
    for (int i : rep(f.size())) {
        F[i][popcount(i)] += f[i];
    }
    for (int i : rep(g.size())) {
        G[i][popcount(i)] += g[i];
    }
    for (int i = 1; i < N; i <<= 1) {
        for (int j : rep(N)) {
            if ((j & i) == 0) {
                for (int k : rep(l + 1)) {
                    F[j | i][k] += F[j][k];
                    G[j | i][k] += G[j][k];
                }
            }
        }
    }
    auto H = Vec<Vec<T>>(N, Vec<T>(l + 1, 0));
    for (int i : rep(N)) {
        for (int j : rep(l + 1)) {
            for (int k : rep(l + 1)) {
                if (j + k > l) { continue; }
                H[i][j + k] += F[i][j] * G[i][k];
            }
        }
    }
    for (int i = 1; i < N; i <<= 1) {
        for (int j : rep(N)) {
            if ((j & i) == 0) {
                for (int k : rep(l + 1)) {
                    H[j | i][k] -= H[j][k];
                }
            }
        }
    }
    Vec<T> ans(N);
    for (int i : rep(N)) {
        ans[i] = H[i][popcount(i)];
    }
    return ans;
}
