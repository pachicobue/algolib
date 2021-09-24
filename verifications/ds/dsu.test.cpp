#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../src/ds/dsu.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    auto uf = DisjointSetUnion(N);
    for (int q : rep(Q)) {
        USE(q);
        const auto [t, u, v] = in.tup<int, int, int>();
        if (t == 0) {
            uf.merge(u, v);
        } else {
            out.ln(uf.leader(u) == uf.leader(v));
        }
    }
}
