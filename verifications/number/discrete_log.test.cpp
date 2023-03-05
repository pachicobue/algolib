// verification-helper: PROBLEM https://judge.yosupo.jp/problem/discrete_logarithm_mod
#include "number/discrete_log.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
#include "utility/modint.hpp"

int main()
{
    const auto T = in.val<int>();
    using mint = modint_dynamic<0>;
    LOOP (T) {
        const auto [x, y, M] = in.tup<u32, u32, u32>();
        mint::setMod(M);
        const mint X = x, Y = y;
        const i64 K = discreteLog(X, Y);
        out.ln(K);
    }
    return 0;
}
