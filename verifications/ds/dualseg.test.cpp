#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include "../../src/ds/dualseg.hpp"
#include "../../src/misc/scanner.hpp"
#include "../../src/misc/printer.hpp"

int main()
{
    struct OpMonoid
    {
        using F = i64;
        static F id()
        {
            return INF<F>;
        }
        F operator()(const F& f1, const F& f2) const
        {
            return f1 != id() ? f1 : f2;
        }
    };
    const auto [N, Q] = in.tup<int, int>();
    auto seg = DualSegTree<OpMonoid>(Vec<i64>(N));
    for (int i : rep(N)) {
        seg.set(i, (1_i64 << 31) - 1);
    }
    LOOP (Q) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [s, t, x] = in.tup<int, int, i64>();
            seg.act(s, t + 1, x);
        } else {
            const auto i = in.val<int>();
            out.ln(seg.get(i));
        }
    }
    return 0;
}
