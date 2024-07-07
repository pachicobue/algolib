// verification-helper: PROBLEM https://judge.yosupo.jp/problem/staticrmq
#include "data_structure/sparse_table/static_rmq.hpp"
#include "internal.hpp"
#include "internal/functional.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<int>(N);
    const auto rmq = StaticRMQ<int, FConst(INF<int>), Lt<int>{}>(as);
    LOOP (Q) {
        const auto [l, r] = in.tup<int, int>();
        out.ln(rmq.fold(l, r));
    }
}
