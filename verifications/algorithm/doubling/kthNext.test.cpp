// verification-helper: PROBLEM https://yukicoder.me/problems/no/1013
#include "algorithm/doubling.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
struct Monoid
{
    using T = i64;
    static constexpr T e() { return 0; }
    T operator()(const T& x1, const T& x2) const { return x1 + x2; }
};
int main()
{
    const auto [N, K] = in.tup<int, i64>();
    const auto Ps     = in.vec<int>(N);
    Vec<int> Fs(N);
    Vec<i64> Ws(N);
    for (int i : rep(N)) {
        Fs[i] = (Ps[i] + i) % N;
        Ws[i] = Ps[i];
    }
    Doubling<Monoid> doubling{Fs, Ws};
    for (int i : rep(N)) {
        const auto D = doubling.kthNext(i, K).second;
        out.ln((i64)i + 1 + D);
    }

    return 0;
}
