#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../../src/data_structure/segtree.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    using Func = Pair<mint, mint>;
    struct Monoid
    {
        using T = Func;
        static const T e()
        {
            return T{1, 0};
        }
        T operator()(const T& f2, const T& f1) const
        {
            return T{f1.first * f2.first, f1.first * f2.second + f1.second};
        }
    };

    const auto [N, Q] = in.tup<int, int>();
    Vec<Func> fs(N);
    for (int i : rep(N)) {
        std::tie(fs[i].first, fs[i].second) = in.tup<mint, mint>();
    }
    auto seg = SegTree<Monoid>(fs);
    for (int q : rep(Q)) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [p, c, d] = in.tup<int, mint, mint>();
            seg.set(p, Func{c, d});
        } else {
            const auto [l, r, x] = in.tup<int, int, mint>();
            const auto [a, b] = seg.fold(l, r);
            out.ln((a * x + b).val());
        }
    }
    return 0;
}
