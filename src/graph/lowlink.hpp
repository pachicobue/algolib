#pragma once
#include "../misc/common.hpp"
#include "graph.hpp"
template<typename T>
class LowLink
{
    using P = Pair<int, int>;

public:
    LowLink(const Graph<T>& g)
        : m_v(g.v()), m_ords(m_v), m_lows(m_v), m_is_art(m_v)
    {
        const int N = g.v();
        int ord = 0;
        Vec<bool> used(N, false);
        auto dfs = Fix([&](auto dfs, int u, int pe) -> void {
            used[u] = true;
            m_ords[u] = ord++;
            m_lows[u] = m_ords[u];
            bool is_art = false;
            int dim = 0;
            for (const auto& [id, v, c] : g[u]) {
                USE(c);
                if (not used[v]) {
                    dim++;
                    dfs(v, id);
                    chmin(m_lows[u], m_lows[v]);
                    is_art |= (pe != -1 and m_ords[u] <= m_lows[v]);
                    if (isBridge(u, v)) {
                        m_bridges.push_back(std::minmax({u, v}));
                    }
                } else if (id != pe) {
                    chmin(m_lows[u], m_ords[v]);
                }
            }
            if (pe == -1) {
                m_is_art[u] = (dim >= 2);
            } else {
                m_is_art[u] = is_art;
            }
        });
        for (int i : rep(N)) {
            if (not used[i]) { dfs(i, -1); }
        }
    }
    bool isArt(int i) const
    {
        assert(0 <= i and i < m_v);
        return m_is_art[i];
    }
    bool isBridge(int i, int j) const
    {
        assert(0 <= i and i < m_v);
        assert(0 <= j and j < m_v);
        if (m_ords[i] > m_ords[j]) { std::swap(i, j); }
        return m_ords[i] < m_lows[j];
    }
    const Vec<P>& bridges() const
    {
        return m_bridges;
    }
    const Vec<int>& arts() const
    {
        return m_arts;
    }

private:
    int m_v;
    Vec<P> m_bridges;
    Vec<int> m_arts;
    Vec<int> m_ords;
    Vec<int> m_lows;
    Vec<bool> m_is_art;
};
