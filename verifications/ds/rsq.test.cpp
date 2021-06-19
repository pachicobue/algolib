#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../src/ds/rsq.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<i64>(N);
    const auto rsq = RSQ(as);
    for (int q : rep(Q)) {
        USE(q);
        const auto [l, r] = in.tup<int, int>();
        out.ln(rsq.suffixSum(l, r));
    }
}
