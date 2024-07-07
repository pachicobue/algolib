// verification-helper: PROBLEM https://judge.yosupo.jp/problem/staticrmq
#include "data_structure/sparse_table/static_rmq.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    const auto [N, Q] = in.tup<int, int>();
    auto as = in.vec<int>(N);
    for (auto& a : as) { a = -a; }
    const auto rMq = StaticRMQ<int, FConst(-INF<int>), Gt<int>{}>(as);
    LOOP (Q) {
        const auto [l, r] = in.tup<int, int>();
        out.ln(-rMq.fold(l, r));
    }
}
