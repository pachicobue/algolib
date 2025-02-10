// verification-helper: PROBLEM https://judge.yosupo.jp/problem/inv_of_formal_power_series
#include "polynomial/polynomial.hpp"
#include "internal.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    using mint = modint_998244353;
    const auto N = in.val<int>();
    Polynomial<mint> as{in.vec<mint>(N)};
    const auto bs = as.inv(N);
    Vec<mint> ans(N);
    for (int i : rep(N)) {
        ans[i] = bs.at(i);
    }
    out.ln(ans);
    return 0;
}
