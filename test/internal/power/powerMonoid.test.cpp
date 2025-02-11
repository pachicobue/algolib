// verification-helper: UNITTEST
#include <algorithm>
#include <cassert>
#include "internal/constant.hpp"
#include "internal/irange.hpp"
#include "internal/power.hpp"
constexpr int MOD = 109;
struct T {
    int min, sum, prod;
    friend auto operator<=>(const T&, const T&) = default;
    static T mul(const T& x, const T& y) {
        return T{std::min(x.min, y.min), x.sum + y.sum, x.prod * y.prod % MOD};
    }
    friend T operator*(const T& x, const T& y) {
        return mul(x, y);
    }
};
static constexpr T E = {INF<int>, 0, 1};
void mulTest() {
    const int N = 100;
    const T x{100, 100, 100};
    T ans = E;
    LOOP (N) {
        ans = T::mul(ans, x);
    }
    assert(powerMonoid(x, N, E, T::mul) == ans);
}
void operatorTest() {
    const int N = 100;
    const T x{-100, -100, -100};
    T ans = E;
    LOOP (N) {
        ans = ans * x;
    }
    assert(powerMonoid(x, N, E) == ans);
}
int main() {
    mulTest();
    operatorTest();
    return 0;
}
