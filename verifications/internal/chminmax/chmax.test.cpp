// verification-helper: UNITTEST
#include "internal/chminmax.hpp"
#include "utility/rng.hpp"
void lessTest()
{
    LOOP (20) {
        auto x             = rng.val(-100, 100);
        const auto y       = rng.val(-100, 100);
        const auto px      = x;
        const bool changed = chmax(x, y);
        assert(changed == (px < y));
        assert(x == std::max(px, y));
    }
}
void greaterTest()
{
    LOOP (20) {
        auto x             = rng.val(-100, 100);
        const auto y       = rng.val(-100, 100);
        const auto px      = x;
        const bool changed = chmax(x, y, Gt<int>{});
        assert(changed == (px > y));
        assert(x == std::min(px, y));
    }
}
int main()
{
    lessTest();
    greaterTest();
    return 0;
}
