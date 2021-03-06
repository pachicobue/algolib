#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
#include "../../src/graph/diameter.hpp"
int main()
{
    const auto N = in.val<int>();
    Graph<i64> g(N);
    for (int i : rep(N - 1)) {
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
