// verification-helper: PROBLEM https://judge.yosupo.jp/problem/staticrmq
#include "data_structure/sparse_table/disjoint_sparse_table.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    const auto as     = in.vec<int>(N);
    const auto rmq    = DisjointSparseTable<int, FConst(INF<int>), FMin<int>{}>(as);
    LOOP (Q) {
        const auto [l, r] = in.tup<int, int>();
        out.ln(rmq.fold(l, r));
    }
}
