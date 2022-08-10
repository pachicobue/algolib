#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include "../../../src/common/func_alias.hpp"

constexpr i64 mod = 1000000007;

int main()
{
    i64 m, n;
    std::cin >> m >> n;
    const i64 ans = modPower(m, n, mod);
    std::cout << ans << "\n";
    return 0;
}
