// verification-helper: PROBLEM https://judge.yosupo.jp/problem/range_affine_point_get
#include "data_structure/segment_tree/dual_segtree.hpp"
#include "utility/modint.hpp"
#include "utility/scanner.hpp"
#include "utility/printer.hpp"

int main()
{
    using mint = modint_998244353;
    using F    = Pair<mint, mint>;

    const auto [N, Q] = in.tup<int, int>();
    const auto as     = in.vec<mint>(N);

    DualSegTree<F,
                []() -> F {
                    return {1, 0};
                },
                [](const F& f1, const F& f2) -> F {
                    const auto& [a1, b1] = f1;
                    const auto& [a2, b2] = f2;
                    return {a1 * a2, a1 * b2 + b1};
                }>
        seg(N);
    LOOP (Q) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [l, r, b, c] = in.tup<int, int, mint, mint>();
            seg.act(l, r, {b, c});
        } else {
            const auto i       = in.val<int>();
            const auto& [a, b] = seg.get(i);
            out.ln(a * as[i] + b);
        }
    }
    return 0;
}
