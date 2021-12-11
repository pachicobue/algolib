#define PROBLEM "https://yukicoder.me/problems/no/888"
#include "../../src/math/divisors.hpp"
#include "../../src/misc/printer.hpp"
#include "../../src/misc/scanner.hpp"

int main()
{
    const auto N = in.val<i64>();
    const auto ds = divisors(N);
    out.ln(sumAll<i64>(ds));
    return 0;
}
