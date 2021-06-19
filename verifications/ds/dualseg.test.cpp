#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include "../../src/ds/dualseg.hpp"
#include "../../src/misc/fastio/scanner.hpp"
#include "../../src/misc/fastio/printer.hpp"

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
    auto seg = DualSeg<OpMonoid>(Vec<i64>(N));
    for (int i : rep(N)) {
        seg.set(i, (1_i64 << 31) - 1);
    }
    for (int q : rep(Q)) {
        USE(q);
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [s, t, x] = in.tup<int, int, i64>();
            seg.act(s, t + 1, x);
        } else {
            const auto i = in.val<int>();
            out.ln(seg.get(i));
        }
    }
    if (N < 10) { std::cerr << seg << std::endl; }
    return 0;
}
