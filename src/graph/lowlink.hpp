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
        int visited = 0;
        Vec<bool> used(N, false);
        Fixpoint([&](auto dfs, int s, int p) -> void {
            used[s] = true;
            m_ords[s] = visited++;
            bool is_art = false;
            int dim = 0;
            for (int to : g[s]) {
                if (not used[to]) {
                    dim++;
                    dfs(to, s);
                    chmin(m_lows[s], m_lows[to]);
                    is_art |= m_ords[s] > m_lows[to];
                    if (isBridge(s, to)) {
                        m_bridges.push_back(std::minmax({s, to}));
                    }
                } else if (to != p) {
                    chmin(m_lows[s], m_ords[to]);
                }
            }
            if (p == -1) {
                m_is_art[s] = (dim >= 2);
            } else {
                m_is_art[s] = is_art;
            }
        })(0, -1);
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
