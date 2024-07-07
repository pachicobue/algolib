// verification-helper: PROBLEM https://judge.yosupo.jp/problem/range_kth_smallest
#include "data_structure/wavelet/wavelet_matrix.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<i64>(N);
    auto wm = WaveletMatrix(as);
    LOOP (Q) {
        const auto [l, r, k] = in.tup<int, int, int>();
        out.ln(wm.quantile(l, r, k));
    }
    return 0;
}
