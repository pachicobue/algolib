#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../../src/graph/strongly_connected_components.hpp"
#include "../../src/graph/topological_sort.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"
int main()
{
    const auto [N, M] = in.tup<int, int>();
    Graph g(N);
    LOOP (M) {
        const auto [a, b] = in.tup<int, int>();
        g.addEdge(a, b);
    }
    const auto scc = StronglyConnectedComponents(g);
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
    for (int i : rep(N)) { cvs[scc[i]].push_back(i); }
    const auto [flag, cs] = topologicalSort(dag);
    assert(flag);
    out.ln(C);
    for (int c : cs) { out.ln(cvs[c].size(), cvs[c]); }
    return 0;
}
