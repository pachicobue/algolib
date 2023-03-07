// verification-helper: PROBLEM https://judge.yosupo.jp/problem/factorize
#include "number/prime_factors.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
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