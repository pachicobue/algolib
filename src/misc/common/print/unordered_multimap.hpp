#pragma once
#include <iostream>
#include <unordered_map>
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::unordered_multimap<Ts...>& vs)
{
    os << "[";
    for (const auto& [k, v] : vs) { os << "(" << k << "->" << v << "),"; }
    return (os << "]" << std::endl);
}
