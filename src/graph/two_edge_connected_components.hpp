#pragma once
#include <cassert>
#include <concepts>
#include "../internal.hpp"
#include "graph.hpp"
#include "low_link.hpp"
/**
 * @brief 二重辺連結成分分解
 */
template <typename T> class TwoEdgeConnectedComponent : public LowLink<T> {
public:
    /**
     * @brief コンストラクタ
     *
     * @param g 無向グラフ
     */
    TwoEdgeConnectedComponent(const Graph<T>& g)
        : LowLink<T>{g}, m_cnum{0}, m_cs{g.V()}, m_g{g} {
        auto dfs = Fix([&](auto self, int u) -> void {
            m_cs[u] = m_cnum;
            for (const auto& [e, v] : g[u] | g.ETo) {
                if (isBridge(e) or m_cs[v] != -1) {
                    continue;
                }
                self(v);
            }
        });
        for (int i : rep(g.V())) {
            if (m_cs[i] != -1) {
                continue;
            }
            dfs(i), m_cnum++;
        }
    }
    /**
     * @brief 頂点が属する成分番号
     *
     * @param u 頂点番号
     * @return int 成分番号
     */
    auto operator[](int u) const -> int {
        return assert(0 <= u and u < m_g.V()), m_cs[u];
    }
    /**
     * @brief 二重辺連結成分数
     *
     * @return int 成分数
     */
    auto cnum() const -> int {
        return m_cnum;
    }
    /**
     * @brief 各成分の頂点集合
     *
     * @return Vec<Vec<int>> 頂点列
     */
    auto groups() const -> Vec<Vec<int>> {
        Vec<Vec<int>> iss(cnum());
        for (int i : rep(m_g.V())) {
            iss[m_cs[i]].push_back(i);
        }
        return iss;
    }
    /**
     * @brief 橋判定
     *
     * @param eid 辺番号
     * @return true 辺が橋
     * @return false 辺が橋でない
     */
    auto isBridge(int eid) const -> bool {
        assert(0 <= eid and eid < m_g.E());
        auto [u, v] = m_g.edge(eid);
        if (m_depths[u] > m_depths[v]) {
            std::ranges::swap(u, v);
        }
        return m_depths[u] < m_lows[v];
    }
    /**
     * @brief 橋の列挙
     *
     * @return Vec<int> 橋である辺番号列
     */
    auto bridges() const -> Vec<int> {
        Vec<int> Ans;
        for (int e : rep(m_g.E())) {
            if (isBridge(e)) {
                Ans.push_back(e);
            }
        }
        return Ans;
    }
private:
    using LowLink<T>::m_depths;
    using LowLink<T>::m_lows;

    int m_cnum;
    Vec<int> m_cs;
    const Graph<T>& m_g;
};
