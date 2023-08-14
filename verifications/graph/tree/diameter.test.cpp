// verification-helper: PROBLEM https://judge.yosupo.jp/problem/tree_diameter
#include "graph/tree/diameter.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    const auto N = in.val<int>();
    Graph<i64> g(N);
    LOOP (N - 1) {
        const auto [u, v, c] = in.tup<int, int, i64>();
        g.addEdge(u, v, c, true);
    }
    const auto [D, vs] = diameter(g);
    out.ln(D, vs.size());
    out.ln(vs);
    return 0;
}
