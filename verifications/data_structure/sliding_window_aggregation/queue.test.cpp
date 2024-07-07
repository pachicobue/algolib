// verification-helper: PROBLEM https://judge.yosupo.jp/problem/queue_operate_all_composite
#include "data_structure/sliding_window_aggregation/queue.hpp"
#include <utility>
#include "internal.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    using mint = modint_998244353;
    using T = std::pair<mint, mint>;
    const auto Q = in.val<int>();
    auto queue = SwagQueue<T, FConst(T{1, 0}), [](const T& x1, const T& x2) {
        return T{x2.first * x1.first, x2.first * x1.second + x2.second};
    }>{};
    LOOP (Q) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [a, b] = in.tup<mint, mint>();
            queue.pushBack(T{a, b});
        } else if (t == 1) {
            queue.popFront();
        } else {
            const auto x = in.val<mint>();
            if (queue.empty()) {
                out.ln(x.val());
            } else {
                const auto [a, b] = queue.foldAll();
                out.ln((a * x + b).val());
            }
        }
    }
    return 0;
}
