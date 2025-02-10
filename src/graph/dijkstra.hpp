#pragma once
#include <cassert>
#include "../internal.hpp"
#include "graph.hpp"
/**
 * @brief Dijkstra
 *
 * @param g グラフ (コストは非負)
 * @param S 始点
 * @return Vec<T> 頂点Sからの最短距離
 */
template <typename T> auto dijkstra(const Graph<T>& g, int S) -> Vec<T> {
    const int N = g.V();
    assert(0 <= S and S < N);
    Vec<T> ds(N, INF<T>);
    MinHeap<Pair<T, int>> Q;
    ds[S] = 0, Q.push({T{}, S});
    while (not Q.empty()) {
        const auto [c, u] = Q.top();
        assert(c >= 0);
        Q.pop();
        if (ds[u] < c) {
            continue;
        }
        for (const auto& [v, c] : g[u] | g.ToC) {
            if (ds[v] <= ds[u] + c) {
                continue;
            }
            ds[v] = ds[u] + c, Q.push({ds[v], v});
        }
    }
    return ds;
}
