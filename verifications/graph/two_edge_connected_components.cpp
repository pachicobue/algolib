// verification-helper: PROBLEM https://judge.yosupo.jp/problem/two_edge_connected_components
#include "graph/two_edge_connected_components.hpp"
#include "graph/graph.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    const auto [N, M] = in.tup<int, int>();
    Graph g(N);
    LOOP (M) {
        const auto [a, b] = in.tup<int, int>();
        g.addEdge(a, b, true);
    }
    const auto two_ecc = TwoEdgeConnectedComponent(g);
    const int C = two_ecc.cnum();
    const auto cvs = two_ecc.groups();
    out.ln(C);
    for (int c : rep(C)) { out.ln(cvs[c].size(), cvs[c]); }
    return 0;
}
