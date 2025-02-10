#pragma once
#include <iostream>
#include <vector>
template <typename... Ts>
std::ostream& operator<<(std::ostream&, const std::vector<Ts...>&);
