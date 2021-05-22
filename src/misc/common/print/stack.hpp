#pragma once
#include <iostream>
#include <stack>
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::stack<Ts...>& vs)
{
    auto q = vs;
    os << "[";
    while (not q.empty()) { os << q.top() << ",", q.pop(); }
    return os << "]\n";
}
