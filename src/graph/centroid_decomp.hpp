#pragma once
#include "../misc/common.hpp"
#include "graph.hpp"
template<typename T>
class CentroidDecomp
{
public:
    CentroidDecomp(const Graph<T>& g)
        : m_g{g},
          m_cs(m_g.v()),
          m_sub_calced{false},
          m_subss(m_g.v()),
          m_subsss(m_g.v())
    {
        const int N = m_g.v();
        Vec<int> szs(N, 1);
        Vec<bool> used(N, false);
        auto sizeDfs = Fixpoint([&](auto dfs, int s, int p) -> int {
            szs[s] = 1;
            for (int to : m_g[s]) {
                if (to == p or used[to]) { continue; }
                szs[s] += dfs(to, s);
            }
        });
        auto getCentor = Fixpoint([&](auto dfs, int s, int p, int tot) -> int {
            for (int to : m_g[s]) {
                if (to == p or used[to]) { continue; }
                if (szs[to] * 2 > tot) { return dfs(to, s, tot); }
            }
            if (tot == N) { m_center = s; }
            return s;
        });
        Fixpoint([&](auto dfs, int s, int pc) -> int {
            const int tot = sizeDfs(s, -1);
            const int c = getCentor(s, -1, tot);
            used[c] = true;
            if (pc != -1) { m_cs.addEdge(pc, c); }
            for (int to : m_g[s]) {
                if (not used[to]) { dfs(to, s, c); }
            }
        })(0, N);
    }
    const int center() const
    {
        return m_center;
    }
    const Graph<>& centers() const
    {
        return m_cs;
    }
    const Vec<int>& subs(int v)
    {
        const int N = m_g.v();
        assert(0 <= v and v < N);
        calcSub();
        return m_subss[v];
    }
    const Vec<Vec<int>>& subss(int v)
    {
        const int N = m_g.v();
        assert(0 <= v and v < N);
        calcSub();
        return m_subsss[v];
    }
private:
    void calcSub()
    {
        if (not m_sub_calced) {
            const int N = m_g.v();
            Vec<bool> used(N, false);
            Fixpoint([&](auto dfs, const int c) -> void {
                used[c] = true;
                m_subss[c].push_back(c);
                for (int to : m_g[c]) {
                    if (used[to]) { continue; }
                    m_subsss[c].push_back(Vec<int>{});
                    Fixpoint([&](auto dfs2, const int s, const int p) -> void {
                        for (int to2 : m_g[s]) {
                            if (p == to2 or used[to2]) { continue; }
                            m_subss[c].push_back(to2);
                            m_subsss[c].back().push_back(to2);
                            dfs2(to2, s);
                        }
                    })(to, -1);
                }
                for (int to : m_g[c]) {
                    dfs(to);
                }
            })(m_center);
        }
        m_sub_calced = true;
    }
    Graph<T> m_g;
    int m_center;
    Graph<> m_cs;
    bool m_sub_calced;
    Vec<Vec<int>> m_subss;
    Vec<Vec<Vec<int>>> m_subsss;
};
