#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_mod"
#include "math/mod_nthroot.hpp"
#include "math/modint.hpp"
#include "misc/fastio/printer.hpp"
#include "misc/fastio/scanner.hpp"
using mint = modint_dynamic<0>;
int main()
{
    const int T = in.val<int>();
    for (int t : rep(T)) {
        const auto [K, Y, P] = in.tup<uint, uint, uint>();
        if (P == 2) {
            out.ln(Y == 1 ? 1 : K == 0 ? -1 : 0);
            continue;
        }
        mint::setMod(P);
        const mint ans = modNthRoot(mint{Y}, K);
        if (ans.pow(K) == Y) {
            out.ln(ans.val());
        } else {
            out.ln(-1);
        }
    }
    return 0;
}
