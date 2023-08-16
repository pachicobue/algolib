#pragma once
#include "../common.hpp"
/**
 * @brief 集合のメビウス変換
 * 
 * @param F 
 * @param subset 和を取る方向
 * @retval nF[i]=\sum_{j \subset i}F[j]*(-1)^|i^j| (subset == Trueの場合)
 * @retval nF[i]=\sum_{i \subset j}F[j]*(-1)^|i^j| (subset == Falseの場合)
 */
template<typename T> Vec<T> setMoebius(const Vec<T>& F, bool subset)
{
    const int N = (int)std::bit_ceil(F.size());
    Vec<T> nF(N);
    for (int i : rep(F.size())) { nF[i] = F[i]; }
    for (int i = 1; i < N; i <<= 1) {
        for (int j : rep(N)) {
            if ((j & i) == 0) {
                if (subset) {
                    nF[j | i] -= nF[j];
                } else {
                    nF[j] -= nF[j | i];
                }
            }
        }
    }
    return nF;
}
