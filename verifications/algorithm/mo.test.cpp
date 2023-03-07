// verification-helper: PROBLEM https://judge.yosupo.jp/problem/static_range_inversions_query
#include "data_structure/fenwick_tree/fenwick_tree.hpp"
#include "algorithm/mo.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
#include "utility/zipper.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    auto as = in.vec<u32>(N);
    Zipper<u32> zipper(as);
    for (auto& a : as) { a = zipper.zip(a); }
    const int L = zipper.size();
    FenwickTree<int> bit(Vec<int>(L, 0));
    u64 inv = 0;
    auto left = [&](int x, int) {  // (x,y)->(x-1,y)
        const int a = as[x - 1];
        inv += bit.sum(0, a);
        bit.add(a, 1);
    };
    auto right = [&](int x, int) {  // (x,y)->(x+1,y)
        const int a = as[x];
        inv -= bit.sum(0, a);
        bit.add(a, -1);
    };
    auto up = [&](int, int y) {  // (x,y)->(x,y-1)
        const int a = as[y - 1];
        inv -= bit.sum(a + 1, L);
        bit.add(a, -1);
    };
    auto down = [&](int, int y) {  // (x,y)->(x,y+1)
        const int a = as[y];
        inv += bit.sum(a + 1, L);
        bit.add(a, 1);
    };

    Vec<int> ls(Q), rs(Q);
    for (int q : rep(Q)) { std::tie(ls[q], rs[q]) = in.tup<int, int>(); }
    Mo mo(ls, rs);
    Vec<u64> ans(Q);
    mo.solve(right, left, down, up, [&](int q) { ans[q] = inv; });
    out.ln(ans);

    return 0;
}
