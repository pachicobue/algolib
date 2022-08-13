#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../../../src/ds/swag/deque.hpp"
#include "../../../src/util/modint.hpp"
#include "../../../src/util/fastio/printer.hpp"
#include "../../../src/util/fastio/scanner.hpp"
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

    auto deque = SwagDeque<SemiGroup>{};
    LOOP (Q) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [a, b] = in.tup<mint, mint>();
            deque.pushBack(Func{a, b});
        } else if (t == 1) {
            deque.popFront();
        } else {
            const auto x = in.val<mint>();
            if (deque.empty()) {
                out.ln(x.val());
            } else {
                const auto [a, b] = deque.foldAll();
                out.ln((a * x + b).val());
            }
        }
    }
    return 0;
}
