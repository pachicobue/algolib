// verification-helper: UNITTEST
#include <cassert>
#include <cmath>
#include "algorithm/two_sat.hpp"
#include "internal.hpp"
#include "utility/rng.hpp"
void test() {
    const auto N = rng.val(10, 1000);
    TwoSat twoSat{N};
    const auto M = rng.val(10, 1000);
    Vec<bool> sol(N + 1);
    for (int i : rep(N + 1)) {
        sol[i] = rng.val(0, 1);
    }
    Vec<Pair<int, int>> clauses;
    LOOP (M) {
        const auto x = rng.val(1, N);
        const auto xnot = rng.val(0, 1);
        const auto y = rng.val(1, N);
        const auto ynot = rng.val(0, 1);
        if (((xnot ? 1 - sol[x] : sol[x]) or (ynot ? 1 - sol[y] : sol[y])) == false) {
            continue;
        }
        const int xi = x * (xnot ? -1 : 1);
        const int yi = y * (ynot ? -1 : 1);
        clauses.push_back({xi, yi});
        twoSat.addClause(xi, yi);
    }
    auto check = [&](const Vec<bool>& sol) {
        for (const auto& [xi, yi] : clauses) {
            const auto x = std::abs(xi);
            const auto xnot = xi < 0;
            const auto y = std::abs(yi);
            const auto ynot = yi < 0;
            if (((xnot ? 1 - sol[x] : sol[x]) or (ynot ? 1 - sol[y] : sol[y])) == false) {
                return false;
            }
        }
        return true;
    };
    const auto K = 100;
    const auto Ans = twoSat.enumSolutions(K);
    assert((int)Ans.size() <= K);
    Set<Vec<bool>> st;
    for (const auto& sol : Ans) {
        assert(st.count(sol) == 0);
        assert(check(sol));
    }
}
int main() {
    test();
    return 0;
}
