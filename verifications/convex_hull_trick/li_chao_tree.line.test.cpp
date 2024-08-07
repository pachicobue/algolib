// verification-helper: PROBLEM https://judge.yosupo.jp/problem/line_add_get_min
#include "convex_hull_trick/li_chao_tree.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
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
            const auto l = cht.minLine(p);
            out.ln(l.value().first * p + l.value().second);
        }
    }
}
