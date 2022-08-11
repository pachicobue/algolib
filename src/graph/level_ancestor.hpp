#pragma once
#include "../common.hpp"
#include "graph.hpp"
class LevelAncestor
{
public:
    template<typename T>
    LevelAncestor(const Graph<T>& g, int r = 0) : m_v(g.v()), m_ds(m_v, 0), m_ps(m_v)
    {
        Fix([&](auto dfs, int u, int p) -> void {
            for (int k = 1; (1 << k) <= m_ds[u]; k++) {
                m_ps[u].push_back(m_ps[m_ps[u][k - 1]][k - 1]);
            }
            for (int v : g[u]) {
                if (v == p) { continue; }
                m_ds[v] = m_ds[u] + 1;
                m_ps[v].push_back(u);
                dfs(v, u);
            }
        })(r, -1);
    };
    int lca(int u, int v) const
    {
        assert(0 <= u and u < m_v);
        assert(0 <= v and v < m_v);
        if (m_ds[u] > m_ds[v]) { std::swap(u, v); }
        v = (*this)(v, m_ds[v] - m_ds[u]);
        if (u == v) { return u; }
        while (true) {
            if (m_ps[u][0] == m_ps[v][0]) { return m_ps[u][0]; }
            for (int i = m_ps[u].size() - 1; i >= 0; i--) {
                const int nu = m_ps[u][i], nv = m_ps[v][i];
                if (nu != nv) {
                    u = nu, v = nv;
                    break;
                }
            }
        }
    }
    int operator()(int v, int d) const
    {
        assert(0 <= v and v < m_v);
        for (int k = (int)log2p1(d); k >= 0; k--) {
            if (btest(d, k)) { v = m_ps[v][k]; }
        }
        return v;
    }

private:
    int m_v;
    Vec<int> m_ds;
    Vec<Vec<int>> m_ps;
};
