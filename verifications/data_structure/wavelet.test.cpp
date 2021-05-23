#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../../src/data_structure/wavelet.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<u64>(N);
    const auto wm = Wavelet<30>(as);
    for (int q : rep(Q)) {
        const auto [l, r, k] = in.tup<int, int, int>();
        out.ln(wm.quantile(l, r, k));
    }
    return 0;
}
