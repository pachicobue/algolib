// verification-helper: PROBLEM https://judge.yosupo.jp/problem/range_affine_range_sum
#include "data_structure/segment_tree/lazy_segtree.hpp"
#include "internal.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

int main() {
    using mint = modint_998244353;
    using T = Pair<mint, mint>;
    using F = Pair<mint, mint>;

    const auto [N, Q] = in.tup<int, int>();
    Vec<Pair<mint, int>> as(N, {0, 1});
    for (int i : rep(N)) {
        as[i].first = in.val<mint>();
    }

    auto seg = LazySeg<T,
                       FConst(T{0, 0}),
                       [](const T& x1, const T& x2) -> T {
                           return {x1.first + x2.first, x1.second + x2.second};
                       },
                       F,
                       FConst(F{1, 0}),
                       [](const F& f1, const F& f2) -> F {
                           return {f1.first * f2.first, f1.first * f2.second + f1.second};
                       },
                       [](const F& f, const T& x) -> T {
                           return {f.first * x.first + f.second * x.second, x.second};
                       }>(as);
    LOOP (Q) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [l, r, b, c] = in.tup<int, int, mint, mint>();
            seg.act(l, r, F{b, c});
        } else {
            const auto [l, r] = in.tup<int, int>();
            out.ln(seg.fold(l, r).first.val());
        }
    }
    return 0;
}
