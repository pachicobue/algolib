#pragma once
#include "../internal.hpp"
#include "graph.hpp"
/**
 * @brief Floyd-Warshall
 *
 * @param g グラフ
 * @return Vec<Vec<T>> 全点対最短距離
 */
template <typename T> auto floydWarshall(const Graph<T>& g) -> Vec<Vec<T>> {
    const int N = g.V();
    Vec<Vec<T>> dss(N, Vec<T>(N));
    for (int i : rep(N)) {
        for (int j : rep(N)) { dss[i][j] = (i == j ? T{} : INF<T>); }
        for (const auto& [j, c] : g[i] | g.ToC) { chmin(dss[i][j], c); }
    }
    for (int k : rep(N)) {
        for (int i : rep(N)) {
            for (int j : rep(N)) {
                if (dss[i][k] != INF<T> and dss[k][j] != INF<T>) { chmin(dss[i][j], dss[i][k] + dss[k][j]); }
            }
        }
    }
    return dss;
}
