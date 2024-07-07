// verification-helper: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
#include "graph/bellman_ford.hpp"
#include "graph/graph.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

int main() {
    const auto [V, E, r] = in.tup<int, int, int>();
    Graph<int> g(V);
    LOOP (E) {
        const auto [u, v, c] = in.tup<int, int, int>();
        g.addEdge(u, v, c);
    }
    const auto ds = bellmanFord(g, r);
    for (int i : rep(V)) {
        if (ds[i] <= -INF<int>) { return out.ln("NEGATIVE CYCLE"); }
    }
    for (int i : rep(V)) {
        if (ds[i] >= INF<int>) {
            out.ln("INF");
        } else {
            out.ln(ds[i]);
        }
    }
    return 0;
}
