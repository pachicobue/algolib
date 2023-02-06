#pragma once
#include "../../common.hpp"
#include "../graph.hpp"
template<typename T>
class CentroidDecomposition
{
public:
    CentroidDecomposition(const Graph<T>& g) : m_cs(g.v())
    {
        const int N = g.v();
        Vec<int> szs(N, 1);
        Vec<bool> used(N, false);
        auto sizeDfs = Fix([&](auto dfs, int u, int p) -> int {
            szs[u] = 1;
            for (int v : g[u]) {
                if (v == p or used[v]) { continue; }
                szs[u] += dfs(v, u);
            }
            return szs[u];
        });
        auto getCentor = Fix([&](auto dfs, int u, int p, int tot) -> int {
            for (int v : g[u]) {
                if (v == p or used[v]) { continue; }
                if (szs[v] * 2 > tot) { return dfs(v, u, tot); }
            }
            if (tot == N) { m_center = u; }
            return u;
        });
        Fix([&](auto dfs, int u, int pc) -> void {
            const int tot = sizeDfs(u, -1);
            const int c = getCentor(u, -1, tot);
            used[c] = true;
            if (pc != -1) { m_cs.addEdge(pc, c); }
            for (int v : g[c]) {
                if (not used[v]) { dfs(v, c); }
            }
        })(0, -1);
    }
    int center() const { return m_center; }
    const Graph<>& centers() const { return m_cs; }

private:
    int m_center;
    Graph<> m_cs;
};
