#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"
#include "../../src/math/modint.hpp"
#include "../../src/math/multiplicative_sum.hpp"
#include "../../src/util/fastio/printer.hpp"
#include "../../src/util/fastio/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto N = in.val<u64>();
    if (N <= 2) { return out.ln(N); }
    auto f = [&](const u64 v, const u64 p, u32) { return v / p * (p - 1); };
    const auto ms = MultiplicativeSum<mint, decltype(f)>(N, f, {mint(-1), mint(1), mint(0)});
    out.ln(ms.get(N).val());
    return 0;
}
