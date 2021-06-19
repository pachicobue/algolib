#pragma once
#include "../misc/common.hpp"
#include "graph.hpp"
template<typename T>
class SCC
{
public:
    SCC(const Graph<T>& g) : m_v(g.v()), m_cs(m_v, -1)
    {
        const int N = g.v();
        Graph<> rg(N);
        for (int u : rep(N)) {
            for (int v : g[u]) {
                rg.addEdge(v, u);
            }
        }
        Vec<int> st;
        Vec<bool> used(N, false);
        auto dfs = Fix([&](auto dfs, int u) -> void {
            used[u] = true;
            for (int v : g[u]) {
                if (not used[v]) { dfs(v); }
            }
            st.push_back(u);
        });
        auto rdfs = Fix([&](auto dfs, int v) -> void {
            m_cs[v] = m_cnum;
            for (int u : rg[v]) {
                if (m_cs[u] != -1) { continue; }
                dfs(u);
            }
        });
        for (int i : rep(N)) {
            if (used[i]) { continue; }
            dfs(i);
        }
        reverseAll(st);
        for (int i : st) {
            if (m_cs[i] != -1) { continue; }
            rdfs(i);
            m_cnum++;
        }
    }
    int operator[](int v) const
    {
        assert(0 <= v and v < m_v);
        return m_cs[v];
    }
    int cnum() const
    {
        return m_cnum;
    }
    Vec<Vec<int>> groups() const
    {
        Vec<Vec<int>> iss(m_v);
        for (const int i : rep(m_v)) {
            iss[m_cs[i]].push_back(i);
        }
        return iss;
    }

private:
    int m_v;
    int m_cnum = 0;
    Vec<int> m_cs;
};
