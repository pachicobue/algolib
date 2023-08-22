// verification-helper: UNITTEST
#include "utility/golden_search.hpp"
#include "utility/rng.hpp"
void test()
{
    LOOP (1000) {
        const int N = 1000;
        const int L = -N, R = N;
        const auto Fs = rng.vec(R - L, -100000, 100000);
        auto f        = [&](int x) {
            assert(L <= x and x < R);
            return Fs[x - L];
        };
        const int x = goldenSearch(L, R, f);
        assert(L <= x and x < R);
        if (L <= x - 1) { assert(f(x - 1) >= f(x)); }
        if (x + 1 < R) { assert(f(x) <= f(x + 1)); }
    }
}
int main()
{
    test();
    return 0;
}
