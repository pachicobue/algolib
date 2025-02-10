#pragma once
#include <array>
#include <iostream>
template <typename T, std::size_t n>
std::ostream& operator<<(std::ostream&, const std::array<T, n>&);
