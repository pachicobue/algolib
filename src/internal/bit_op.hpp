#pragma once
#include "type.hpp"
constexpr int popCount(u64 v) { return v ? __builtin_popcountll(v) : 0; }
constexpr int topBit(u64 v) { return v == 0 ? -1 : 63 - __builtin_clzll(v); }
constexpr int lowBit(u64 v) { return v == 0 ? 64 : __builtin_ctzll(v); }
constexpr int bitWidth(u64 v) { return topBit(v) + 1; }
constexpr u64 bitCeil(u64 v) { return v ? (1_u64 << bitWidth(v - 1)) : 1_u64; }
constexpr u64 bitFloor(u64 v) { return v ? (1_u64 << topBit(v)) : 0_u64; }
constexpr bool hasSingleBit(u64 v) { return (v > 0) and ((v & (v - 1)) == 0); }
constexpr bool isBitOn(u64 mask, int ind) { return (mask >> ind) & 1_u64; }
constexpr bool isBitOff(u64 mask, int ind) { return not isBitOn(mask, ind); }
constexpr u64 bitMask(int bitWidth) { return (bitWidth == 64 ? ~0_u64 : (1_u64 << bitWidth) - 1); }
constexpr u64 bitMask(int start, int end) { return bitMask(end - start) << start; }
