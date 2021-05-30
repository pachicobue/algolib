#pragma once
#include "../misc/common.hpp"
template<typename T = int>
class Graph
{
    struct Edge
    {
        Edge() = default;
        Edge(int i, int t, T c) : id{i}, to{t}, cost{c} {}
        int id;
        int to;
        T cost;
        operator int() const
        {
            return to;
        }
    };

public:
    Graph(int n) : m_v{n}, m_edges(n) {}
    void addEdge(int u, int v, bool bi = false)
    {
        assert(0 <= u and u < m_v);
        assert(0 <= v and v < m_v);
        m_edges[u].emplace_back(m_e, v, 1);
        if (bi) { m_edges[v].emplace_back(m_e, u, 1); }
        m_e++;
    }
    void addEdge(int u, int v, const T& c, bool bi = false)
    {
        assert(0 <= u and u < m_v);
        assert(0 <= v and v < m_v);
        m_edges[u].emplace_back(m_e, v, c);
        if (bi) { m_edges[v].emplace_back(m_e, u, c); }
        m_e++;
    }
    const Vec<Edge>& operator[](const int u) const
    {
        assert(0 <= u and u < m_v);
        return m_edges[u];
    }
    Vec<Edge>& operator[](const int u)
    {
        assert(0 <= u and u < m_v);
        return m_edges[u];
    }
    int v() const
    {
        return m_v;
    }
    int e() const
    {
        return m_e;
    }
    friend Ostream& operator<<(Ostream& os, const Graph& g)
    {
        for (int u : rep(g.v())) {
            for (const auto& [id, v, c] : g[u]) {
                os << "[" << id << "]: ";
                os << u << "->" << v << "(" << c << ")\n";
            }
        }
        return os;
    }
    Vec<T> sizes(int root = 0) const
    {
        const int N = v();
        assert(0 <= root and root < N);
        Vec<T> ss(N, 1);
        Fix([&](auto dfs, int u, int p) -> void {
            for (const auto& [id, v, c] : m_edges[u]) {
                USE(id);
                if (v == p) { continue; }
                dfs(v, u);
                ss[u] += ss[v];
            }
        })(root, -1);
        return ss;
    }
    Vec<T> depths(int root = 0) const
    {
        const int N = v();
        assert(0 <= root and root < N);
        Vec<T> ds(N, 0);
        Fix([&](auto dfs, int u, int p) -> void {
            for (const auto& [id, v, c] : m_edges[u]) {
                USE(id);
                if (v == p) { continue; }
                ds[v] = ds[u] + c;
                dfs(v, u);
            }
        })(root, -1);
        return ds;
    }
    Vec<int> parents(int root = 0) const
    {
        const int N = v();
        assert(0 <= root and root < N);
        Vec<int> ps(N, -1);
        Fix([&](auto dfs, int u, int p) -> void {
            for (const auto& [id, v, c] : m_edges[u]) {
                USE(id);
                if (v == p) { continue; }
                ps[v] = u;
                dfs(v, u);
            }
        })(root, -1);
        return ps;
    }

private:
    int m_v;
    int m_e = 0;
    Vec<Vec<Edge>> m_edges;
};
