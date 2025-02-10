#pragma once
#include "../internal.hpp"
#include "graph.hpp"
/**
 * @brief LowLink
 * @attention 以下に継承させるための基底クラス (直接利用しない)
 *   - TwoEdgeConnectedComponents
 *   - BiConnectedComponents
 */
template <typename T> class LowLink {
protected:
    /**
     * @brief コンストラクタ
     *
     * @param g 無向グラフ
     */
    LowLink(const Graph<T>& g)
        : m_degs(g.V(), 0), m_depths(g.V(), 0), m_lows(g.V(), -1) {
        auto dfs = Fix([&](auto self, int u, int pe) -> void {
            for (const auto& [e, v] : g[u] | g.ETo) {
                if (e == pe) {
                    continue;
                }
                if (m_depths[v] == 0) {
                    m_degs[v]++;
                    m_lows[v] = m_depths[v] = m_depths[u] + 1;
                    self(v, e);
                    chmin(m_lows[u], m_lows[v]);
                } else {
                    chmin(m_lows[u], m_depths[v]);
                }
            }
        });
        for (int i : rep(g.size())) {
            if (m_depths[i] == 0) {
                dfs(i, -1);
            }
        }
    }

    Vec<int> m_degs; // m_degs[u] = uにつながっている下る辺の本数
    Vec<int> m_depths;
    Vec<int> m_lows; // m_lows[u] = uから始めて、下る辺と後退辺を使って到達可能な最小深さ
};
