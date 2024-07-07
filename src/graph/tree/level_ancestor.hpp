#pragma once
#include <bit>
#include <cassert>
#include <concepts>
#include "../../internal.hpp"
#include "../graph.hpp"
/**
 * @brief Level Ancestor
 */
class LevelAncestor {
public:
    /**
     * @brief コンストラクタ
     *
     * @param g 無向木
     * @param r 根
     */
    template <typename T> LevelAncestor(const Graph<T>& g, int r = 0) : m_V(g.V()), m_ds(m_V, 0), m_ps(m_V) {
        Fix([&](auto dfs, int u, int p) -> void {
            for (int k = 1; (1 << k) <= m_ds[u]; k++) { m_ps[u].push_back(m_ps[m_ps[u][k - 1]][k - 1]); }
            for (int v : g[u]) {
                if (v == p) { continue; }
                m_ds[v] = m_ds[u] + 1;
                m_ps[v].push_back(u);
                dfs(v, u);
            }
        })(r, -1);
    };
    /**
     * @brief LCA
     *
     * @param u
     * @param v
     * @return int LCA(u,v)
     */
    auto lca(int u, int v) const -> int {
        assert(0 <= u and u < m_V);
        assert(0 <= v and v < m_V);
        if (m_ds[u] > m_ds[v]) { std::ranges::swap(u, v); }
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
    /**
     * @brief LevelAncestor
     *
     * @param v
     * @param d
     * @return int 頂点vのd世代親にあたる頂点
     */
    auto operator()(int v, int d) const -> int {
        assert(0 <= v and v < m_V);
        assert(d <= m_ds[v]);
        for (int k = (int)std::bit_width((u64)d); k >= 0; k--) {
            if (isBitOn(d, k)) { v = m_ps[v][k]; }
        }
        return v;
    }
private:
    int m_V;
    Vec<int> m_ds;
    Vec<Vec<int>> m_ps;
};
