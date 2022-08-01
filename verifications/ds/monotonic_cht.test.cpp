#define PROBLEM "https://yukicoder.me/problems/no/409"
#include "../../src/ds/monotonic_cht.hpp"
#include "../../src/misc/printer.hpp"
#include "../../src/misc/scanner.hpp"
int main()
{
    const auto [N, A, B, W] = in.tup<int, i64, i64, i64>();
    auto ds = in.vec<i64>(N);
    ds.push_back(0);
    ds = Vec<i64>{0} + ds;
    Vec<i64> dp(N + 2, INF<i64>);
    dp[0] = 0;
    MonotonicCHT<i64> cht;
    for (int i : rep(N + 2)) {
        if (i != 0) {
            const auto [a, b] = cht.minLine(i);
            dp[i] = ds[i] * 2 - A * (i - 1) * 2 + B * i * i + (a * i + b);
        }
        cht.addLine(-B * (2 * i + 1), dp[i] + A * 2 * i + B * (i + 1) * i);
    }
    out.ln(W + dp.back() / 2);

    return 0;
}
