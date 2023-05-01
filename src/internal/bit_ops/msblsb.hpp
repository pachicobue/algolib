#pragma once
#include "../type.hpp"
constexpr int topBit(u64 v) { return v == 0 ? -1 : 63 - __builtin_clzll(v); }
constexpr int lowBit(u64 v) { return v == 0 ? 64 : __builtin_ctzll(v); }
