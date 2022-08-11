#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../src/graph/level_ancestor.hpp"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"

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
