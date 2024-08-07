// verification-helper: PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum
#include "data_structure/fenwick_tree/fenwick_tree.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<u64>(N);
    auto fenwick = FenwickTree(as);
    LOOP (Q) {
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
