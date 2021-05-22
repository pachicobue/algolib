#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include "graph/bcc.hpp"
#include "misc/fastio/printer.hpp"
#include "misc/fastio/scanner.hpp"
int main()
{
    const auto [N, M] = in.tup<int, int>();
    Graph g(N);
    for (int i : rep(M)) {
        const auto [a, b] = in.tup<int, int>();
        g.addEdge(a, b, true);
    }
    const auto bcc = BCC(g);
    const int C    = bcc.cnum();
    Vec<Vec<int>> cvs(C);
    for (int i : rep(N)) {
        cvs[bcc[i]].push_back(i);
    }
    out.ln(C);
    for (int c : rep(C)) {
        out.ln(cvs[c].size(), cvs[c]);
    }
    return 0;
}
