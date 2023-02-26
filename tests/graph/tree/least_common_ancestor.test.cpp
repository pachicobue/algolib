#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../../src/graph/tree/least_common_ancestor.hpp"
#include "../../../src/utility/printer.hpp"
#include "../../../src/utility/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    Graph g(N);
    for (int i : irange(1, N)) {
        const int p = in.val<int>();
        g.addEdge(p, i, true);
    }
    const auto lca = LowestCommonAncestor(g, 0);
    LOOP (Q) {
        const auto [u, v] = in.tup<int, int>();
        const int l = lca(u, v);
        out.ln(l);
    }
    return 0;
}
