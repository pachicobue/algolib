// verification-helper: UNITTEST
#include "utility/golden_search.hpp"
#include "utility/rng.hpp"
void test()
{
    LOOP (1000) {
        const f80 L = -1e9, R = 1e9;
        const f80 c  = std::uniform_real_distribution<f80>{L, R}(rng);
        auto f       = [&](int x) { return (x - c) * (x - c); };
        const auto x = goldenSearch(L, R, f, 1000);
        assert(std::abs((x - c) / c) < 1e-5);
    }
}
int main()
{
    test();
    return 0;
}
