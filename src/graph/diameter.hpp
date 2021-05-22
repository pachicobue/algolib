#pragma once
#include "../misc/common.hpp"
#include "graph.hpp"
namespace diameter_impl {
template<typename T>
struct Edge
{
    Edge(int f, int t, T c) : from{f}, to{t}, cost{c} {}
    Edge(const Edge&) = default;
    int from, to;
    T cost;
};
};  // namespace diameter_impl
template<typename T>
Vec<diameter_impl::Edge<T>> diameter(const Graph<T>& g)
{
    const int N = g.v();
    auto ds = g.depths(0);
    auto ps = g.parents(0);
    const int s = maxInd(ds);
    ds[s] = 0;
    ds = g.depths(s);
    ps = g.parents(s);
    const int t = maxInd(ds);
    Vec<diameter_impl::Edge<T>> es;
    for (int u = t; ps[u] != -1;) {
        for (const auto& [v, cost] : g[u]) {
            if (v == ps[u]) {
                u = v;
                es.emplace_back(u, v, cost);
            }
        }
    }
    return es;
}
