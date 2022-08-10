#pragma once
#include <iostream>
#include <map>
template<typename... Ts>
std::ostream& operator<<(std::ostream&, const std::multimap<Ts...>&);
