#pragma once
#include "../type.hpp"
constexpr u64 bitMask(int bitWidth) { return (bitWidth == 64 ? ~0_u64 : (1_u64 << bitWidth) - 1); }
constexpr u64 bitMask(int start, int end) { return bitMask(end - start) << start; }
