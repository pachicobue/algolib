#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../../src/graph/tree/la.hpp"
#include "../../../src/util/fastio/printer.hpp"
#include "../../../src/util/fastio/scanner.hpp"

int main()
{
    const auto [N, Q] = in.tup<int, int>();
    Graph g(N);
    for (int i : irange(1, N, 1)) {
        const int p = in.val<int>();
        g.addEdge(p, i, true);
    }
    LevelAncestor la(g);
    LOOP (Q) {
        const auto [u, v] = in.tup<int, int>();
        out.ln(la.lca(u, v));
    }

    return 0;
}
