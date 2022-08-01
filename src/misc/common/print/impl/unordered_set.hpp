#pragma once
#include <iostream>
#include <unordered_set>
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<Ts...>& vs)
{
    os << "[";
    for (const auto& v : vs) {
        os << v << ",";
    }
    return (os << "]");
}
