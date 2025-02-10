#pragma once
#include <cassert>
#include "../internal.hpp"
#include "graph.hpp"
/**
 * @brief 強連結成分分解
 */
template <typename T> class StronglyConnectedComponents {
public:
    /**
     * @brief コンストラクタ
     *
     * @param g 有向グラフ
     */
    StronglyConnectedComponents(const Graph<T>& g)
        : m_V(g.V()), m_cnum{0}, m_cs(m_V, -1) {
        const int N = g.V();
        Graph rg(N);
        for (int u : rep(N)) {
            for (int v : g[u]) {
                rg.addEdge(v, u);
            }
        }
        Vec<int> st;
        Vec<bool> used(N, false);
        auto dfs = Fix([&](auto self, int u) -> void {
            used[u] = true;
            for (int v : g[u]) {
                if (not used[v]) {
                    self(v);
                }
            }
            st.push_back(u);
        });
        auto rdfs = Fix([&](auto self, int v) -> void {
            m_cs[v] = m_cnum;
            for (int u : rg[v]) {
                if (m_cs[u] != -1) {
                    continue;
                }
                self(u);
            }
        });
        for (int i : rep(N)) {
            if (used[i]) {
                continue;
            }
            dfs(i);
        }
        seqReverse(st);
        for (int i : st) {
            if (m_cs[i] != -1) {
                continue;
            }
            rdfs(i);
            m_cnum++;
        }
    }
    /**
     * @brief 頂点が属する成分番号
     *
     * @param v 頂点番号
     * @return int 成分番号
     */
    auto operator[](int u) const -> int {
        return assert(0 <= u and u < m_V), m_cs[u];
    }
    /**
     * @brief 強連結成分数
     *
     * @return int 成分数
     */
    auto cnum() const -> int {
        return m_cnum;
    }
    /**
     * @brief 各成分の頂点集合
     *
     * @return Vec<Vec<int>> 頂点番号列
     */
    auto groups() const -> Vec<Vec<int>> {
        Vec<Vec<int>> iss(m_V);
        for (int i : rep(m_V)) {
            iss[m_cs[i]].push_back(i);
        }
        return iss;
    }
private:
    int m_V;
    int m_cnum;
    Vec<int> m_cs;
};
