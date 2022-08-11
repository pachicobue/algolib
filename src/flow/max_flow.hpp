#pragma once
#include "../common.hpp"
template<typename T>
class MaxFlow
{
    struct Edge
    {
        int to;
        T cap;
        T flow;
        int rid;
        Edge() = default;
        Edge(int t, T c, T f, int r) : to{t}, cap{c}, flow{f}, rid{r} {}
        T resCap() const { return cap - flow; }
    };

public:
    MaxFlow(int n) : m_v(n), m_ds(n, -1)
    {
        m_is[0].resize(n);
        m_is[1].resize(n);
        m_gs[0].resize(n);
        m_gs[1].resize(n);
    }
    void addEdge(int from, int to, T cap)
    {
        assert(0 <= from and from < m_v);
        assert(0 <= to and to < m_v);
        assert(0 <= cap);
        int id = m_gs[0][from].size();
        int rid = m_gs[1][to].size();
        m_gs[0][from].emplace_back(to, cap, 0, rid);
        m_gs[1][to].emplace_back(from, cap, cap, id);
        m_es.emplace_back(from, id);
    }
    const Edge& edge(int i) const
    {
        const auto& [u, id] = m_es[i];
        return m_gs[0][u][id];
    }
    T maxFlow(int s, int t, T max_flow = INF<T>)
    {
        auto bfs = [&]() {
            fillAll(m_ds, -1);
            Queue<int> q;
            m_ds[s] = 0, q.push(s);
            while (not q.empty()) {
                const int u = q.front();
                q.pop();
                for (int l : rep(2)) {
                    for (const auto& e : m_gs[l][u]) {
                        if (e.resCap() > 0 and m_ds[e.to] == -1) {
                            m_ds[e.to] = m_ds[u] + 1;
                            q.push(e.to);
                        }
                    }
                }
            }
        };
        auto dfs = Fix([&](auto dfs, int u, T fmax) -> T {
            if (u == t) { return fmax; }
            for (int l : rep(2)) {
                for (int& i = m_is[l][u]; i < (int)m_gs[l][u].size(); i++) {
                    auto& e = m_gs[l][u][i];
                    if (e.resCap() > 0 and m_ds[u] < m_ds[e.to]) {
                        const T d = dfs(e.to, std::min(fmax, e.resCap()));
                        if (d > 0) {
                            e.flow += d;
                            m_gs[1 - l][e.to][e.rid].flow -= d;
                            return d;
                        }
                    }
                }
            }
            return 0;
        });
        T flow = 0;
        while (flow < max_flow) {
            bfs();
            if (m_ds[t] == -1) { return flow; }
            for (int l : rep(2)) { fillAll(m_is[l], 0); }
            while (true) {
                T f = dfs(s, max_flow - flow);
                if (f == 0) { break; }
                flow += f;
            }
        }
        return flow;
    }
    Vec<Edge>& operator[](int i)
    {
        assert(0 <= i and i < m_v);
        return m_gs[0][i];
    }
    const Vec<Edge>& operator[](int i) const
    {
        assert(0 <= i and i < m_v);
        return m_gs[0][i];
    }
    int v() const { return m_v; }
    friend Ostream& operator<<(Ostream& os, const MaxFlow& mf)
    {
        const int N = mf.v();
        os << "[\n";
        for (int u : rep(N)) {
            for (const auto& e : mf[u]) {
                const int v = e.to;
                const T cap = e.cap, flow = e.flow;
                os << u << "->" << v << " [" << flow << "/" << cap << "]\n";
            }
        }
        return (os << "]\n");
    }

private:
    int m_v;
    Vec<int> m_ds;
    Arr<Vec<int>, 2> m_is;
    Vec<Pair<int, int>> m_es;
    Arr<Vec<Vec<Edge>>, 2> m_gs;  // (元のグラフ,逆辺のグラフ)
};
