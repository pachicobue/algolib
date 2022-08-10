#pragma once
#include "type.hpp"
template<typename T>
Vec<T>& operator+=(Vec<T>& vs1, const Vec<T>& vs2)
{
    return vs1.insert(vs1.end(), vs2.begin(), vs2.end()), vs1;
}
template<typename T>
Vec<T> operator+(const Vec<T>& vs1, const Vec<T>& vs2)
{
    return Vec<T>{vs1} += vs2;
}
