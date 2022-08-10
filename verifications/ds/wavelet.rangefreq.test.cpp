#define PROBLEM "https://yukicoder.me/problems/1937"
#include "../../src/ds/wavelet.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"
#include "../../src/utility/bin_search.hpp"
int main()
{
    const auto N = in.val<int>();
    auto as = in.vec<i64>(N);
    Vec<i64> ls(N), rs(N);
    for (int i : rep(N)) {
        std::tie(ls[i], rs[i]) = in.tup<i64, i64>();
    }

    auto is = iotaVec(N);
    sortAll(is, [&](int i, int j) { return as[i] < as[j]; });
    constexpr i64 L = TEN<i64>(9);
    Vec<i64> bs = as;
    for (int i : rep(N)) {
        bs[i] = as[is[i]] - ls[is[i]] + L;
    }
    auto wm = WaveletMatrix(bs, 31);

    i64 ans = 0;
    for (int i : rep(N - 1)) {
        const int jsup = binSearch(
            i, N, [&](int j) { return as[is[i]] + rs[is[i]] < as[is[j]]; });
        ans += wm.rangeFreq(i + 1, jsup, 0, as[is[i]] + L + 1);
    }
    out.ln(ans);
    return 0;
}
