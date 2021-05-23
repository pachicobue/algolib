#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include "../../src/graph/bcc.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    const auto [N, M] = in.tup<int, int>();
    Graph g(N);
    for (int i : rep(M)) {
        USE(i);
        const auto [a, b] = in.tup<int, int>();
        g.addEdge(a, b, true);
    }
    const auto bcc = BCC(g);
    const int C = bcc.cnum();
    const auto cvs = bcc.groups();
    out.ln(C);
    for (int c : rep(C)) {
        out.ln(cvs[c].size(), cvs[c]);
    }
    return 0;
}
