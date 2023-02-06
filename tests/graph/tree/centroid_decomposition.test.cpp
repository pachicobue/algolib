#define PROBLEM "https://yukicoder.me/problems/no/1002"
#include "../../../src/graph/tree/centroid_decomposition.hpp"
#include "../../../src/util/nd_vec.hpp"
#include "../../../src/util/printer.hpp"
#include "../../../src/util/scanner.hpp"

int main()
{
    const auto [N, K] = in.tup<int, int>();
    Graph<int> g(N);
    LOOP (N - 1) {
        const auto [u, v, c] = in.tup<int, int, int>(1, 1, 1);
        g.addEdge(u, v, c, true);
    }
    CentroidDecomposition centros(g);
    const int cr = centros.center();
    const auto cg = centros.centers();
    Vec<bool> used(N, false);
    using P = Pair<int, int>;
    i64 ans = 0;

    auto f = [&](const Map<int, i64>& dp1,
                 const Map<P, i64>& dp2,
                 const Map<int, i64>& dp3,
                 const i64 one) -> i64 {
        i64 ans = 0;
        i64 dbl = 0;
        for (const auto& [k, n] : dp1) {
            ans += n * (dp3.at(k) - n);  // 1色x2色
            dbl += n * (one - n);        // 1色x1色
        }
        for (UNUSED const auto& [_, n] : dp2) {
            ans += n * (n - 1) / 2;  // 2色x2色
        }
        return ans + dbl / 2;
    };

    Fix([&](auto dfs, int c) -> void {
        used[c] = true;
        Map<int, i64> dp1;
        Map<P, i64> dp2;
        Map<int, i64> dp3;
        int one = 0;
        for (const auto& e : g[c]) {
            if (used[e.to]) { continue; }
            Map<int, i64> subdp1;
            Map<P, i64> subdp2;
            Map<int, i64> subdp3;
            i64 sone = 0;
            Fix([&](auto dfs, int u, int p, const P& ks) -> void {
                if (ks.second == INF<int>) {
                    dp1[ks.first]++;
                    dp3[ks.first]++;
                    subdp1[ks.first]++;
                    subdp3[ks.first]++;
                    sone++;
                    one++;
                } else {
                    ans++;
                    dp2[ks]++;
                    dp3[ks.first]++;
                    dp3[ks.second]++;
                    subdp2[ks]++;
                    subdp3[ks.first]++;
                    subdp3[ks.second]++;
                }
                for (const auto& e : g[u]) {
                    const int v = e.to;
                    if (v == p or used[v]) { continue; }
                    const int k = e.cost;
                    auto nks = ks;
                    if (ks.first == k or ks.second == k) {
                        ;
                    } else if (ks.second == INF<int>) {
                        nks.second = k;
                    } else {
                        continue;
                    }
                    if (nks.first > nks.second) { std::swap(nks.first, nks.second); }
                    dfs(v, u, nks);
                }
            })(e.to, c, P{e.cost, INF<int>});
            ans -= f(subdp1, subdp2, subdp3, sone);
        }
        ans += f(dp1, dp2, dp3, one);
        for (int nc : cg[c]) { dfs(nc); }
    })(cr);
    out.ln(ans);
    return 0;
}
