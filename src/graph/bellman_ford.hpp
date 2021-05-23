#pragma once
#include "../misc/common.hpp"
#include "graph.hpp"
template<typename T>
Vec<T> bellmanFord(const Graph<T>& g, const int s)
{
    const int N = g.v();
    assert(0 <= s and s < N);
    Vec<T> ds(N, INF<T>);
    ds[s] = 0;
    for (int loop : rep(2 * N)) {
        for (int u : rep(N)) {
            if (ds[u] == INF<T>) { continue; }
            for (const auto& [id, v, c] : g[u]) {
                USE(id);
                if (ds[v] <= ds[u] + c) { continue; }
                ds[v] = ds[u] + c;
                if (loop >= N - 1) { ds[v] = -INF<T>; }
            }
        }
    }
    return ds;
}
