#pragma once
#include "../common.hpp"
#include "set_hadamard.hpp"
/**
 * @brief H[i]=\sum_{i=j^k}F[j]*G[k]
 * 
 * @param F 
 * @param G 
 * @return Vec<T> H[i]=\sum_{i=j^k}F[j]*G[k]
 */
template<typename T> Vec<T> xorConvolute(Vec<T> F, Vec<T> G)
{
    const int N = (int)std::bit_ceil(std::max(F.size(), G.size()));
    F.resize(N), G.resize(N);
    auto nF = setHadamard(F, false), nG = setHadamard(G, false);
    for (int i : rep(N)) { nF[i] *= nG[i]; }
    return setHadamard(nF, true);
}
