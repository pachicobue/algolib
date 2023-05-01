#pragma once
#include "../type.hpp"
#include "../macro.hpp"

template<typename Vs, typename V>
constexpr void plusAll(Vs& vs, const V& v)
{
    for (auto& v_ : vs) { v_ += v; }
}
