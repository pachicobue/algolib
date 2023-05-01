#pragma once
#include "../type.hpp"
#include "../macro.hpp"

template<typename Vs>
constexpr auto minAll(const Vs& vs)
{
    return *std::min_element(ALL(vs));
}
template<typename Vs>
constexpr auto maxInd(const Vs& vs)
{
    return *std::max_element(ALL(vs));
}
template<typename Vs>
constexpr int minInd(const Vs& vs)
{
    return std::min_element(ALL(vs)) - std::begin(vs);
}
template<typename Vs>
constexpr int maxInd(const Vs& vs)
{
    return std::max_element(ALL(vs)) - std::begin(vs);
}
