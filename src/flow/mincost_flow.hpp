#pragma once
#include "../misc/common.hpp"
template<typename Cap, typename Cost>
struct MinCostBFlow
{
    struct Edge
    {
        int from, to;
        Cap cap;
        Cap flow;
        Cost cost;
        int rid;
        Edge() = default;
        Edge(int from_, int to_, Cap cap_, Cap flow_, Cost cost_, int rid_)
            = default;
    };
    Cap resCap(const Edge& e) const
    {
        return e.cap - e.flow;
    }
    Cost resCost(const Edge& e) const
    {
        return e.cost + m_pots[e.from] - m_pots[e.to];
    }

public:
    MinCostBFlow(int n) : m_v(n), m_bs(n, 0), m_ds(n), m_pots(n, 0)
    {
        m_gs[0].resize(n);
        m_gs[1].resize(n);
    }
    void addEdge(int from, int to, Cap cap, Cost cost)
    {
        addEdge(from, to, 0, cap, cost);
    }
    void addEdge(int from, int to, Cap lower, Cap upper, Cost cost)
    {
        assert(0 <= from and from < m_v);
        assert(0 <= to and to < m_v);
        assert(lower <= upper);
        const int id = m_gs[0][from].size();
        const int rid = m_gs[1][to].size();
        m_gs[0][from].emplace_back(from, to, upper, 0, cost, rid);
        m_gs[1][to].emplace_back(to, from, -lower, 0, -cost, id);
        m_es.emplace_back(from, id);
    }
    void addSupply(int v, Cap b)
    {
        m_bs[v] += b;
    }
    void addDemand(int v, Cap b)
    {
        m_bs[v] -= b;
    }
    template<typename Result = Cost>
    Pair<bool, Result> flow()
    {
        for (int l : rep(2)) {
            for (int u : rep(m_v)) {
                for (auto& e : m_gs[l][u]) {
                    const Cap cap = e.resCap();
                    if (cap < 0) {
                        const int v = e.to;
                        auto& re = m_gs[1 - l][v][e.rid];
                        e.flow += cap, re.flow -= cap;
                        m_bs[u] -= cap, m_bs[v] += cap;
                    }
                }
            }
        }
        Cap maxcap = 1;
        for (int l : rep(2)) {
            for (int u : rep(m_v)) {
                for (const auto& e : m_gs[l][u]) {
                    chmax(maxcap, e.resCap());
                }
            }
        }
        for (Cap delta = floor2(maxcap); delta > 0; delta >>= 1) {
            preCalc(delta);
            while (dual(delta)) {
                primal(delta);
            }
        }
        const bool feasible = m_excs.empty() and m_defs.empty();
        Result ans = 0;
        for (int u : rep(m_v)) {
            for (const auto& e : m_gs[0][u]) {
                ans += (Result)e.flow * e.cost;
            }
        }
        return {feasible, ans};
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
    const Edge& edge(int i) const
    {
        const auto& [u, id] = m_es[i];
        return m_gs[0][u][id];
    }
    Cap potential(int i) const
    {
        return m_pots[i];
    }
    int v() const
    {
        return m_v;
    }
    friend Ostream& operator<<(Ostream& os, const MinCostBFlow& mcf)
    {
        os << "[\n";
        for (int u : rep(mcf.v())) {
            for (const auto& e : mcf[u]) {
                const int v = e.to;
                const Cap cap = e.cap, flow = e.flow;
                const Cost cost = e.cost;
                os << u << "->" << v << " [" << flow << "/" << cap
                   << ",cost=" << cost << "]\n";
            }
        }
        return (os << "]\n");
    }

private:
    void preCalc(Cap delta)
    {
        m_excs.clear(), m_defs.clear();
        for (int l : rep(2)) {
            for (int u : rep(m_v)) {
                for (auto& e : m_gs[l][u]) {
                    const int v = e.to;
                    const Cap cap = e.resCap();
                    const Cost cost = resCost(u, v, e);
                    if (delta <= cap and cost < 0) {
                        auto& re = m_gs[1 - l][v][e.rid];
                        e.flow += cap, re.flow -= cap;
                        m_bs[u] -= cap, m_bs[v] += cap;
                    }
                }
            }
        }
        for (int v : rep(m_v)) {
            if (m_bs[v] > 0) {
                m_excs.push_back(v);
            } else if (m_bs[v] < 0) {
                m_defs.push_back(v);
            }
        }
    }
    void primal(Cap delta)
    {
        Vec<bool> used(m_v, false);
        auto dfs = Fixpoint([&](auto dfs, int v, Cap fmax) -> Cap {
            if (fmax < delta) { return 0; }
            used[v] = true;
            if (m_bs[v] > 0) {
                chmin(fmax, m_bs[v]);
                m_bs[v] -= fmax;
                return fmax;
            }
            for (int l : rep(2)) {
                for (auto& re : m_gs[l][v]) {
                    const int u = re.to;
                    if (used[u]) { continue; }
                    auto& e = m_gs[1 - l][u][re.rid];
                    const Cost cost = resCost(u, v, e);
                    if (e.resCap() > 0 and cost == 0) {
                        chmin(fmax, e.resCap());
                        const Cap f = dfs(u, fmax);
                        if (f >= delta) {
                            e.flow += f, re.flow -= f;
                            return f;
                        }
                    }
                }
            }
            return 0;
        });
        for (int t : m_defs) {
            if (m_ds[t] > m_dmax) { continue; }
            const auto& f = dfs(t, -m_bs[t]);
            if (f >= delta) {
                m_bs[t] += f;
                SHOW(delta, f);
            }
        }
    }
    bool dual(Cap delta)
    {
        fillAll(m_ds, INF<Cost>);
        eraseIf(m_excs, [&](int v) { return m_bs[v] < delta; });
        eraseIf(m_defs, [&](int v) { return m_bs[v] > -delta; });
        for (int v : m_excs) {
            m_ds[v] = 0, m_pq.emplace(m_ds[v], v);
        }
        int def_count = 0;
        m_dmax = 0;
        while (not m_pq.empty()) {
            const auto [d, u] = m_pq.top();
            m_pq.pop();
            if (m_ds[u] < d) { continue; }
            chmax(m_dmax, d);
            if (m_bs[u] <= -delta) { def_count++; }
            for (int l : rep(2)) {
                for (const auto& e : m_gs[l][u]) {
                    const int v = e.to;
                    const Cap nd = d + resCost(u, v, e);
                    if (e.resCap() >= delta) {
                        if (m_ds[v] <= nd) { continue; }
                        m_ds[v] = nd, m_pq.emplace(nd, v);
                    }
                }
            }
        }
        for (int i : rep(m_v)) {
            m_pots[i] += std::min(m_dmax, m_ds[i]);
        }
        return def_count > 0;
    }
    int m_v;
    Vec<Cap> m_bs;
    Vec<Cost> m_ds;
    Vec<int> m_excs, m_defs;
    Vec<Cost> m_pots;
    MinHeap<Pair<Cost, int>> m_pq;
    Cap m_dmax;
    Vec<Pair<int, int>> m_es;
    Arr<Vec<Vec<Edge>>, 2> m_gs;  // (元のグラフ,逆辺のグラフ)
};
