// verification-helper: PROBLEM https://judge.yosupo.jp/problem/polynomial_taylor_shift
#include "polynomial/polynomial.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    using mint        = modint_998244353;
    const auto [N, c] = in.tup<int, mint>();
    Polynomial<mint> as{in.vec<mint>(N)};
    const auto bs = as.taylorShift(c);
    out.ln(bs.asVec());
    return 0;
}
