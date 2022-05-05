#pragma once
#include "../misc/common.hpp"
#include "lowlink.hpp"
template<typename T>
class TwoEdgeConnectedComponent : public LowLink<T>
{
public:
    using LowLink<T>::LowLink;
    using LowLink<T>::isBridge;
    using LowLink<T>::bridges;
    TwoEdgeConnectedComponent(const Graph<T>& g)
        : LowLink<T>(g), m_v(g.v()), m_cs(g.v(), -1)
    {
        auto dfs = Fix([&](auto dfs, int u) -> void {
            m_cs[u] = m_cnum;
            for (int v : g[u]) {
                if (isBridge(u, v) or m_cs[v] != -1) { continue; }
                dfs(v);
            }
        });
        for (int i : rep(g.v())) {
            if (m_cs[i] != -1) { continue; }
            dfs(i);
            m_cnum++;
        }
    }
    int operator[](int v) const
    {
        assert(0 <= v and v < m_v);
        return m_cs[v];
    }
    int cnum() const
    {
        return m_cnum;
    }
    Vec<Vec<int>> groups() const
    {
        Vec<Vec<int>> iss(m_v);
        for (int i : rep(m_v)) {
            iss[m_cs[i]].push_back(i);
        }
        return iss;
    }

private:
    int m_v;
    int m_cnum = 0;
    Vec<int> m_cs;
};
