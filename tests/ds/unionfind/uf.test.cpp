#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../../src/ds/unionfind/uf.hpp"
#include "../../../src/util/fastio/printer.hpp"
#include "../../../src/util/fastio/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    auto uf = UnionFindTree(N);
    LOOP (Q) {
        const auto [t, u, v] = in.tup<int, int, int>();
        if (t == 0) {
            uf.merge(u, v);
        } else {
            out.ln(uf.same(u, v));
        }
    }
}
