#pragma once
#include "../type.hpp"
#include "../macro.hpp"

template<typename Vs>
constexpr void reverseAll(Vs& vs)
{
    std::reverse(ALL(vs));
}
template<typename Vs>
constexpr Vs reversed(Vs vs)
{
    reverseAll(vs);
    return vs;
}
