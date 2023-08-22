// verification-helper: UNITTEST
#include "utility/rng.hpp"
void test()
{
    const i64 min = -10;
    const i64 max = 10;
    LOOP (100) {
        const auto x = rng.val(min, max);
        assert(min <= x and x <= max);
    }
}
int main() { test(); }
