#pragma once
#include "../common.hpp"
/**
 * @brief Eratosthenesの篩
 */
class EratosthenesSieve
{
public:
    /**
     * @brief コンストラクタ
     *
     * @param N N未満に対する篩
     */
    EratosthenesSieve(int N) : m_N{N}, m_factors{iotaVec(N)}
    {
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
    int maxPrimeFactor(int x) const
    {
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
    bool isPrime(int x) const
    {
        assert(x < m_N);
        if (x <= 1) { return false; }
        return m_factors[x] == x;
    }
    /**
     * @brief N未満の素数列
     * 
     * @return Vec<int> 素数列
     */
    Vec<int> primes() const
    {
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
    Map<int, int> primeFactors(int x) const
    {
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
