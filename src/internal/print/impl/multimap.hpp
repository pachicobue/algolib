#pragma once
#include <iostream>
#include <map>
template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::multimap<Ts...>& vs) {
    os << "[";
    for (const auto& [k, v] : vs) {
        os << "(" << k << " -> " << v << "),";
    }
    return (os << "]");
}
