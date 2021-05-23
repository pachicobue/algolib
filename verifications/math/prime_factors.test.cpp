#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "math/prime_factors.hpp"
#include "misc/fastio/printer.hpp"
#include "misc/fastio/scanner.hpp"
int main()
{
    const auto Q = in.val<int>();
    for (int q : rep(Q)) {
        const auto a = in.val<u64>();
        const auto fs = primeFactors(a);
        std::vector<u64> ans;
        for (const auto& [p, e] : fs) {
            for (int i : rep(e)) {
                ans.push_back(p);
            }
        }
        out.ln(ans.size(), ans);
    }
    return 0;
}
