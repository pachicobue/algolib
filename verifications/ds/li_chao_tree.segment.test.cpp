#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "../../src/ds/li_chao_tree.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    auto cht = LiChaoTree<i64>(-TEN<i64>(9), TEN<i64>(9));
    for (int i : rep(N)) {
        USE(i);
        const auto [l, r, a, b] = in.tup<i64, i64, i64, i64>();
        cht.addSeg({a, b}, l, r);
    }
    for (int q : rep(Q)) {
        USE(q);
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [l, r, a, b] = in.tup<i64, i64, i64, i64>();
            cht.addSeg({a, b}, l, r);
        } else {
            const auto p = in.val<i64>();
            const auto [ok, l] = cht.minLine(p);
            if (ok) {
                out.ln(l.first * p + l.second);
            } else {
                out.ln(Str("INFINITY"));
            }
        }
    }
}
