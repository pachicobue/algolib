#pragma once
#include "../misc/common.hpp"
#include "graph.hpp"
namespace diameter_impl {
template<typename T>
struct Edge
{
    Edge(int i, int f, int t, T c) : id{i}, from{f}, to{t}, cost{c} {}
    Edge(const Edge&) = default;
    int id;
    int from, to;
    T cost;
};
};  // namespace diameter_impl
template<typename T>
Vec<diameter_impl::Edge<T>> diameter(const Graph<T>& g)
{
    auto ds = g.depths(0);
    auto ps = g.parents(0);
    const int s = maxInd(ds);
    ds = g.depths(s);
    ps = g.parents(s);
    const int t = maxInd(ds);
    Vec<diameter_impl::Edge<T>> es;
    for (int u = t; ps[u] != -1; u = ps[u]) {
        for (const auto& [id, v, c] : g[u]) {
            if (v == ps[u]) { es.emplace_back(id, u, v, c); }
        }
    }
    return es;
}
