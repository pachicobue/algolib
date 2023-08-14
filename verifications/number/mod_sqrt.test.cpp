// verification-helper: PROBLEM https://judge.yosupo.jp/problem/sqrt_mod
#include "number/mod_sqrt.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    const int T = in.val<int>();
    LOOP (T) {
        const auto [Y, P] = in.tup<i64, u64>();
        using mint        = modint_dynamic<0>;
        mint::setMod(P);
        const auto ans = modSqrt(mint{Y});
        if (ans) {
            out.ln(ans.value());
        } else {
            out.ln(-1);
        }
    }
    return 0;
}
