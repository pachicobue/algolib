#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "data_structure/dsu.hpp"
#include "misc/fastio/printer.hpp"
#include "misc/fastio/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    auto uf = DSU(N);
    for (int q = 0; q < Q; q++) {
        const auto [t, u, v] = in.tup<int, int, int>();
        if (t == 0) {
            uf.merge(u, v);
        } else {
            out.ln((int)(uf.root(u) == uf.root(v)));
        }
    }
}
