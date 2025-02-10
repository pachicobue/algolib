// verification-helper: PROBLEM https://judge.yosupo.jp/problem/two_sat
#include "algorithm/two_sat.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    const auto [_, _, N, M] = in.tup<Str, Str, int, int>();
    TwoSat twoSat(N);
    LOOP (M) {
        const auto [x, y, _] = in.tup<int, int, int>();
        twoSat.addClause(x, y);
    }
    const auto sol = twoSat.findSolution();
    if (sol) {
        out.ln("s SATISFIABLE");
        auto ans = iotaVec(N, 1);
        for (int i : rep(N)) {
            if (not sol.value()[i + 1]) {
                ans[i] = -ans[i];
            }
        }
        out.ln("v", ans, "0");
    } else {
        out.ln("s UNSATISFIABLE");
    }
    return 0;
}
