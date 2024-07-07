#pragma once
#include <cassert>
#include "../internal.hpp"
#include "graph.hpp"
/**
 * @brief Bellman-Ford
 *
 * @param g グラフ
 * @param S 始点
 * @return Vec<T> 頂点Sからの最短距離
 */
template <typename T> auto bellmanFord(const Graph<T>& g, int S) -> Vec<T> {
    const int N = g.V();
    assert(0 <= S and S < N);
    Vec<T> ds(N, INF<T>);
    ds[S] = 0;
    for (int loop : rep(2 * N)) {
        for (int u : rep(N)) {
            if (ds[u] == INF<T>) { continue; }
            for (const auto& [v, c] : g[u] | g.ToC) {
                if (ds[v] <= ds[u] + c) { continue; }
                ds[v] = ds[u] + c;
                if (loop >= N - 1) { ds[v] = -INF<T>; }
            }
        }
    }
    return ds;
}
