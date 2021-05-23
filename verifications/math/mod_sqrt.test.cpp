#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include "math/mod_sqrt.hpp"
#include "math/modint.hpp"
#include "misc/fastio/printer.hpp"
#include "misc/fastio/scanner.hpp"
using mint = modint_dynamic<0>;
int main()
{
    const int T = in.val<int>();
    for (int t : rep(T)) {
        const auto [Y, P] = in.tup<uint, uint>();
        mint::setMod(P);
        const mint ans = modsqrt(mint{Y});
        if (ans * ans == Y) {
            out.ln(ans.val());
        } else {
            out.ln(-1);
        }
    }
    return 0;
}
