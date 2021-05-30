#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../../src/data_structure/swag.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    using Func = std::pair<mint, mint>;
    const auto Q = in.val<int>();
    struct SemiGroup
    {
        using T = Func;
        T operator()(const T& f2, const T& f1) const
        {
            return T{f1.first * f2.first, f1.first * f2.second + f1.second};
        }
    };

    auto deque = SWAG<SemiGroup>{};
    for (int q : rep(Q)) {
        USE(q);
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
