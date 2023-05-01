#pragma once
#include "../type.hpp"
#include "../macro.hpp"

constexpr int popCount(u64 v) { return v ? __builtin_popcountll(v) : 0; }
constexpr bool popParity(u64 v) { return v > 0 and __builtin_parity(v) == 1; }
