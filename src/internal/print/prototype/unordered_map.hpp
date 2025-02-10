#pragma once
#include <iostream>
#include <unordered_map>
template <typename... Ts>
std::ostream& operator<<(std::ostream&, const std::unordered_map<Ts...>&);
