#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../../src/ds/sparsetable/rmq.hpp"
#include "../../../src/util/printer.hpp"
#include "../../../src/util/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<u32>(N);
    struct Ord
    {
        using T = u32;
        bool operator()(const T& x1, const T& x2) const { return x1 < x2; }
    };
    const auto rmq = StaticRMQ<Ord>(as);
    LOOP (Q) {
        const auto [l, r] = in.tup<int, int>();
        out.ln(rmq.fold(l, r));
    }
}