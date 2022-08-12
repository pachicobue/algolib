#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../../../src/ds_2d/wavelet/wm.hpp"
#include "../../../src/util/fastio/printer.hpp"
#include "../../../src/util/fastio/scanner.hpp"
#include "../../../src/util/bin_search.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<i64>(N);
    auto wm = WaveletMatrix(as);
    LOOP (Q) {
        const auto [l, r, k] = in.tup<int, int, int>();
        const i64 ans = binSearch(TEN<i64>(9) + 1, 0_i64, [&, l = l, r = r, k = k](u32 x) {
            return wm.rangeFreq(l, r, 0, x) <= k;
        });
        out.ln(ans);
    }
    return 0;
}
