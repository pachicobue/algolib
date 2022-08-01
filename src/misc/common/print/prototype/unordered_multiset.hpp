#pragma once
#include <iostream>
#include <unordered_set>
template<typename... Ts>
std::ostream& operator<<(std::ostream&, const std::unordered_multiset<Ts...>&);
