#pragma once
#include "../common.hpp"
template<typename T>
constexpr Pair<T, T> extgcd(const T a, const T b)  // [x,y] -> ax+by=gcd(a,b)
{
    static_assert(std::is_signed<T>::value,
                  "extgcd: Only signed integer supported.");
    assert(a != 0 or b != 0);
    if (a >= 0 and b >= 0) {
        if (a < b) {
            const auto [y, x] = extgcd(b, a);
            return {x, y};
        }
        if (b == 0) { return {1, 0}; }
        const auto [x, y] = extgcd(b, a % b);
        return {y, x - (a / b) * y};
    } else {
        auto [x, y] = extgcd(std::abs(a), std::abs(b));
        if (a < 0) { x = -x; }
        if (b < 0) { y = -y; }
        return {x, y};
    }
}
template<typename T>
constexpr T inverse(const T a, const T mod)  // ax=gcd(a,M) (mod M)
{
    assert(a > 0 and mod > 0);
    auto [x, y] = extgcd(a, mod);
    if (x <= 0) { x += mod; }
    return x;
}
