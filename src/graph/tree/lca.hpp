#pragma once
#include "../../ds/sparsetable/rmq.hpp"
#include "../../common.hpp"
#include "../graph.hpp"
template<typename C>
class LowestCommonAncestor
{
    using P = Pair<int, int>;

public:
    LowestCommonAncestor(const Graph<C>& g, int r = 0)
        : m_v(g.v()),
          m_ins(g.v(), 0),
          m_ds([&]() {
              Vec<P> ans;
              Vec<bool> used(g.v(), false);
              Fix([&](auto dfs, const P& s) -> void {
                  const int u = s.second;
                  used[u] = true;
                  m_ins[u] = ans.size();
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
    int operator()(int u, int v) const
    {
        const auto [ul, vl] = std::minmax({m_ins[u], m_ins[v]});
        return m_rmq.fold(ul, vl + 1).second;
    }

private:
    struct Ord
    {
        using T = P;
        bool operator()(const T& p1, const T& p2) const { return p1 < p2; }
    };
    int m_v;
    Vec<int> m_ins;
    Vec<P> m_ds;
    StaticRMQ<Ord> m_rmq;
};
