#pragma once
#include <iostream>
#include <vector>
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::vector<Ts...>& vs)
{
    os << "[";
    for (const auto& v : vs) { os << v << ","; }
    return (os << "]" << std::endl);
}
