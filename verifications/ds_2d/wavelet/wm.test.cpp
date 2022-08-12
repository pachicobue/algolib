#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../../../src/ds_2d/wavelet/wm.hpp"
#include "../../../src/util/fastio/printer.hpp"
#include "../../../src/util/fastio/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<u32>(N);
    auto wm = WaveletMatrix(as);
    LOOP (Q) {
        const auto [l, r, k] = in.tup<int, int, int>();
        out.ln(wm.quantile(l, r, k));
    }
    return 0;
}
