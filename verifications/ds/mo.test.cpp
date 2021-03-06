#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "../../src/ds/fenwick.hpp"
#include "../../src/ds/mo.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
#include "../../src/misc/zipper.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    auto as = in.vec<u32>(N);
    Zipper<u32> zipper(as);
    for (auto& a : as) {
        a = zipper.zip(a);
    }
    const int L = zipper.size();
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
