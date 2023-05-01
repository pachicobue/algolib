#pragma once
#include "../type.hpp"
#include "../macro.hpp"

template<typename Vs>
constexpr void concat(Vs& vs1, const Vs vs2)
{
    std::copy(ALL(vs2), std::back_inserter(vs1));
}
template<typename Vs>
constexpr Vs concatted(Vs vs1, const Vs& vs2)
{
    concat(vs1, vs2);
    return vs1;
}
