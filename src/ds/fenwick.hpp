#pragma once
#include "../misc/common.hpp"
template<typename T>
class FenwickTree
{
public:
    FenwickTree(const Vec<T>& vs)
        : m_size(vs.size()), m_cap(ceil2(m_size)), m_vs(m_cap + 1, 0)
    {
        std::copy(vs.begin(), vs.end(), m_vs.begin() + 1);
        for (int x : irange(1, m_cap)) {
            m_vs[x + (x & -x)] += m_vs[x];
        }
    }
    void add(int i, const T& v)
    {
        assert(0 <= i and i < m_size);
        for (int ind = i + 1; ind <= m_cap; ind += ind & (-ind)) {
            m_vs[ind] += v;
        }
    }
    T sum(int i) const
    {
        assert(0 <= i and i <= m_size);
        T sum{};
        for (int ind = i; ind != 0; ind &= ind - 1) {
            sum += m_vs[ind];
        }
        return sum;
    }
    T sum(int l, int r) const
    {
        assert(0 <= l and l <= r and r <= m_size);
        return sum(r) - sum(l);
    }
    template<typename F>
    int maxRight(F f)
    {
        assert(f(T{}));
        T sum = T{};
        int x = 0;
        for (int k = (m_cap >> 1); k >= 1; k >>= 1) {
            if (x + k <= m_size and f(sum + m_vs[x + k])) {
                sum += m_vs[x + k], x += k;
            }
        }
        return x;
    }
    friend Ostream& operator<<(Ostream& os, const FenwickTree& fw)
    {
        os << "[";
        for (int i : rep(fw.m_size)) {
            os << (i == 0 ? "" : ",") << fw.sum(i, i + 1);
        }
        return (os << "]\n");
    }

private:
    int m_size, m_cap;
    Vec<T> m_vs;
};
