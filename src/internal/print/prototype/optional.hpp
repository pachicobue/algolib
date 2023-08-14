#pragma once
#include <optional>
#include <iostream>
template<typename T> std::ostream& operator<<(std::ostream& os, const std::optional<T>& v);
