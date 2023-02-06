#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../../../src/data_structure/sliding_window_aggregation/queue.hpp"
#include "../../../src/util/modint.hpp"
#include "../../../src/util/printer.hpp"
#include "../../../src/util/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    using Func = std::pair<mint, mint>;
    const auto Q = in.val<int>();
    struct SemiGroup
    {
        using T = Func;
        // f2 \circ f1 なので注意
        T operator()(const T& f1, const T& f2) const
        {
            return T{f2.first * f1.first, f2.first * f1.second + f2.second};
        }
    };

    auto queue = SwagQueue<SemiGroup>{};
    LOOP (Q) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [a, b] = in.tup<mint, mint>();
            queue.pushBack(Func{a, b});
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
