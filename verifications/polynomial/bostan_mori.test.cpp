// verification-helper: PROBLEM https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
#include "polynomial/bostan_mori.hpp"
#include "internal.hpp"
#include "polynomial/polynomial.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    using mint = modint_998244353;
    const auto [D, K] = in.tup<int, i64>();
    const auto as = in.vec<mint>(D);
    const auto cs = seqConcatCopy(Vec<mint>{1}, in.vec<mint>(D));
    Polynomial<mint> f{as};
    Polynomial<mint> g{cs};
    for (int i : irange(1, D + 1)) {
        g[i] *= (-1);
    }
    (f *= g).shrink(D);
    const auto ans = bostanMori(f, g, K);
    out.ln(ans.val());
    return 0;
}
