#pragma once
#include "../misc/common.hpp"
#include "graph.hpp"
template<typename T>
Vec<T> dijkstra(const Graph<T>& g, int s)
{
    const int N = g.v();
    assert(0 <= s and s < N);
    Vec<T> ds(N, INF<T>);
    using P = Pair<T, int>;
    MinHeap<P> Q;
    ds[s] = 0;
    Q.push({T{}, s});
    while (not Q.empty()) {
        const auto [c, u] = Q.top();
        Q.pop();
        if (ds[u] < c) { continue; }
        for (const auto& [v, c] : g[u]) {
            if (ds[v] <= ds[u] + c) { continue; }
            ds[v] = ds[u] + c;
            Q.push({ds[v], v});
        }
    }
    return ds;
}
