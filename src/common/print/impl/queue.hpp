#pragma once
#include <iostream>
#include <queue>
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::queue<Ts...>& vs)
{
    auto q = vs;
    os << "[";
    while (not q.empty()) { os << q.front() << ",", q.pop(); }
    return os << "]";
}
