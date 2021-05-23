#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include "../../../src/misc/common.hpp"
#include "../../../src/misc/printer.hpp"
#include "../../../src/misc/scanner.hpp"

constexpr i64 mod = 1000000007;

int main()
{
    const auto [m, n] = in.tup<i64, i64>();
    const i64 ans = modPower(m, n, mod);
    out.ln(ans);
    return 0;
}
