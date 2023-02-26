#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"
#include "../../src/set_power_series/xor_convolution.hpp"
#include "../../src/utility/modint.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto n = in.val<int>();
    const int N = 1 << n;
    const auto as = in.vec<mint>(N);
    const auto bs = in.vec<mint>(N);
    const auto cs = xorConvolute(as, bs);
    std::vector<int> ans(cs.size());
    for (int i : rep(N)) { ans[i] = cs[i].val(); }
    out.ln(ans);
    return 0;
}
