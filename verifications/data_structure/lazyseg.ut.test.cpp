#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include "../../src/data_structure/lazyseg.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"

int main()
{
    struct MergeMonoid
    {
        using T = i64;
        static T e()
        {
            return INF<T>;
        }
        T operator()(const T& x1, const T& x2) const
        {
            return std::min(x1, x2);
        }
    };
    struct OpMonoid
    {
        using F = i64;
        static F id()
        {
            return 0;
        }
        F operator()(const F& f1, const F& f2) const
        {
            return f1 + f2;
        }
    };
    struct Act
    {
        using T = MergeMonoid::T;
        using F = OpMonoid::F;
        T operator()(const F& f, const T& x) const
        {
            return f + x;
        }
    };

    const auto [N, Q] = in.tup<int, int>();
    auto seg = LazySeg<MergeMonoid, OpMonoid, Act>(Vec<i64>(N, 1));
    for (int i : rep(N)) {
        seg.set(i, 0);
    }
    for (int q : rep(Q)) {
        USE(q);
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [s, t, x] = in.tup<int, int, i64>();
            seg.act(s, t + 1, x);
        } else {
            const auto [s, t] = in.tup<int, int>();
            if (t - s == 0) {
                out.ln(seg.get(s));
            } else {
                out.ln(seg.fold(s, t + 1));
            }
        }
    }
    if (N < 10) { std::cerr << seg << std::endl; }
    return 0;
}
