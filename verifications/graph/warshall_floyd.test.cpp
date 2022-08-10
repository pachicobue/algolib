#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "../../src/graph/warshall_floyd.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"

int main()
{
    const auto [V, E] = in.tup<int, int>();
    Graph<i64> g(V);
    LOOP (E) {
        const auto [u, v, c] = in.tup<int, int, i64>();
        g.addEdge(u, v, c);
    }
    const auto dss = warshallFloyd(g);
    for (int i : rep(V)) {
        if (dss[i][i] < 0) { return out.ln("NEGATIVE CYCLE"); }
    }
    for (int i : rep(V)) {
        for (int j : rep(V)) {
            out(j == 0 ? "" : " ");
            if (dss[i][j] >= INF<i64>) {
                out("INF");
            } else {
                out(dss[i][j]);
            }
        }
        out("\n");
    }

    return 0;
}
