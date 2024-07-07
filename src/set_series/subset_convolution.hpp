#pragma once
#include <bit>
#include "../internal.hpp"
/**
 * @brief H[i]=\sum_{i=j|k && j&k==0}F[j]*G[k]
 *
 * @param F
 * @param G
 * @return Vec<T> H[i]=\sum_{i=j|k && j&k==0}F[j]*G[k]
 */
template <typename T> auto subsetConvolute(const Vec<T>& F, const Vec<T>& G) -> Vec<T> {
    const int l = floorLog2((u64)std::bit_ceil(std::max(F.size(), G.size())));
    const int N = 1 << l;
    auto nF = Vec<Vec<T>>(N, Vec<T>(l + 1, 0));
    auto nG = Vec<Vec<T>>(N, Vec<T>(l + 1, 0));
    for (int i : rep(F.size())) { nF[i][std::popcount((u64)i)] += F[i]; }
    for (int i : rep(G.size())) { nG[i][std::popcount((u64)i)] += G[i]; }
    for (int i = 1; i < N; i <<= 1) {
        for (int j : rep(N)) {
            if ((j & i) == 0) {
                for (int k : rep(l + 1)) {
                    nF[j | i][k] += nF[j][k];
                    nG[j | i][k] += nG[j][k];
                }
            }
        }
    }
    auto H = Vec<Vec<T>>(N, Vec<T>(l + 1, 0));
    for (int i : rep(N)) {
        for (int j : rep(l + 1)) {
            for (int k : rep(l + 1)) {
                if (j + k > l) { continue; }
                H[i][j + k] += nF[i][j] * nG[i][k];
            }
        }
    }
    for (int i = 1; i < N; i <<= 1) {
        for (int j : rep(N)) {
            if ((j & i) == 0) {
                for (int k : rep(l + 1)) { H[j | i][k] -= H[j][k]; }
            }
        }
    }
    Vec<T> ans(N);
    for (int i : rep(N)) { ans[i] = H[i][std::popcount((u64)i)]; }
    return ans;
}
