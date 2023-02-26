#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"
#include "../../src/number/prime_power_sum.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"
int main()
{
    const auto N = in.val<u64>();
    if (N <= 2) { return out.ln(N == 2 ? 1 : 0); }
    const auto powsum = PrimePowerSum<u64>(N);
    out.ln(powsum.get(0, N));
    return 0;
}
