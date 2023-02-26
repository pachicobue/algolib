#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../../src/data_structure/sparse_table/disjoint_sparse_table.hpp"
#include "../../../src/utility/printer.hpp"
#include "../../../src/utility/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<u64>(N);
    struct SemiGroup
    {
        using T = u64;
        T operator()(T x1, T x2) const { return std::min(x1, x2); }
    };
    const auto rmq = DisjointSparseTable<SemiGroup>(as);
    LOOP (Q) {
        const auto [l, r] = in.tup<int, int>();
        out.ln(rmq.fold(l, r));
    }
}
