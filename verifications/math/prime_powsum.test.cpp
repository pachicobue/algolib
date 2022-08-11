#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"
#include "../../src/math/prime_powsum.hpp"
#include "../../src/util/fastio/printer.hpp"
#include "../../src/util/fastio/scanner.hpp"
int main()
{
    const auto N = in.val<u64>();
    if (N <= 2) { return out.ln(N == 2 ? 1 : 0); }
    const auto powsum = PrimePowSum<u64>(N);
    out.ln(powsum.get(0, N));
    return 0;
}
