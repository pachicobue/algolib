#pragma once
#include <cassert>
#include "../internal.hpp"
#include "../number/eratosthenes_sieve.hpp"
/**
 * @brief 約数ゼータ変換
 *
 * @param F 変換前の数列 (F[0]==0)
 * @param subset 和を取る方向
 * @param primes N未満の素数リスト
 * @retval nF[i]=\sum_{j|i}F[j] (subset == Trueの場合)
 * @retval nF[i]=\sum_{i|j}F[j] (subset == Falseの場合)
 */
template <typename T> auto divisorsZeta(const Vec<T>& F, bool subset, const Vec<int>& primes) -> Vec<T> {
    assert(F[0] == 0);
    const int N = (int)F.size();
    auto nF = F;
    for (const int p : primes) {
        if (subset) {
            for (int i = 1; i * p < N; i++) { nF[i * p] += nF[i]; }
        } else {
            for (int i = (N - 1) / p; i >= 1; i--) { nF[i] += nF[i * p]; }
        }
    }
    return nF;
}
/**
 * @brief 約数ゼータ変換
 *
 * @param F 変換前の数列 (F[0]==0)
 * @param subset 和を取る方向
 * @retval nF[i]=\sum_{j|i}F[j] (subset == Trueの場合)
 * @retval nF[i]=\sum_{i|j}F[j] (subset == Falseの場合)
 */
auto divisorsZeta(const auto& F, bool subset) { return divisorsZeta(F, subset, EratosthenesSieve{(int)F.size()}.primes()); }
