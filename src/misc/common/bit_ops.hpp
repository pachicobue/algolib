#pragma once
#include "type_alias.hpp"
#pragma region BitOps
constexpr int popcount(const u64 v)
{
    return v ? __builtin_popcountll(v) : 0;
}
constexpr int log2p1(const u64 v)
{
    return v ? 64 - __builtin_clzll(v) : 0;
}
constexpr int lsbp1(const u64 v)
{
    return __builtin_ffsll(v);
}
constexpr int clog(const u64 v)
{
    return v ? log2p1(v - 1) : 0;
}
constexpr u64 ceil2(const u64 v)
{
    const int l = clog(v);
    return (l == 64) ? 0_u64 : (1_u64 << l);
}
constexpr u64 floor2(const u64 v)
{
    return v ? (1_u64 << (log2p1(v) - 1)) : 0_u64;
}
constexpr bool ispow2(const u64 v)
{
    return (v > 0) and ((v & (v - 1)) == 0);
}
constexpr bool btest(const u64 mask, const int ind)
{
    return (mask >> ind) & 1_u64;
}
#pragma endregion
