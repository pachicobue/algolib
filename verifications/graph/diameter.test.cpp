#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "misc/fastio/printer.hpp"
#include "misc/fastio/scanner.hpp"
#include "graph/diameter.hpp"
int main()
{
    const auto N = in.val<int>();
    Graph<i64> g(N);
    for (int i = 0; i < N - 1; i++) {
        const auto [u, v, c] = in.tup<int, int, i64>();
        g.addEdge(u, v, c, true);
    }
    auto es = diameter(g);
    i64 X = 0;
    Vec<int> vs{es[0].from};
    for (const auto& e : es) {
        X += e.cost;
        vs.push_back(e.to);
    }
    out.ln(X, vs.size());
    out.ln(vs);
    return 0;
}