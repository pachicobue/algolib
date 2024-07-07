#pragma once
#include <cassert>
#include "../internal.hpp"
/**
 * @brief Eratosthenesの篩
 */
class EratosthenesSieve {
public:
    /**
     * @brief コンストラクタ
     *
     * @param N N未満に対する篩
     */
    EratosthenesSieve(int N) : m_N{N}, m_factors{iotaVec(N)} {
        for (int i : irange(2, N)) {
            if (m_factors[i] != i) { continue; }
            for (int j : irange(i + i, N, i)) { m_factors[j] = i; }
        }
    }
    /**
     * @brief xの最大素因数
     *
     * @param x
     * @return int 最大素因数
     */
    auto maxPrimeFactor(int x) const -> int {
        assert(1 <= x and x < m_N);
        return m_factors[x];
    }
    /**
     * @brief xが素数か
     *
     * @param x
     * @return true 素数
     * @return false 合成数
     */
    auto isPrime(int x) const -> bool {
        assert(x < m_N);
        if (x <= 1) { return false; }
        return m_factors[x] == x;
    }
    /**
     * @brief N未満の素数列
     *
     * @return Vec<int> 素数列
     */
    auto primes() const -> Vec<int> {
        Vec<int> ps;
        for (int i : irange(2, m_N)) {
            if (m_factors[i] == i) { ps.push_back(i); }
        }
        return ps;
    }
    /**
     * @brief 素因数分解
     *
     * @param x
     * @return Map<int, int> xの素因数分解
     */
    auto primeFactors(int x) const -> Map<int, int> {
        assert(1 <= x and x < m_N);
        Map<int, int> fs;
        while (x > 1) {
            const int p = m_factors[x];
            fs[p]++;
            x /= p;
        }
        return fs;
    }
private:
    int m_N;
    Vec<int> m_factors;
};
