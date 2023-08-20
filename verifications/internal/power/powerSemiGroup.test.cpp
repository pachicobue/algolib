// verification-helper: UNITTEST
#include "internal/power.hpp"
#include "internal/irange.hpp"
constexpr int MOD = 109;
struct T
{
    int min, sum, prod;
    friend auto operator<=>(const T&, const T&) = default;
    static T mul(const T& x, const T& y) { return T{std::min(x.min, y.min), x.sum + y.sum, x.prod * y.prod % MOD}; }
    friend T operator*(const T& x, const T& y) { return mul(x, y); }
};
void mulTest()
{
    const int N = 100;
    const T x{100, 100, 100};
    T ans = x;
    LOOP (N - 1) { ans = T::mul(ans, x); }
    assert(powerSemiGroup(x, N, T::mul) == ans);
}
void operatorTest()
{
    const int N = 100;
    const T x{-100, -100, -100};
    T ans = x;
    LOOP (N - 1) { ans = ans * x; }
    assert(powerSemiGroup(x, N) == ans);
}
int main()
{
    mulTest();
    operatorTest();
    return 0;
}
