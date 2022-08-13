#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "../../../src/combi/flow/max_flow.hpp"
#include "../../../src/util/fastio/printer.hpp"
#include "../../../src/util/fastio/scanner.hpp"
int main()
{
    const auto [L, R, M] = in.tup<int, int, int>();
    MaxFlow<int> flow(L + R + 2);
    const int S = L + R, T = L + R + 1;
    LOOP (M) {
        const auto [u, v] = in.tup<int, int>();
        flow.addEdge(u, v + L, 1);
    }
    for (int i : rep(L)) { flow.addEdge(S, i, 1); }
    for (int i : rep(R)) { flow.addEdge(i + L, T, 1); }
    const int K = flow.maxFlow(S, T);
    out.ln(K);
    for (int i : rep(L)) {
        for (const auto& e : flow[i]) {
            if (e.flow == 1) { out.ln(i, e.to - L); }
        }
    }
    return 0;
}
