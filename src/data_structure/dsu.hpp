#pragma once
#include "../misc/common.hpp"
class DSU
{
public:
    DSU(int n) : m_v{n}, m_roots{iotaVec(n)}, m_sizes(m_v, 0) {}
    int root(int i)
    {
        if (m_roots[i] == i) {
            return i;
        } else {
            return m_roots[i] = root(m_roots[i]);
        }
    }
    bool merge(int i, int j)
    {
        i = root(i), j = root(j);
        if (i == j) { return false; }
        if (size(i) > size(j)) { std::swap(i, j); }
        m_roots[i] = j;
        m_sizes[j] = i;
        return true;
    }
    int size(int i)
    {
        return m_sizes[i];
    }
    Vec<Vec<int>> groups() const
    {
        Vec<Vec<int>> iss(m_v);
        for (const int i : rep(m_v)) {
            iss[m_roots[i]].push_back(i);
        }
        return iss;
    }

private:
    int m_v;
    Vec<int> m_roots;
    Vec<int> m_sizes;
};
