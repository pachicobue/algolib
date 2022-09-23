#pragma once
#include "../common.hpp"
#include "graph.hpp"
template<typename T>
Vec<T> bfs_01(const Graph<T>& g, int s)
{
    const int N = g.v();
    assert(0 <= s and s < N);
    Vec<T> ds(N, INF<T>);
    using P = Pair<T, int>;
    Deq<P> Q;
    ds[s] = 0;
    Q.push_front({T{}, s});
    while (not Q.empty()) {
        const auto [c, u] = Q.front();
        Q.pop_front();
        if (ds[u] < c) { continue; }
        for (UNUSED const auto& [_, v, c] : g[u]) {
            if (ds[v] <= ds[u] + c) { continue; }
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
