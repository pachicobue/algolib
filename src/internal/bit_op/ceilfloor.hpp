#pragma once
#include "../type.hpp"
#include "msblsb.hpp"
constexpr int bitWidth(u64 v) { return topBit(v) + 1; }
constexpr u64 bitCeil(u64 v) { return v ? (1_u64 << bitWidth(v - 1)) : 1_u64; }
constexpr u64 bitFloor(u64 v) { return v ? (1_u64 << topBit(v)) : 0_u64; }
constexpr bool hasSingleBit(u64 v) { return (v > 0) and ((v & (v - 1)) == 0); }
