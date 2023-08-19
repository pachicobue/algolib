// verification-helper: PROBLEM https://yukicoder.me/problems/no/888
#include "number/divisors.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

int main()
{
    const auto N  = in.val<i64>();
    const auto ds = divisors(N);
    out.ln(mdSeqSum(ds));
    return 0;
}
