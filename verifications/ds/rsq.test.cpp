#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../src/ds/rsq.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<i64>(N);
    const auto rsq = RSQ(as);
    LOOP (Q) {
        const auto [l, r] = in.tup<int, int>();
        out.ln(rsq.suffixSum(l, r));
    }
}
