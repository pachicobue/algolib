#pragma once
#include "../type.hpp"
#include "../macro.hpp"

template<typename Vs, typename V>
constexpr int lbInd(const Vs& vs, const V& v)
{
    return std::lower_bound(ALL(vs), v) - std::begin(vs);
}
template<typename Vs, typename V>
constexpr int ubInd(const Vs& vs, const V& v)
{
    return std::upper_bound(ALL(vs), v) - std::begin(vs);
}
