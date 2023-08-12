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
template<typename T> constexpr bool chmin(T& x, const T& y, auto comp = Lt<T>{}) { return (comp(y, x) ? (x = y, true) : false); }
/**
 * @brief chmax
 * 
 * @param x 
 * @param y 
 * @param comp 比較関数
 * @return true xが更新された
 * @return false xが更新されなかった
 */
template<typename T> constexpr bool chmax(T& x, const T& y, auto comp = Lt<T>{}) { return (comp(x, y) ? (x = y, true) : false); }
