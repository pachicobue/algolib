#pragma once
#include "type_alias.hpp"
template<typename T>
Vec<T>& operator+=(Vec<T>& vs1, const Vec<T>& vs2)
{
    vs1.insert(vs1.end(), vs2.begin(), vs2.end());
    return vs1;
}
template<typename T>
Vec<T> operator+(const Vec<T>& vs1, const Vec<T>& vs2)
{
    auto vs = vs1;
    vs += vs2;
    return vs;
}
