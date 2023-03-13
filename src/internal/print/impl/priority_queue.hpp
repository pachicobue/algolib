#pragma once
#include <iostream>
#include <queue>
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::priority_queue<Ts...>& vs)
{
    auto q = vs;
    os << "[";
    while (not q.empty()) { os << q.top() << ",", q.pop(); }
    return os << "]";
}
