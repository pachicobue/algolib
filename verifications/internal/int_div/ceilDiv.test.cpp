// verification-helper: UNITTEST
#include <cassert>
#include <cmath>
#include "internal/constant.hpp"
#include "internal/int_div.hpp"
#include "internal/irange.hpp"
#include "internal/type.hpp"
#include "utility/rng.hpp"
void test() {
    LOOP (100) {
        const auto x = rng.val<i64>(-TEN<i64>(9), TEN<i64>(9));
        const auto y = rng.val<i64>(-TEN<i64>(9), TEN<i64>(9));
        if (y == 0) { continue; }
        const i64 d = ceilDiv(x, y);
        assert(d == (i64)std::ceil(f80(x) / y));
    }
}
int main() {
    test();
    return 0;
}
