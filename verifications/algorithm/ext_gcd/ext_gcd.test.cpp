// verification-helper: UNITTEST
#include <cassert>
#include <cmath>
#include <numeric>
#include "algorithm/ext_gcd.hpp"
#include "internal.hpp"
#include "utility/rng.hpp"
void nonZeroTest() {
    LOOP (100) {
        const auto a = rng.val<i64>(-TEN<i64>(15), TEN<i64>(15));
        const auto b = rng.val<i64>(-TEN<i64>(15), TEN<i64>(15));
        if (a == 0 or b == 0) { continue; }
        const i64 g = std::gcd(std::abs(a), std::abs(b));
        const auto [x, y] = extgcd(a, b);
        assert((i128)a * x + (i128)b * y == g);
        assert(0 <= x and x < std::abs(b) / g);
    }
}
void aZeroTest() {
    LOOP (100) {
        const auto a = 0_i64;
        const auto b = rng.val<i64>(-TEN<i64>(15), TEN<i64>(15));
        if (b == 0) { continue; }
        const auto [x, y] = extgcd(a, b);
        assert((i128)a * x + (i128)b * y == std::abs(b));
        assert(x == 0);
    }
}
void bZeroTest() {
    LOOP (100) {
        const auto a = rng.val<i64>(-TEN<i64>(15), TEN<i64>(15));
        const auto b = 0_i64;
        if (a == 0) { continue; }
        const auto [x, y] = extgcd(a, b);
        assert((i128)a * x + (i128)b * y == std::abs(a));
        assert(std::abs(x) == 1);
    }
}
int main() {
    nonZeroTest();
    aZeroTest();
    bZeroTest();
    return 0;
}
