#pragma once
#include <iostream>
#include <map>
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::multimap<Ts...>& v)
{
    os << "[";
    for (const auto& [k, v] : v) { os << "(" << k << " -> " << v << "),"; }
    return (os << "]" << std::endl);
}
