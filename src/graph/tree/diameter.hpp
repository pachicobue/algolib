#pragma once
#include "../../common.hpp"
#include "../graph.hpp"
/**
 * @brief 木の直径
 * 
 * @param g 無向木
 * @return Pair<T, Vec<int>> {直径,頂点列}
 */
template<typename T> Pair<T, Vec<int>> diameter(const Graph<T>& g)
{
    auto ds = g.depths(0), ps = g.parents(0);
    const int s = seqMaxInd(ds);
    ds = g.depths(s), ps = g.parents(s);
    const int t = seqMaxInd(ds);
    const i64 D = ds[t];
    Vec<int> vs;
    for (int u = t; u != s; u = ps[u]) { vs.push_back(u); }
    vs.push_back(s);
    return {D, vs};
}
