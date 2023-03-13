#pragma once
#include <deque>
#include <iostream>
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::deque<Ts...>& vs)
{
    os << "[";
    for (const auto& v : vs) { os << v << ","; }
    return (os << "]");
}
