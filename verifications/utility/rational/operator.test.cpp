// verification-helper: UNITTEST
#include <cassert>
#include <numeric>
#include "internal.hpp"
#include "utility/rational.hpp"
#include "utility/rng.hpp"
void negTest() {
    LOOP (100) {
        const auto n = rng.val(-100, 100), d = rng.val(1, 100);
        const Rational v{n, d};
        const auto nv = -v;
        assert(nv.num() == -v.num() and nv.den() == v.den());
    }
}
void plusEqTest() {
    LOOP (100) {
        const auto n1 = rng.val(-100, 100), d1 = rng.val(1, 100);
        const auto n2 = rng.val(-100, 100), d2 = rng.val(1, 100);
        Rational v1{n1, d1}, v2{n2, d2};
        auto n = n1 * d2 + n2 * d1, d = d1 * d2;
        const auto g = std::gcd(n, d);
        n /= g, d /= g;
        v1 += v2;
        assert(v1.num() == n and v1.den() == d);
    }
}
void minusEqTest() {
    LOOP (100) {
        const auto n1 = rng.val(-100, 100), d1 = rng.val(1, 100);
        const auto n2 = rng.val(-100, 100), d2 = rng.val(1, 100);
        Rational v1{n1, d1}, v2{n2, d2};
        auto n = n1 * d2 - n2 * d1, d = d1 * d2;
        const auto g = std::gcd(n, d);
        n /= g, d /= g;
        v1 -= v2;
        assert(v1.num() == n and v1.den() == d);
    }
}
void prodEqTest() {
    LOOP (100) {
        const auto n1 = rng.val(-100, 100), d1 = rng.val(1, 100);
        const auto n2 = rng.val(-100, 100), d2 = rng.val(1, 100);
        Rational v1{n1, d1}, v2{n2, d2};
        auto n = n1 * n2, d = d1 * d2;
        const auto g = std::gcd(n, d);
        n /= g, d /= g;
        v1 *= v2;
        assert(v1.num() == n and v1.den() == d);
    }
}
void divEqTest() {
    LOOP (100) {
        const auto n1 = rng.val(-100, 100), d1 = rng.val(1, 100);
        const auto n2 = rng.val(1, 100), d2 = rng.val(1, 100);
        Rational v1{n1, d1}, v2{n2, d2};
        auto n = n1 * d2, d = d1 * n2;
        const auto g = std::gcd(n, d);
        n /= g, d /= g;
        v1 /= v2;
        assert(v1.num() == n and v1.den() == d);
    }
}
void plusTest() {
    LOOP (100) {
        const auto n1 = rng.val(-100, 100), d1 = rng.val(1, 100);
        const auto n2 = rng.val(-100, 100), d2 = rng.val(1, 100);
        Rational v1{n1, d1}, v2{n2, d2};
        auto n = n1 * d2 + n2 * d1, d = d1 * d2;
        const auto g = std::gcd(n, d);
        n /= g, d /= g;
        const auto v = v1 + v2;
        assert(v.num() == n and v.den() == d);
    }
}
void minusTest() {
    LOOP (100) {
        const auto n1 = rng.val(-100, 100), d1 = rng.val(1, 100);
        const auto n2 = rng.val(-100, 100), d2 = rng.val(1, 100);
        Rational v1{n1, d1}, v2{n2, d2};
        auto n = n1 * d2 - n2 * d1, d = d1 * d2;
        const auto g = std::gcd(n, d);
        n /= g, d /= g;
        const auto v = v1 - v2;
        assert(v.num() == n and v.den() == d);
    }
}
void prodTest() {
    LOOP (100) {
        const auto n1 = rng.val(-100, 100), d1 = rng.val(1, 100);
        const auto n2 = rng.val(-100, 100), d2 = rng.val(1, 100);
        Rational v1{n1, d1}, v2{n2, d2};
        auto n = n1 * n2, d = d1 * d2;
        const auto g = std::gcd(n, d);
        n /= g, d /= g;
        const auto v = v1 * v2;
        assert(v.num() == n and v.den() == d);
    }
}
void divTest() {
    LOOP (100) {
        const auto n1 = rng.val(-100, 100), d1 = rng.val(1, 100);
        const auto n2 = rng.val(1, 100), d2 = rng.val(1, 100);
        Rational v1{n1, d1}, v2{n2, d2};
        auto n = n1 * d2, d = d1 * n2;
        const auto g = std::gcd(n, d);
        n /= g, d /= g;
        const auto v = v1 / v2;
        assert(v.num() == n and v.den() == d);
    }
}
void compTest() {
    LOOP (1000) {
        auto n1 = rng.val(-100, 100), d1 = rng.val(-100, 100);
        auto n2 = rng.val(-100, 100), d2 = rng.val(-100, 100);
        if (rng.val(0, 5) == 0) {
            n2 = n1, d2 = d1;
        }
        if (n1 == 0 and d1 == 0) {
            continue;
        }
        if (n2 == 0 and d2 == 0) {
            continue;
        }
        const Rational v1{n1, d1}, v2{n2, d2};
        if (d1 < 0) {
            n1 = -n1, d1 = -d1;
        }
        if (d2 < 0) {
            n2 = -n2, d2 = -d2;
        }
        const i64 x1 = n1 * d2, x2 = n2 * d1;
        assert((v1 == v2) == (x1 == x2));
        assert((v1 != v2) == (x1 != x2));
        assert((v1 < v2) == (x1 < x2));
        assert((v1 > v2) == (x1 > x2));
        assert((v1 <= v2) == (x1 <= x2));
        assert((v1 >= v2) == (x1 >= x2));
    }
}
int main() {
    negTest();

    plusEqTest();
    minusEqTest();
    prodEqTest();
    divEqTest();

    plusTest();
    minusTest();
    prodTest();
    divTest();

    compTest();
}
