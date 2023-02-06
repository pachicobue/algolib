#pragma once
#include "../common.hpp"
class EratosthenesSieve
{
public:
    EratosthenesSieve(int N) : m_N{N}, m_factors{iotaVec(N)}
    {
        for (int i : irange(2, N)) {
            if (m_factors[i] != i) { continue; }
            for (int j : irange(i + i, N, i)) { m_factors[j] = i; }
        }
    }
    int maxPrimeFactor(int x) const
    {
        assert(1 < x and x < m_N);
        return m_factors[x];
    }
    bool isPrime(int x) const
    {
        assert(x < m_N);
        if (x <= 1) { return false; }
        return m_factors[x] == x;
    }
    Vec<int> primes() const
    {
        Vec<int> ps;
        for (int i : irange(2, m_N)) {
            if (m_factors[i] == i) { ps.push_back(i); }
        }
        return ps;
    }
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
