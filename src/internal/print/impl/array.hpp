#pragma once
#include <array>
#include <iostream>
template<typename T, std::size_t n> std::ostream& operator<<(std::ostream& os, const std::array<T, n>& vs)
{
    os << "[";
    for (const auto& v : vs) { os << v << ","; }
    return (os << "]");
}
