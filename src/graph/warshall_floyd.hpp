#pragma once
#include "../misc/common.hpp"
#include "graph.hpp"
template<typename T>
Vec<Vec<T>> warshallFloyd(const Graph<T>& g)
{
    const int N = g.v();
    Vec<Vec<T>> dss(N, Vec<T>(N));
    for (int i : rep(N)) {
        for (int j : rep(N)) {
            dss[i][j] = (i == j ? T{} : INF<T>);
        }
        for (UNUSED const auto& [_, j, c] : g[i]) {
            chmin(dss[i][j], c);
        }
    }
    for (int k : rep(N)) {
        for (int i : rep(N)) {
            for (int j : rep(N)) {
                if (dss[i][k] != INF<T> and dss[k][j] != INF<T>) {
                    chmin(dss[i][j], dss[i][k] + dss[k][j]);
                }
            }
        }
    }
    return dss;
}
