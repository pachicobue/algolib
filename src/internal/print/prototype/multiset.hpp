#pragma once
#include <iostream>
#include <set>
template <typename... Ts>
std::ostream& operator<<(std::ostream&, const std::multiset<Ts...>&);
