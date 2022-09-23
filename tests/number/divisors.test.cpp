#define PROBLEM "https://yukicoder.me/problems/no/888"
#include "../../src/number/divisors.hpp"
#include "../../src/util/fastio/printer.hpp"
#include "../../src/util/fastio/scanner.hpp"

int main()
{
    const auto N = in.val<i64>();
    const auto ds = divisors(N);
    out.ln(sumAll<i64>(ds));
    return 0;
}