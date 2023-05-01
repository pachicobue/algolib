#pragma once
#include "../type.hpp"
#include "../macro.hpp"

template<typename Vs, typename... Args>
constexpr void sortAll(Vs& vs, Args... args)
{
    std::sort(ALL(vs), args...);
}

template<typename Vs, typename... Args>
constexpr Vs sorted(Vs vs, Args... args)
{
    sortAll(vs, args...);
    return vs;
}
