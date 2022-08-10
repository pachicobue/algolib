#pragma once
#include <iostream>
#include <set>
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::multiset<Ts...>& vs)
{
    os << "[";
    for (const auto& v : vs) {
        os << v << ",";
    }
    return (os << "]");
}
