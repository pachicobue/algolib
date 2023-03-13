#pragma once
#include <iostream>
#include <queue>
template<typename... Ts>
std::ostream& operator<<(std::ostream&, const std::priority_queue<Ts...>&);
