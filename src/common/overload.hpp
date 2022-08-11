#pragma once
#include "type.hpp"
template<typename T>
constexpr Vec<T>& operator+=(Vec<T>& vs1, const Vec<T>& vs2)
{
    return vs1.insert(vs1.end(), vs2.begin(), vs2.end()), vs1;
}
template<typename T>
constexpr Vec<T> operator+(const Vec<T>& vs1, const Vec<T>& vs2)
{
    auto vs = vs1;
    vs += vs2;
    return vs;
}
