#pragma once
#include <iostream>
#include <optional>
template <typename T> std::ostream& operator<<(std::ostream& os, const std::optional<T>& v);
