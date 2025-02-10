#pragma once
#include <cassert>
#include "../internal.hpp"
#include "graph.hpp"
/**
 * @brief 0/1 BFS
 *
 * @param g グラフ (コストが0/1)
 * @param S 始点
 * @return Vec<T> 頂点Sからの最短距離
 */
template <typename T> auto bfs01(const Graph<T>& g, int S) -> Vec<T> {
    const int N = g.V();
    assert(0 <= S and S < N);
    Vec<T> ds(N, INF<T>);
    Deq<Pair<T, int>> Q;
    ds[S] = 0, Q.push_front({T{}, S});
    while (not Q.empty()) {
        const auto [c, u] = Q.front();
        assert(c == 0 or c == 1);
        Q.pop_front();
        if (ds[u] < c) {
            continue;
        }
        for (const auto& [v, c] : g[u] | g.ToC) {
            if (ds[v] <= ds[u] + c) {
                continue;
            }
            ds[v] = ds[u] + c;
            if (c == 0) {
                Q.push_front({ds[v], v});
            } else {
                Q.push_back({ds[v], v});
            }
        }
    }
    return ds;
}
