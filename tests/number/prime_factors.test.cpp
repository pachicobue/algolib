#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../../src/number/prime_factors.hpp"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"
int main()
{
    const auto Q = in.val<int>();
    LOOP (Q) {
        const auto a = in.val<u64>();
        const auto fs = primeFactors(a);
        std::vector<u64> ans;
        for (const auto& [p, e] : fs) {
            LOOP (e) { ans.push_back(p); }
        }
        out.ln(ans.size(), ans);
    }
    return 0;
}
