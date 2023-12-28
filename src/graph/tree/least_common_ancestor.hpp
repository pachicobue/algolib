#pragma once
#include "../../data_structure/sparse_table/static_rmq.hpp"
#include "../../common.hpp"
#include "../graph.hpp"
/**
 * @brief LCA
 */
template<typename C> class LowestCommonAncestor
{
    using P = Pair<int, int>;
public:
    /**
     * @brief コンストラクタ
     * 
     * @param g 無向木
     * @param r 根
     */
    LowestCommonAncestor(const Graph<C>& g, int r = 0)
        : m_V(g.V()),
          m_ins(g.V(), 0),
          m_ds([&]() {
              Vec<P> ans;
              Vec<bool> used(g.V(), false);
              Fix([&](auto dfs, const P& s) -> void {
                  const int u = s.second;
                  used[u]     = true;
                  m_ins[u]    = ans.size();
                  ans.push_back(s);
                  for (int v : g[u]) {
                      if (used[v]) { continue; }
                      dfs(P{s.first + 1, v});
                      ans.push_back(s);
                  }
              })(P{0, r});
              return ans;
          }()),
          m_rmq(m_ds)
    {}
    /**
     * @brief LCA(u,v)
     * 
     * @param u 
     * @param v 
     * @return int LCA(u,v)
     */
    int operator()(int u, int v) const
    {
        const auto [ul, vl] = std::minmax({m_ins[u], m_ins[v]});
        return m_rmq.fold(ul, vl + 1).second;
    }
private:
    int m_V;
    Vec<int> m_ins;
    Vec<P> m_ds;
    StaticRMQ<P, FConst(P{INF<int>, INF<int>}), Lt<P>{}> m_rmq;
};
