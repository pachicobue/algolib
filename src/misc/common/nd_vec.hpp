#pragma once
#include "type_alias.hpp"
#pragma region NdVec
template<typename T, int n, int i = 0>
auto ndVec(int const (&szs)[n], const T x = T{})
{
    if constexpr (i == n) {
        return x;
    } else {
        return std::vector(szs[i], ndVec<T, n, i + 1>(szs, x));
    }
}
#pragma endregion
