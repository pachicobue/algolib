#pragma once
#include "../type.hpp"
#include "../macro.hpp"

template<typename Vs, typename... Args>
constexpr auto accumAll(const Vs& vs, Args... args)
{
    return std::accumulate(ALL(vs), args...);
}
template<typename Vs>
constexpr auto sumAll(const Vs& vs)
{
    return accumAll(vs, decltype(vs[0]){});
}
template<typename Vs>
constexpr auto gcdAll(const Vs& vs)
{
    return accumAll(vs, (decltype(vs[0])){}, [&](auto v1, auto v2) { return std::gcd(v1, v2); });
}
