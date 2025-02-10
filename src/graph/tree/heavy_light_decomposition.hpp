#pragma once
#include <cassert>
#include <concepts>
#include "../../internal.hpp"
#include "../graph.hpp"
/**
 * @brief HLD
 */
template <typename T> class HeavyLightDecomposition {
    using P = Pair<int, int>;
public:
    /**
     * @brief コンストラクタ
     * @attention グラフに対して破壊的変更をする (g[u][0] がHeavyEdgeになるように並び替える)
     *
     * @param g 無向木
     * @param r 根
     */
    HeavyLightDecomposition(Graph<T>& g, int r = 0)
        : m_V(g.V()), m_ps(m_V, -1), m_tops(m_V, -1), m_ords(m_V, -1), m_ins(m_V, -1), m_outs(m_V, -1) {
        const int N = g.V();
        Vec<int> szs(N, 1);
        Fix([&](auto self, int u, int p) -> int {
            m_ps[u] = p;
            for (int i : rep(g[u].size())) {
                const int v = g[u][i];
                if (p == v) {
                    continue;
                }
                szs[u] += self(v, u);
                if (szs[(int)g[u][0]] < szs[v]) {
                    std::ranges::swap(g[u][0], g[u][i]);
                }
            }
            return szs[u];
        })(r, -1);
        m_tops[r] = r;
        int index = 0;
        Fix([&](auto self, int u, int p) -> void {
            m_ins[u] = index++;
            m_outs[u] = m_ins[u] + szs[u];
            m_ords[m_ins[u]] = u;
            for (int i : rep(g[u].size())) {
                const int v = g[u][i];
                if (v == p) {
                    continue;
                }
                if (i == 0) {
                    m_tops[v] = m_tops[u];
                } else {
                    m_tops[v] = v;
                }
                self(v, u);
            }
        })(r, -1);
    }
    /**
     * @brief 頂点番号→ET順
     *
     * @param v 頂点番号
     * @return int 訪問順
     */
    auto pos(int v) const -> int {
        return assert(0 <= v and v < m_V), m_ins[v];
    }
    /**
     * @brief ET順→頂点番号
     *
     * @param n ET順
     * @return int 頂点番号
     */
    auto at(int i) const -> int {
        return assert(0 <= i and i < m_V), m_ords[i];
    }
    /**
     * @brief 部分木に属する頂点の ET順区間
     *
     * @param v 頂点番号
     * @return P {l,r} : l<=ET<r が部分木
     */
    auto sub(int v) const -> P {
        assert(0 <= v and v < m_V);
        return {m_ins[v], m_outs[v]};
    }
    /**
     * @brief パスに属する ET順区間集合
     * @attention 閉区間 (向きを表現するため l>r もあり得る)
     *
     * @param u 頂点番号
     * @param v 頂点番号
     * @return P {[l,r]} : ET が l~r
     */
    auto path(int u, int v) const -> Vec<P> {
        assert(0 <= u and u < m_V);
        assert(0 <= v and v < m_V);
        Vec<P> head, tail;
        for (int pu = m_tops[u], pv = m_tops[v]; pu != pv;) {
            if (m_ins[pu] < m_ins[pv]) {
                tail.push_back({m_ins[pv], m_ins[v]});
                v = m_ps[pv];
                pv = m_tops[v];
            } else {
                head.push_back({m_ins[u], m_ins[pu]});
                u = m_ps[pu];
                pu = m_tops[u];
            }
        }
        head.push_back({m_ins[u], m_ins[v]});
        seqReverse(tail);
        for (const auto& p : tail) {
            head.push_back(p);
        }
        return head;
    }
private:
    int m_V;
    Vec<int> m_ps;
    Vec<int> m_tops;
    Vec<int> m_ords;
    Vec<int> m_ins, m_outs;
};
