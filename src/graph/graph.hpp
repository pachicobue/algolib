#pragma once
#include "../misc/common.hpp"
template<typename T = int>
class Graph
{
    struct Edge
    {
        Edge() = default;
        Edge(int t, T c) : to{t}, cost{c} {}
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
        m_edges[u].emplace_back(v, 1);
        if (bi) { m_edges[v].emplace_back(u, T{1}); }
    }
    void addEdge(int u, int v, const T& c, bool bi = false)
    {
        assert(0 <= u and u < m_v);
        assert(0 <= v and v < m_v);
        m_edges[u].emplace_back(v, c);
        if (bi) { m_edges[v].emplace_back(u, c); }
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
    friend Ostream& operator<<(Ostream& os, const Graph& g)
    {
        for (int u : rep(g.m_v)) {
            for (const auto& e : g[u]) {
                os << e.from << "->" << e.to << "(" << e.cost << ")\n";
            }
        }
        return os;
    }
    Vec<T> sizes(int root = 0) const
    {
        const int N = v();
        assert(0 <= root and root < N);
        Vec<T> ss(N, 1);
        Fixpoint([&](auto dfs, int u, int p) -> void {
            for (const auto& [v, c] : m_edges[u]) {
                if (v == p) { continue; }
                dfs(v, u);
                ss[v] += ss[u];
            }
        })(root, -1);
        return ss;
    }
    Vec<T> depths(int root = 0) const
    {
        const int N = v();
        assert(0 <= root and root < N);
        Vec<T> ds(N, 0);
        Fixpoint([&](auto dfs, int u, int p) -> void {
            for (const auto& [v, c] : m_edges[u]) {
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
        Fixpoint([&](auto dfs, int u, int p) -> void {
            for (const auto& [v, c] : m_edges[u]) {
                if (v == p) { continue; }
                ps[v] = u;
                dfs(v, u);
            }
        })(root, -1);
        return ps;
    }

private:
    int m_v;
    Vec<Vec<Edge>> m_edges;
};
