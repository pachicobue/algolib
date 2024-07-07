// verification-helper: PROBLEM https://judge.yosupo.jp/problem/counting_primes
#include "internal.hpp"
#include "number/prime_power_sum.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    const auto N = in.val<u64>();
    if (N <= 2) { return out.ln(N == 2 ? 1 : 0); }
    const auto powsum = PrimePowerSum<u64>(N);
    out.ln(powsum.get(0, N));
    return 0;
}
