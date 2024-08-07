// verification-helper: PROBLEM https://judge.yosupo.jp/problem/lca
#include "graph/tree/level_ancestor.hpp"
#include "graph/graph.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

int main() {
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
