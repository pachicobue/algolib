#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include "../../../src/ds/segtree/dual.hpp"
#include "../../../src/math/modint.hpp"
#include "../../../src/util/fastio/scanner.hpp"
#include "../../../src/util/fastio/printer.hpp"

using mint = modint_998244353;
struct OpMonoid
{
    using F = Pair<mint, mint>;
    static F id() { return {1, 0}; }
    F operator()(const F& f1, const F& f2) const
    {
        const auto& [a1, b1] = f1;
        const auto& [a2, b2] = f2;
        return {a1 * a2, a1 * b2 + b1};
    }
};

int main()
{
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<mint>(N);
    DualSegTree<OpMonoid> seg(N);
    LOOP (Q) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [l, r, b, c] = in.tup<int, int, mint, mint>();
            seg.act(l, r, {b, c});
        } else {
            const auto i = in.val<int>();
            const auto& [a, b] = seg.get(i);
            out.ln(a * as[i] + b);
        }
    }
    return 0;
}
