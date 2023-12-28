// verification-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_set_path_composite
#include "graph/tree/heavy_light_decomposition.hpp"
#include "data_structure/segment_tree/segtree.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    using mint        = modint_998244353;
    const auto [N, Q] = in.tup<int, int>();
    Graph g(N);
    using T = Pair<mint, mint>;

    Vec<mint> as(N), bs(N);
    for (int i : rep(N)) { std::tie(as[i], bs[i]) = in.tup<mint, mint>(); }
    LOOP (N - 1) {
        const auto [u, v] = in.tup<int, int>();
        g.addEdge(u, v, true);
    }
    const HeavyLightDecomposition hld{g};
    Vec<T> vs(N);
    for (int i : rep(N)) { vs[hld.pos(i)] = T{as[i], bs[i]}; }

    auto merge  = [](const T& x2, const T& x1) { return T{x1.first * x2.first, x1.first * x2.second + x1.second}; };
    auto Rmerge = [](const T& x1, const T& x2) { return T{x1.first * x2.first, x1.first * x2.second + x1.second}; };
    auto seg    = SegTree<T, []() { return T{1, 0}; }, merge>(vs);
    auto rseg   = SegTree<T, []() { return T{1, 0}; }, Rmerge>(vs);
    LOOP (Q) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [p, c, d] = in.tup<int, mint, mint>();
            seg.set(hld.pos(p), {c, d}), rseg.set(hld.pos(p), {c, d});
        } else {
            const auto [u, v, x] = in.tup<int, int, mint>();
            const auto ps        = hld.path(u, v);
            T X{1, 0};
            for (const auto& [a, b] : ps) { X = merge(X, a <= b ? seg.fold(a, b + 1) : rseg.fold(b, a + 1)); }
            out.ln((X.first * x + X.second).val());
        }
    }
    return 0;
}
