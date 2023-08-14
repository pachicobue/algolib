// verification-helper: PROBLEM https://judge.yosupo.jp/problem/kth_root_mod
#include "number/mod_nthroot.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    const int T = in.val<int>();
    LOOP (T) {
        const auto [K, Y, P] = in.tup<i64, i64, u64>();
        if (P == 2) {
            out.ln(Y == 1 ? 1 : K == 0 ? -1 : 0);
            continue;
        }
        using mint = modint_dynamic<0>;
        mint::setMod(P);
        const auto ans = modNthRoot<mint>(mint{Y}, K);
        if (ans) {
            out.ln(ans.value());
        } else {
            out.ln(-1);
        }
    }
    return 0;
}
