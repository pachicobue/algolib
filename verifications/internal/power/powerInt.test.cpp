// verification-helper: UNITTEST
#include <cassert>
#include "internal/irange.hpp"
#include "internal/power.hpp"
#include "internal/type.hpp"
constexpr int MOD = 109;
struct T {
    T() = default;
    T(int v)
        : v{v} {
    }
    int v;
    friend auto operator<=>(const T&, const T&) = default;
    friend T operator*(const T& x, const T& y) {
        return T{x.v * y.v % MOD};
    }
};
void i64Test() {
    const int N = 20;
    i64 x = -3;
    i64 ans = 1;
    LOOP (N) {
        ans *= x;
    }
    assert(powerInt(x, N) == ans);
}
void modTest() {
    const int N = 100;
    const T x = 100;
    T ans = 1;
    LOOP (N) {
        ans = ans * x;
    }
    assert(powerInt(x, N) == ans);
}
int main() {
    i64Test();
    modTest();
    return 0;
}
