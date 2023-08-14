#pragma once
#include "../common.hpp"
/**
 * @brief 拡張ユークリッド互除法
 * @attention x はあり得る中で最小の非負整数(b != 0 の場合)
 * 
 * @param a 
 * @param b 
 * @return Pair<i64, i64> ax+by=gcd(a,b) を満たす {x,y}
 */
constexpr Pair<i64, i64> extgcd(i64 a, i64 b)
{
    assert(a != 0 or b != 0);
    const i64 A = ABS(a), B = ABS(b);
    auto [x, y, g] = Fix([&](auto self, i64 a, i64 b) -> Tup<i64, i64, i64> {
        assert(0 <= a and a < b);
        if (a == 0) { return {0, 1, b}; }
        const auto [px, py, pg] = self(b % a, a);
        return {py - (b / a) * px, px, pg};
    })(std::ranges::min(A, B), std::ranges::max(A, B));
    if (A > B) { std::swap(x, y); }
    if (a < 0) { x = -x; }
    if (b < 0) { y = -y; }
    // この時点で ax+by=gcd(A,B), |x|<B/g, |y|<=A/g になっているので微調整
    if (x < 0) { x += B / g, y -= (b > 0 ? a / g : -a / g); }
    return {x, y};
}
/**
 * @brief MOD逆元 (互いに素じゃなくても使える)
 * @attention 最小の非負整数を返す
 * 
 * @param a 
 * @param mod 
 * @return i64 ax=gcd(a,M) mod M を満たす x
 */
constexpr i64 inverseMod(i64 a, i64 mod)
{
    assert(mod > 0 and a % mod != 0);
    return extgcd(a % mod, mod).first;
}
