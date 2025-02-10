#pragma once
#include "../../internal.hpp"
#include "../graph.hpp"
/**
 * @brief 重心分解
 */
template <typename T> class CentroidDecomposition {
public:
    /**
     * @brief コンストラクタ
     *
     * @param g 無向木
     */
    CentroidDecomposition(const Graph<T>& g)
        : m_cs(g.V()) {
        const int N = g.V();
        Vec<int> szs(N, 1);
        Vec<bool> used(N, false);
        auto sizeDfs = Fix([&](auto self, int u, int p) -> int {
            szs[u] = 1;
            for (int v : g[u]) {
                if (v == p or used[v]) {
                    continue;
                }
                szs[u] += self(v, u);
            }
            return szs[u];
        });
        auto getCentor = Fix([&](auto self, int u, int p, int tot) -> int {
            for (int v : g[u]) {
                if (v == p or used[v]) {
                    continue;
                }
                if (szs[v] * 2 > tot) {
                    return self(v, u, tot);
                }
            }
            if (tot == N) {
                m_center = u;
            }
            return u;
        });
        Fix([&](auto self, int u, int pc) -> void {
            const int tot = sizeDfs(u, -1);
            const int c = getCentor(u, -1, tot);
            used[c] = true;
            if (pc != -1) {
                m_cs.addEdge(pc, c);
            }
            for (int v : g[c]) {
                if (not used[v]) {
                    self(v, c);
                }
            }
        })(0, -1);
    }
    /**
     * @brief 重心
     *
     * @return int 重心の一つ
     */
    auto center() const -> int {
        return m_center;
    }
    /**
     * @brief 重心分解を表す有向木
     *
     * @return const Graph<>& 重心同士を結んだ有効木
     */
    auto centers() const -> const Graph<>& {
        return m_cs;
    }
private:
    int m_center;
    Graph<> m_cs;
};
