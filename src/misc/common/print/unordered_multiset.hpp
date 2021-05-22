#pragma once
#include <iostream>
#include <unordered_set>
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::unordered_multiset<Ts...>& vs)
{
    os << "[";
    for (const auto& v : vs) { os << v << ","; }
    return (os << "]" << std::endl);
}
