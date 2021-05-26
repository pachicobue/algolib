#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../../src/data_structure/fenwick.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<u64>(N);
    auto fenwick = Fenwick(as);
    for (int q : rep(Q)) {
        USE(q);
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [p, x] = in.tup<int, u64>();
            fenwick.add(p, x);
        } else {
            const auto [l, r] = in.tup<int, int>();
            out.ln(fenwick.sum(l, r));
        }
    }
    return 0;
}
