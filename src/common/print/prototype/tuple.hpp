#pragma once
#include <iostream>
#include <tuple>
template<typename... Ts>
std::ostream& operator<<(std::ostream&, const std::tuple<Ts...>&);
