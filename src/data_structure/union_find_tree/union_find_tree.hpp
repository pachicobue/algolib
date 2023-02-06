#pragma once
#include "../../common.hpp"
class UnionFindTree
{
public:
    UnionFindTree(int n) : m_v{n}, m_roots{iotaVec(n)}, m_sizes(m_v, 1) {}
    int find(int i)
    {
        if (m_roots[i] == i) {
            return i;
        } else {
            return m_roots[i] = find(m_roots[i]);
        }
    }
    bool unite(int i, int j)
    {
        i = find(i), j = find(j);
        if (i == j) { return false; }
        if (size(i) > size(j)) { std::swap(i, j); }
        m_roots[i] = j;
        m_sizes[j] += m_sizes[i];
        return true;
    }
    bool same(int i, int j) { return find(i) == find(j); }
    int size(int i) { return m_sizes[find(i)]; }
    Vec<Vec<int>> groups()
    {
        Vec<Vec<int>> iss(m_v);
        for (const int i : rep(m_v)) { iss[find(i)].push_back(i); }
        return iss;
    }

private:
    int m_v;
    Vec<int> m_roots;
    Vec<int> m_sizes;
};
