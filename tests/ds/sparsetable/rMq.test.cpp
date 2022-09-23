#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../../src/ds/sparsetable/rmq.hpp"
#include "../../../src/util/fastio/printer.hpp"
#include "../../../src/util/fastio/scanner.hpp"

struct Max
{
    using T = i32;
    bool operator()(const T& x1, const T& x2) const { return x1 > x2; }
};
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    auto as = in.vec<i32>(N);
    for (auto& a : as) { a = -a; }
    const auto rMq = StaticRMQ<Max>(as);
    LOOP (Q) {
        const auto [l, r] = in.tup<int, int>();
        out.ln(-rMq.fold(l, r));
    }
}
