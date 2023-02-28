// verification-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_set_path_composite
#include "graph/tree/heavy_light_decomposition.hpp"
#include "data_structure/segment_tree/segtree.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto [N, Q] = in.tup<int, int>();
    Graph g(N);
    using Func = Pair<mint, mint>;
    struct Monoid
    {
        using T = Func;
        static const T e() { return T{1, 0}; }
        T operator()(const T& f2, const T& f1) const
        {
            return T{f1.first * f2.first, f1.first * f2.second + f1.second};
        }
    };
    struct RMonoid
    {
        using T = Func;
        static const T e() { return T{1, 0}; }
        T operator()(const T& f1, const T& f2) const
        {
            return T{f1.first * f2.first, f1.first * f2.second + f1.second};
        }
    };

    Vec<mint> as(N), bs(N);
    for (int i : rep(N)) { std::tie(as[i], bs[i]) = in.tup<mint, mint>(); }
    LOOP (N - 1) {
        const auto [u, v] = in.tup<int, int>();
        g.addEdge(u, v, true);
    }
    const HeavyLightDecomposition hld{g};
    Vec<Func> vs(N);
    for (int i : rep(N)) { vs[hld.pos(i)] = Func{as[i], bs[i]}; }
    auto seg = SegTree<Monoid>(vs);
    auto rseg = SegTree<RMonoid>(vs);
    LOOP (Q) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [p, c, d] = in.tup<int, mint, mint>();
            seg.set(hld.pos(p), {c, d}), rseg.set(hld.pos(p), {c, d});
        } else {
            const auto [u, v, x] = in.tup<int, int, mint>();
            const auto ps = hld.path(u, v);
            Func f{1, 0};
            for (const auto& [a, b] : ps) {
                f = Monoid{}(f, a <= b ? seg.fold(a, b + 1) : rseg.fold(b, a + 1));
            }
            out.ln((f.first * x + f.second).val());
        }
    }
    return 0;
}
