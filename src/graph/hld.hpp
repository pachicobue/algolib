#pragma once
#include "../misc/common.hpp"
#include "graph.hpp"
template<typename T>
class HLD
{
    using P = Pair<int, int>;

public:
    HLD(Graph<T>& g, int r = 0)
        : m_v(g.v()),
          m_ps(m_v, -1),
          m_tops(m_v, -1),
          m_ords(m_v, -1),
          m_ins(m_v, -1),
          m_outs(m_v, -1)
    {
        const int N = g.v();
        Vec<int> szs(N, 1);
        Fixpoint([&](auto dfs, int u, int p) -> int {
            m_ps[u] = p;
            for (int i : rep(g[u].size())) {
                const int v = g[u][i];
                if (p == v) { continue; }
                szs[u] += dfs(v, u);
                if (szs[(int)g[u][0]] < szs[v]) { std::swap(g[u][0], g[u][i]); }
            }
            return szs[u];
        })(r, -1);
        m_tops[r] = r;
        int index = 0;
        Fixpoint([&](auto dfs, int u, int p) -> void {
            m_ins[u] = index++;
            m_ords[m_ins[u]] = u;
            for (int i : rep(g[u].size())) {
                const int v = g[u][i];
                if (v == p) { continue; }
                if (i == 0) {
                    m_tops[v] = m_tops[u];
                } else {
                    m_tops[v] = v;
                }
                dfs(v, u);
            }
        })(r, -1);
    }
    int pos(int v) const
    {
        assert(0 <= v and v < m_v);
        return m_ins[v];
    }
    int at(int n) const
    {
        assert(0 <= n and n < m_v);
        return m_ords[n];
    }
    P sub(int v) const
    {
        assert(0 <= v and v < m_v);
        return {m_ins[v], m_outs[v]};
    }
    Vec<P> path(int u, int v) const
    {
        assert(0 <= u and u < m_v);
        assert(0 <= v and v < m_v);
        Vec<P> head, tail;
        for (int pu = m_tops[u], pv = m_tops[v]; pu != pv;) {
            if (m_ins[pu] < m_ins[pv]) {
                tail.push_back({m_ins[pv], m_ins[v]});
                v = m_ps[pv];
                pv = m_tops[v];
            } else {
                head.push_back({m_ins[u], m_ins[pu]});
                u = m_ps[pu];
                pu = m_tops[u];
            }
        }
        head.push_back({m_ins[u], m_ins[v]});
        reverseAll(tail);
        for (const auto& p : tail) {
            head.push_back(p);
        }
        return head;
    }

private:
    int m_v;
    Vec<int> m_ps;
    Vec<int> m_tops;
    Vec<int> m_ords;
    Vec<int> m_ins, m_outs;
};
