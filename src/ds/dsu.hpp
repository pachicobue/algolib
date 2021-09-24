#pragma once
#include "../misc/common.hpp"
class DisjointSetUnion
{
public:
    DisjointSetUnion(int n) : m_v{n}, m_roots{iotaVec(n)}, m_sizes(m_v, 1) {}
    int leader(int i)
    {
        if (m_roots[i] == i) {
            return i;
        } else {
            return m_roots[i] = leader(m_roots[i]);
        }
    }
    bool merge(int i, int j)
    {
        i = leader(i), j = leader(j);
        if (i == j) { return false; }
        if (size(i) > size(j)) { std::swap(i, j); }
        m_roots[i] = j;
        m_sizes[j] += m_sizes[i];
        return true;
    }
    int size(int i)
    {
        return m_sizes[leader(i)];
    }
    Vec<Vec<int>> groups()
    {
        Vec<Vec<int>> iss(m_v);
        for (const int i : rep(m_v)) {
            iss[leader(i)].push_back(i);
        }
        return iss;
    }

private:
    int m_v;
    Vec<int> m_roots;
    Vec<int> m_sizes;
};
