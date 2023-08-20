// verification-helper: UNITTEST
#include "internal/bit_op.hpp"
#include "internal/irange.hpp"
#include "internal/constant.hpp"
#include "utility/rng.hpp"
void lessTest()
{
    LOOP (20) {
        auto x             = rng.val(-100, 100);
        const auto y       = rng.val(-100, 100);
        const auto px      = x;
        const bool changed = chmin(x, y);
        assert(changed == (px > y));
        assert(x == std::min(px, y));
    }
}
void greaterTest()
{
    LOOP (20) {
        auto x             = rng.val(-100, 100);
        const auto y       = rng.val(-100, 100);
        const auto px      = x;
        const bool changed = chmin(x, y, Gt<int>{});
        assert(changed == (px < y));
        assert(x == std::max(px, y));
    }
}
int main()
{
    lessTest();
    greaterTest();
    return 0;
}
