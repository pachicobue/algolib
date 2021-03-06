#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include "../../src/flow/max_flow.hpp"
#include "../../src/misc/printer.hpp"
#include "../../src/misc/scanner.hpp"
int main()
{
    const auto [V, E] = in.tup<int, int>();
    MaxFlow<int> flow(V);
    for (int i : rep(E)) {
        USE(i);
        const auto [u, v, c] = in.tup<int, int, int>();
        flow.addEdge(u, v, c);
    }
    out.ln(flow.maxFlow(0, V - 1));
    return 0;
}
