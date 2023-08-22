// verification-helper: UNITTEST
#include "utility/rng.hpp"
void test()
{
    const auto N  = 100;
    const i64 min = -10;
    const i64 max = 10;
    LOOP (100) {
        const auto xs = rng.vec(N, min, max);
        assert((int)xs.size() == N);
        assert(std::ranges::all_of(xs, [&](int x) { return min <= x and x <= max; }));
    }
}
int main() { test(); }
