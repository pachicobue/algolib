#pragma once
#include "../../common.hpp"

class UnionFindTree
{
public:
    UnionFindTree(int N) : m_v{N}, m_infos(m_v, -1) {}
    int find(int i)
    {
        if (m_infos[i] < 0) {
            return i;
        } else {
            return m_infos[i] = find(m_infos[i]);
        }
    }
    bool unite(int i, int j)
    {
        i = find(i), j = find(j);
        if (i == j) { return false; }
        if (size(i) > size(j)) { std::swap(i, j); }
        m_infos[j] += m_infos[i];
        m_infos[i] = j;
        return true;
    }
    bool same(int i, int j) { return find(i) == find(j); }
    int size(int i) { return -m_infos[find(i)]; }
    Vec<Vec<int>> groups()
    {
        Vec<Vec<int>> iss(m_v);
        for (const int i : rep(m_v)) { iss[find(i)].push_back(i); }
        return iss;
    }

private:
    int m_v;
    Vec<int> m_infos;
};
