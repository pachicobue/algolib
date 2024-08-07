// verification-helper: PROBLEM https://judge.yosupo.jp/problem/unionfind
#include "data_structure/union_find_tree/union_find_tree.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    const auto [N, Q] = in.tup<int, int>();
    auto uf = UnionFindTree(N);
    LOOP (Q) {
        const auto [t, u, v] = in.tup<int, int, int>();
        if (t == 0) {
            uf.unite(u, v);
        } else {
            out.ln(uf.same(u, v));
        }
    }
}
