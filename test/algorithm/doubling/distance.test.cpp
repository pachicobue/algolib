// verification-helper: PROBLEM https://yukicoder.me/problems/no/2242
#include "algorithm/doubling.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    const auto N = in.val<int>();
    const auto Hs = in.vec<int>(N);
    const auto Ts = in.vec<int>(N);
    auto is = iotaVec(N), ris = Vec<int>(N);
    seqSort(is, [&](int i, int j) {
        return Hs[i] < Hs[j];
    });
    for (int i : rep(N)) {
        ris[is[i]] = i;
    }

    Vec<int> hs(N), ts(N);
    for (int i : rep(N)) {
        hs[i] = Hs[is[i]], ts[i] = Ts[is[i]];
    }
    auto mts = ts;
    auto mtis = iotaVec(N);
    for (int i : rep(N - 1)) {
        if (chmax(mts[i + 1], mts[i])) {
            mtis[i + 1] = mtis[i];
        }
    }

    Vec<int> ns(N);
    for (int i : rep(N)) {
        const int ri = sortedUbInd(hs, ts[i]);
        ns[i] = (ri == 0 ? -1 : mtis[ri - 1]);
    }
    Doubling<int, FConst(-INF<int>), FMax<int>{}> doubling(ns, ts);

    const auto Q = in.val<int>();
    LOOP (Q) {
        const auto [A, B] = in.tup<int, int>(1, 1);
        if (A == B) {
            out.ln(0);
        } else {
            const int a = ris[A], b = ris[B];
            int d = doubling.distance(a, N, [&](int, int d) {
                return hs[b] <= d;
            });
            chmax(d, 1);
            out.ln(d == N + 1 ? -1 : d);
        }
    }
    return 0;
}
