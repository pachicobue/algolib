#pragma once
#include "../internal.hpp"
/**
 * @brief H[i]=\sum{i=j|k}F[j]*G[k]
 *
 * @param F
 * @param G
 * @return Vec<T> H[i]=\sum{i=j|k}F[j]*G[k]
 */
template <typename T> auto orConvolute(Vec<T> F, Vec<T> G) -> Vec<T> {
    const int N = (int)std::bit_ceil(std::max(F.size(), G.size()));
    F.resize(N), G.resize(N);
    auto nF = setZeta(F, true), nG = setZeta(G, true);
    for (int i : rep(N)) {
        nF[i] *= nG[i];
    }
    return setMoebius(nF, true);
}
