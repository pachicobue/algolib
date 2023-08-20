// verification-helper: UNITTEST
#include "internal/int_div.hpp"
#include "utility/rng.hpp"
void test()
{
    LOOP (100) {
        const auto x = rng.val<i64>(-TEN<i64>(9), TEN<i64>(9));
        const auto y = rng.val<i64>(-TEN<i64>(9), TEN<i64>(9));
        if (y == 0) { continue; }
        const i64 d = floorDiv(x, y);
        assert(d == (i64)std::floor(f80(x) / y));
    }
}
int main()
{
    test();
    return 0;
}
