#pragma once
#include "../common.hpp"
#include "../number/eratosthenes_sieve.hpp"
/**
 * @brief 約数メビウス変換
 * 
 * @param xs 変換前の数列 (X[0] == 0)
 * @param subset 和を取る方向
 * @param primes N未満の素数リスト
 * @retval Ans[i] = \sum_{j|i} X[j]*\mu(i/j) (subset == Trueの場合)
 * @retval Ans[i] = \sum_{i|j} X[j]*\mu(j/i) (subset == Falseの場合)
 */
template<typename T> constexpr Vec<T> divisorsMoebius(const Vec<T>& xs, bool subset, const Vec<int>& primes)
{
    assert(xs[0] == 0);
    const int N = (int)xs.size();
    auto ys     = xs;
    for (int p : primes) {
        if (subset) {
            for (int i = (N - 1) / p; i >= 1; i--) { ys[i * p] -= ys[i]; }
        } else {
            for (int i = 1; i * p < N; i++) { ys[i] -= ys[i * p]; }
        }
    }
    return ys;
}
/**
 * @brief 約数メビウス変換
 * 
 * @param xs 変換前の数列 (X[0] == 0)
 * @param subset 和を取る方向
 * @retval Ans[i] = \sum_{j|i} X[j]*\mu(i/j) (subset == Trueの場合)
 * @retval Ans[i] = \sum_{i|j} X[j]*\mu(j/i) (subset == Falseの場合)
 */
constexpr auto divisorsMoebius(const auto& xs, bool subset)
{
    return divisorsMoebius(xs, subset, EratosthenesSieve{(int)xs.size()}.primes());
}
