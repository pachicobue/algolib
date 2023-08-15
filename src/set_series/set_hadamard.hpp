#pragma once
#include "../common.hpp"
/**
 * @brief Hadamard変換
 * @attention 実際は逆変換だけに 1/(2^n)倍 を押し付けているので注意
 * 
 * @param F 変換前の数列
 * @param rev 逆変換かどうか
 * @return Vec<T> Hadamard変換後の数列
 */
template<typename T> constexpr Vec<T> setHadamard(const Vec<T>& F, bool rev)
{
    const int N = (int)std::bit_ceil(F.size());
    Vec<T> nF(N);
    for (int i : rep(F.size())) { nF[i] = F[i]; }
    for (int i = 1; i < N; i <<= 1) {
        for (int j : rep(N)) {
            if ((j & i) == 0) {
                const T x = nF[j], y = nF[j | i];
                nF[j] = x + y, nF[j | i] = x - y;
            }
        }
    }
    if (rev) {
        const T iN = T{1} / N;
        for (auto& y : nF) { y *= iN; }
    }
    return nF;
}
