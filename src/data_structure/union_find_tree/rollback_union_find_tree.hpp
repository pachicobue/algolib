#pragma once
#include "../../common.hpp"
template<typename CompInfo>
class RollbackUnionFindTree
{
    using T = typename CompInfo::T;

public:
    RollbackUnionFindTree(int N) : m_v{N}, m_infos(m_v), m_vals(1, T{})
    {
        for (int i : rep(N)) { m_infos[i].size = 1, m_infos[i].root = i; }
    }
    int find(int i) const
    {
        if (m_infos[i].root == i) {
            return i;
        } else {
            return find(m_infos[i].root);
        }
    }
    bool unite(int i, int j)
    {
        auto val = m_vals.back();
        i = find(i), j = find(j);
        m_hists.push_back({i, m_infos[i]});
        m_hists.push_back({j, m_infos[j]});
        if (size(i) > size(j)) { std::swap(i, j); }
        val -= m_infos[i].eval();
        if (i != j) { val -= m_infos[j].eval(); }
        CompInfo::merge(m_infos[i], m_infos[j]);
        val += m_infos[j].eval();
        m_vals.push_back(val);
        return (i != j);
    }
    void undo()
    {
        m_infos[m_hists.back().first] = m_hists.back().second;
        m_hists.pop_back();
        m_infos[m_hists.back().first] = m_hists.back().second;
        m_hists.pop_back();
        m_vals.pop_back();
    }
    bool same(int i, int j) const { return find(i) == find(j); }
    int size(int i) const { return m_infos[find(i)].size; }
    Vec<Vec<int>> groups() const
    {
        Vec<Vec<int>> iss(m_v);
        for (const int i : rep(m_v)) { iss[find(i)].push_back(i); }
        return iss;
    }
    T val() const { return m_vals.back(); }
    T eval(int i) const { return m_infos[find(i)].eval(); }

private:
    int m_v;
    Vec<CompInfo> m_infos;
    Vec<Pair<int, CompInfo>> m_hists;
    Vec<T> m_vals;
};
