#pragma once
#include "../type.hpp"
constexpr bool isBitOn(u64 mask, int ind) { return (mask >> ind) & 1_u64; }
constexpr bool isBitOff(u64 mask, int ind) { return not isBitOn(mask, ind); }
