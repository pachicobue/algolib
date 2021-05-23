#define PROBLEM "https://yukicoder.me/problems/no/981"
#include "math/modint.hpp"
#include "math/modint64.hpp"
#include "math/mod_nthroot.hpp"
#include "misc/fastio/printer.hpp"
#include "misc/fastio/scanner.hpp"
using mint = modint_dynamic<0>;
using mint64 = modint64_dynamic<0>;
int main()
{
    const int T = in.val<int>();
    for (int t : rep(T)) {
        const auto [P, K, A] = in.tup<u64, u64, u64>();
        if (P == 2) {
            out.ln(A == 1 ? 1 : K == 0 ? -1 : 0);
            continue;
        }
        if (P < (1ULL << 30)) {
            mint::setMod(P);
            const mint ans = modNthRoot(mint(A), K);
            if (ans.pow(K) == A) {
                out.ln(ans.val());
            } else {
                out.ln(-1);
            }
        } else {
            mint64::setMod(P);
            const mint64 ans = modNthRoot(mint64(A), K);
            if (ans.pow(K) == A) {
                out.ln(ans.val());
            } else {
                out.ln(-1);
            }
        }
    }
    return 0;
}
