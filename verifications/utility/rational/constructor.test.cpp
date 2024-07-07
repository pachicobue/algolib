// verification-helper: UNITTEST
#include <cassert>
#include <numeric>
#include "internal.hpp"
#include "utility/rational.hpp"
#include "utility/rng.hpp"
void emptyTest() {
    Rational<i64> v;
    assert(v.num() == 0);
    assert(v.den() == 1);
}
void int1Test() {
    LOOP (100) {
        const auto n = rng.val(-100, 100);
        Rational v{n};
        assert(v.num() == n);
        assert(v.den() == 1);
    }
}
void int2Test() {
    LOOP (100) {
        auto n = rng.val(-100, 100);
        auto d = rng.val(-100, 100);
        if (n == 0 and d == 0) { continue; }
        Rational v{n, d};
        const auto g = std::gcd(n, d);
        n /= g, d /= g;
        if (d < 0) { n = -n, d = -d; }
        assert(v.num() == n);
        assert(v.den() == d);
    }
}
int main() {
    emptyTest();
    int1Test();
    int2Test();
}
