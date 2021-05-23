#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "data_structure/fenwick.hpp"
#include "data_structure/mo.hpp"
#include "misc/fastio/printer.hpp"
#include "misc/fastio/scanner.hpp"
#include "misc/zipper.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    auto as = in.vec<u32>(N);
    Zipper<u32> zip(as);
    for (auto& a : as) {
        a = zip.zip(a);
    }
    const int L = zip.size();
    Fenwick<int> bit(Vec<int>(L, 0));
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
    for (int q : rep(Q)) {
        std::tie(ls[q], rs[q]) = in.tup<int, int>();
    }
    Mo<300> mo(ls, rs);
    Vec<u64> ans(Q);
    for (int q : rep(Q)) {
        const int it = mo.next(right, left, down, up);
        ans[it] = inv;
    }
    out.ln(ans);

    return 0;
}
