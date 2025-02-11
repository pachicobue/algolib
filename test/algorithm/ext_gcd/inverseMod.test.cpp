// verification-helper: UNITTEST
#include <cassert>
#include <cmath>
#include <numeric>
#include "algorithm/ext_gcd.hpp"
#include "internal.hpp"
#include "utility/rng.hpp"
void test() {
    LOOP (100) {
        const auto a = rng.val<i64>(-TEN<i64>(15), TEN<i64>(15));
        const auto mod = rng.val<i64>(2_i64, TEN<i64>(15));
        if (a % mod == 0) {
            continue;
        }
        const i64 g = std::gcd(std::abs(a), mod);
        const auto x = inverseMod(a, mod);
        assert(((i128)a * x - g) % mod == 0);
        assert(0 <= x and x < mod / g);
    }
}
int main() {
    test();
    return 0;
}
