#pragma once
#include "type.hpp"
template<typename T>
constexpr bool chmin(T& a, const T& b)
{
    return (a > b ? (a = b, true) : false);
}
template<typename T>
constexpr bool chmax(T& a, const T& b)
{
    return (a < b ? (a = b, true) : false);
}
