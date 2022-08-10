#pragma once
#include "type.hpp"
constexpr int popcount(u64 v)
{
    return v ? __builtin_popcountll(v) : 0;
}
constexpr int log2p1(u64 v)
{
    return v ? 64 - __builtin_clzll(v) : 0;
}
constexpr int lsbp1(u64 v)
{
    return __builtin_ffsll(v);
}
constexpr int ceillog(u64 v)
{
    return v ? log2p1(v - 1) : 0;
}
constexpr u64 ceil2(u64 v)
{
    return 1_u64 << ceillog(v);
}
constexpr u64 floor2(u64 v)
{
    return v ? (1_u64 << (log2p1(v) - 1)) : 0_u64;
}
constexpr bool ispow2(u64 v)
{
    return (v > 0) and ((v & (v - 1)) == 0);
}
constexpr bool btest(u64 mask, int ind)
{
    return (mask >> ind) & 1_u64;
}
