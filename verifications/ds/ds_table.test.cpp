#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../src/ds/static_rmq.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<u64>(N);
    struct SemiGroup
    {
        using T = u64;
        T operator()(T x1, T x2) const
        {
            return std::min(x1, x2);
        }
    };
    const auto rmq = DisjointSparseTable<SemiGroup>(as);
    for (int q : rep(Q)) {
        USE(q);
        const auto [l, r] = in.tup<int, int>();
        out.ln(rmq.fold(l, r));
    }
}
