// verification-helper: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite
#include "data_structure/segment_tree/segtree.hpp"
#include "internal.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    using mint = modint_998244353;
    using T = Pair<mint, mint>;

    const auto [N, Q] = in.tup<int, int>();
    Vec<T> fs(N);
    for (int i : rep(N)) {
        std::tie(fs[i].first, fs[i].second) = in.tup<mint, mint>();
    }
    auto seg = SegTree<T, FConst(T{1, 0}), [](const T& f2, const T& f1) -> T {
        return {f1.first * f2.first, f1.first * f2.second + f1.second};
    }>(fs);
    LOOP (Q) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [p, c, d] = in.tup<int, mint, mint>();
            seg.set(p, T{c, d});
        } else {
            const auto [l, r, x] = in.tup<int, int, mint>();
            const auto [a, b] = seg.fold(l, r);
            out.ln((a * x + b).val());
        }
    }
    return 0;
}
