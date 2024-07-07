#pragma once
#include <cassert>
#include "../internal.hpp"
#include "graph.hpp"
#include "low_link.hpp"
/**
 * @brief 二重頂点連結成分分解
 *
 */
template <typename T> class BiConnectedComponent : public LowLink<T> {
public:
    /**
     * @brief Construct a new BiConnected Component object
     *
     * @param g 無向グラフ
     */
    BiConnectedComponent(const Graph<T>& g) : LowLink<T>{g}, m_cnum{0}, m_cs(g.E()), m_g{g} {
        Vec<int> freeEdges; // どこにも属していない辺 (祖先の関節点待ち)
        auto dfs = Fix([&](auto self, int u) -> void {
            for (const auto& [e, v] : g[u] | g.ETo) {
                if (m_depths[v] < m_depths[u]) { continue; }
                freeEdges.push_back(e);
                self(v);
                if (m_lows[v] >= m_depths[u]) {
                    while (not freeEdges.empty()) {
                        const int se = freeEdges.back();
                        freeEdges.pop_back();
                        m_cs[se] = m_cnum;
                        if (se == e) { break; }
                    }
                    m_cnum++;
                }
            }
        });
        for (int i : rep(g.V())) {
            if (m_depths[i] != 0) { continue; }
            dfs(i), m_cnum++;
        }
    }
    /**
     * @brief 辺が属する成分番号
     *
     * @param eid 辺番号
     * @return int 成分番号
     */
    auto operator[](int eid) const -> int { return assert(0 <= eid and eid < m_g.E()), m_cs[eid]; }
    /**
     * @brief 二重頂点連結成分数
     *
     * @return int 成分数
     */
    auto cnum() const -> int { return m_cnum; }
    /**
     * @brief 各成分の辺集合
     *
     * @return Vec<Vec<int>> 辺番号列
     */
    auto groups() const -> Vec<Vec<int>> {
        Vec<Vec<int>> iss(cnum());
        for (int i : rep(m_g.V())) { iss[m_cs[i]].push_back(i); }
        return iss;
    }
    /**
     * @brief 関節点判定
     *
     * @param u 頂点番号
     * @return true 頂点が関節点
     * @return false 頂点が関節点でない
     */
    auto isArt(int u) -> bool {
        if (m_depths[u] == 0) {
            return (m_degs[u] >= 2);
        } else {
            for (int v : m_g[u]) {
                if (m_depths[v] < m_depths[u]) { continue; }
                if (m_lows[v] >= m_depths[u]) { return true; }
            }
            return false;
        }
    }
    /**
     * @brief 関節点の列挙
     *
     * @return Vec<int> 関節点である頂点番号列
     */
    auto arts() -> Vec<int> {
        Vec<int> Ans;
        for (int u : rep(m_g.V())) {
            if (isArt(u)) { Ans.push_back(u); }
        }
        return Ans;
    }
private:
    using LowLink<T>::m_degs;
    using LowLink<T>::m_depths;
    using LowLink<T>::m_lows;

    int m_cnum;
    Vec<int> m_cs;
    const Graph<T>& m_g;
};
