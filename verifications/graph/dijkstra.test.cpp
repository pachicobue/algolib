#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "misc/fastio/printer.hpp"
#include "misc/fastio/scanner.hpp"
#include "graph/dijkstra.hpp"
int main()
{
    const auto [N, M, S, T] = in.tup<int, int, int, int>();
    Graph<i64> g(N), rg(N);
    for (int i : rep(M)) {
        const auto [u, v, c] = in.tup<int, int, i64>();
        g.addEdge(u, v, c), rg.addEdge(v, u, c);
    }
    const auto ds = dijkstra(g, S);
    if (ds[T] >= INF<i64>) { return out.ln(-1); }
    using pii = Pair<int, int>;
    Vec<bool> used(N, false);
    Vec<pii> ans;
    int p = T;
    while (p != S) {
        used[p] = true;
        for (const auto& [id, pp, cost] : rg[p]) {
            USE(id);
            if (not used[pp] and ds[pp] + cost == ds[p]) {
                ans.push_back({pp, p});
                p = pp;
                break;
            }
        }
    }
    reverseAll(ans);
    out.ln(ds[T], ans.size());
    for (const auto& [u, v] : ans) {
        out.ln(u, v);
    }
    return 0;
}
