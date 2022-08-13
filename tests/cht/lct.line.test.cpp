#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../../src/cht/lct.hpp"
#include "../../src/util/fastio/printer.hpp"
#include "../../src/util/fastio/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    auto cht = LiChaoTree<i64>(-TEN<i64>(9), TEN<i64>(9));
    LOOP (N) {
        const auto [a, b] = in.tup<i64, i64>();
        cht.addLine({a, b});
    }
    LOOP (Q) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [a, b] = in.tup<i64, i64>();
            cht.addLine({a, b});
        } else {
            const auto p = in.val<i64>();
            const auto [ok, l] = cht.minLine(p);
            out.ln(l.first * p + l.second);
        }
    }
}
