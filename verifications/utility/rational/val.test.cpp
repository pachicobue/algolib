// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/rational.hpp"
#include "utility/rng.hpp"
void test() {
    LOOP (100) {
        auto n = rng.val(-100, 100);
        auto d = rng.val(-100, 100);
        if (n == 0 and d == 0) {
            continue;
        }
        Rational v{n, d};
        const auto p = v.val();
        assert(p.first == v.num() and p.second == v.den());
    }
}
int main() {
    test();
}
