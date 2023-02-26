#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include "../../src/number/discrete_log.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"
#include "../../src/utility/modint.hpp"

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
