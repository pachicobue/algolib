#pragma once
#include <deque>
#include <iostream>
template<typename... Ts>
std::ostream& operator<<(std::ostream&, const std::deque<Ts...>&);
