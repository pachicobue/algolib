#pragma once
#include "type.hpp"
/**
 * @brief chmin
 *
 * @param x
 * @param y
 * @param comp 比較関数
 * @return true xが更新された
 * @return false xが更新されなかった
 */
template <typename T> constexpr auto chmin(T &x, const T &y, auto comp) -> bool { return (comp(y, x) ? (x = y, true) : false); }
/**
 * @brief chmin
 *
 * @param x
 * @param y
 * @return true xが更新された
 * @return false xが更新されなかった
 */
template <typename T> constexpr auto chmin(T &x, const T &y) -> bool { return chmin(x, y, Lt<T>{}); }
/**
 * @brief chmax
 *
 * @param x
 * @param y
 * @param comp 比較関数
 * @return true xが更新された
 * @return false xが更新されなかった
 */
template <typename T> constexpr auto chmax(T &x, const T &y, auto comp) -> bool { return (comp(x, y) ? (x = y, true) : false); }
/**
 * @brief chmax
 *
 * @param x
 * @param y
 * @return true xが更新された
 * @return false xが更新されなかった
 */
template <typename T> constexpr auto chmax(T &x, const T &y) -> bool { return chmax(x, y, Lt<T>{}); }
