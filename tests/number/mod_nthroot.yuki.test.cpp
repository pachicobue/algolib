#define IGNORE  // スペシャルジャッジなので...
#define PROBLEM "https://yukicoder.me/problems/no/981"
#include "../../src/number/mod_nthroot.hpp"
#include "../../src/utility/modint64.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"
using mint = modint64_dynamic<0>;
int main()
{
    const int T = in.val<int>();
    LOOP (T) {
        const auto [P, K, Y] = in.tup<u64, u64, u64>();
        if (P == 2) {
            out.ln(Y == 1 ? 1 : K == 0 ? -1 : 0);
            continue;
        }
        mint::setMod(P);
        const mint ans = modNthRoot(mint(Y), K);
        if (ans.pow(K) == Y) {
            out.ln(ans.val());
        } else {
            out.ln(-1);
        }
    }
    return 0;
}
