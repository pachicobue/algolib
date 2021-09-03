#pragma once
#include "type_alias.hpp"
#include "show.hpp"
template<typename T>
bool chmin(T& a, const T& b)
{
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<typename T>
bool chmax(T& a, const T& b)
{
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<typename T>
constexpr T floorDiv(T x, T y)
{
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? x / y : (x - y + 1) / y;
}
template<typename T>
constexpr T ceilDiv(T x, T y)
{
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? (x + y - 1) / y : x / y;
}
template<typename T, typename I>
constexpr T modPower(T v, I n, T mod)
{
    T ans = 1 % mod;
    for (; n > 0; n >>= 1, (v *= v) %= mod) {
        if (n % 2 == 1) { (ans *= v) %= mod; }
    }
    return ans;
}
template<typename T, typename I>
constexpr T power(T v, I n)
{
    T ans = 1;
    for (; n > 0; n >>= 1, v *= v) {
        if (n % 2 == 1) { ans *= v; }
    }
    return ans;
}
template<typename T, typename I>
constexpr T power(T v, I n, const T& e)
{
    T ans = e;
    for (; n > 0; n >>= 1, v *= v) {
        if (n % 2 == 1) { ans *= v; }
    }
    return ans;
}
