#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "graph/scc.hpp"
#include "graph/top_sort.hpp"
#include "misc/fastio/printer.hpp"
#include "misc/fastio/scanner.hpp"
int main()
{
    const auto [N, M] = in.tup<int, int>();
    Graph g(N);
    for (int i = 0; i < M; i++) {
        const auto [a, b] = in.tup<int, int>();
        g.addEdge(a, b);
    }
    const auto scc = sc_comp(g);
    const int C = scc.cnum();
    Graph dag(C);
    for (int u : rep(N)) {
        const int uc = scc[u];
        for (const int v : g[u]) {
            const int vc = scc[v];
            if (uc == vc) { continue; }
            dag.addEdge(uc, vc);
        }
    }
    Vec<Vec<int>> cvs(C);
    for (int i : rep(N)) {
        cvs[scc[i]].push_back(i);
    }
    const auto [flag, cs] = topSort(dag);
    assert(flag);
    out.ln(C);
    for (int c : cs) {
        out.ln(cvs[c].size(), cvs[c]);
    }
    return 0;
}
