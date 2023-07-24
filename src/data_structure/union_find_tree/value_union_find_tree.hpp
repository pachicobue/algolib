#pragma once
#include "../../common.hpp"
template<typename CompInfo>
class ValueUnionFindTree
{
    using T = typename CompInfo::T;

public:
    ValueUnionFindTree(int N) : m_v{N}, m_infos(m_v), m_val{}
    {
        for (int i : rep(N)) { m_infos[i].size = 1, m_infos[i].root = i; }
    }
    int find(int i)
    {
        if (m_infos[i].root == i) {
            return i;
        } else {
            return m_infos[i].root = find(m_infos[i].root);
        }
    }
    bool unite(int i, int j)
    {
        i = find(i), j = find(j);
        m_diffs.push_back({i, m_infos[i]});
        m_diffs.push_back({j, m_infos[j]});
        if (size(i) > size(j)) { std::swap(i, j); }
        m_val -= m_infos[i].eval();
        if (i != j) { m_val -= m_infos[j].eval(); }
        CompInfo::merge(m_infos[i], m_infos[j]);
        m_val += m_infos[j].eval();
        return (i != j);
    }
    bool same(int i, int j) { return find(i) == find(j); }
    int size(int i) { return m_infos[find(i)].size; }
    Vec<Vec<int>> groups()
    {
        Vec<Vec<int>> iss(m_v);
        for (const int i : rep(m_v)) { iss[find(i)].push_back(i); }
        return iss;
    }
    T val() const { return m_val; }
    T eval(int i) { return m_infos[find(i)].eval(); }

private:
    int m_v;
    Vec<CompInfo> m_infos;
    Vec<Pair<int, CompInfo>> m_diffs;
    T m_val;
};
