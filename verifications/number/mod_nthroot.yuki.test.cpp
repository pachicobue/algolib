// verification-helper: IGNORE
// verification-helper: PROBLEM https://yukicoder.me/problems/no/981
#include "number/mod_nthroot.hpp"
#include "internal.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    const int T = in.val<int>();
    using mint = modint_dynamic<0>;
    LOOP (T) {
        const auto [P, K, Y] = in.tup<u64, i64, i64>();
        mint::setMod(P);
        const auto ans = modNthRoot(mint(Y), K);
        if (ans) {
            out.ln(ans.value());
        } else {
            out.ln(-1);
        }
    }
    return 0;
}
