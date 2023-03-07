// verification-helper: PROBLEM https://judge.yosupo.jp/problem/sqrt_mod
#include "number/mod_sqrt.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
using mint = modint_dynamic<0>;
int main()
{
    const int T = in.val<int>();
    LOOP (T) {
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