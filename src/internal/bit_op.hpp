#pragma once
#include "type.hpp"
/**
 * @brief i bit目がONかどうか
 * 
 * @param x 
 * @param i bit位置
 * @return true xのi bit目がON
 * @return false xのi bit目がOFF
 */
constexpr bool isBitOn(u64 x, int i) { return assert(0 <= i and i < 64), ((x >> i) & 1_u64); }
/**
 * @brief i bit目がOFFかどうか
 * 
 * @param x 
 * @param i bit位置
 * @return true xのi bit目がOFF
 * @return false xのi bit目がON
 */
constexpr bool isBitOff(u64 x, int i) { return assert(0 <= i and i < 64), (not isBitOn(x, i)); }
/**
 * @brief [0,w) bit目が立ったMask
 * 
 * @param w 
 * @return u64 [0,w) bit目が立ったMask
 */
constexpr u64 bitMask(int w) { return assert(0 <= w and w <= 64), (w == 64 ? ~0_u64 : (1_u64 << w) - 1); }
/**
 * @brief [s,e) bit目が立ったMask
 * 
 * @param s
 * @param e
 * @return u64 [s,e) bit目が立ったMask
 */
constexpr u64 bitMask(int s, int e) { return assert(0 <= s and s <= e and e <= 64), (bitMask(e - s) << s); }
/**
 * @brief floor(log_2(x))
 * @attention x==0 の場合は -1
 * 
 * @param x 
 * @return int floor(log_2(x))
 */
constexpr int floorLog2(u64 x) { return 63 - std::countl_zero(x); }
/**
 * @brief ceil(log_2(x))
 * @attention x==0 の場合は -1
 * 
 * @param x 
 * @return int ceil(log_2(x))
 */
constexpr int ceilLog2(u64 x) { return x == 0 ? -1 : std::bit_width(x - 1); }
/**
 * @brief ord_2(x)
 * @attention x==0 の場合は 64
 * 
 * @param x 
 * @return int ord_2(x)
 */
constexpr int order2(u64 x) { return std::countr_zero(x); }
