#pragma once
#include <iostream>
#include <stack>
template <typename... Ts>
std::ostream& operator<<(std::ostream&, const std::stack<Ts...>&);
