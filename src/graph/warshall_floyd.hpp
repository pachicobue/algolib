#pragma once
#include "../misc/common.hpp"
#include "graph.hpp"
template<typename T>
Vec<Vec<T>> warshallFloyd(const Graph<T>& g)
{
    const int N = g.v();
    Vec<Vec<T>> dss(N, Vec<T>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dss[i][j] = (i == j ? T{} : INF<T>);
        }
        for (const auto& [j, c] : g[i]) {
            chmin(dss[i][j], c);
        }
    }
    for (int k : rep(N)) {
        for (int i : rep(N)) {
            for (int j : rep(N)) {
                chmin(dss[i][j], dss[i][k] + dss[k][j]);
            }
        }
    }
    return dss;
}
