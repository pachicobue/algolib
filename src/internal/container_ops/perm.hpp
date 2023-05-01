#pragma once
#include "../type.hpp"
#include "../macro.hpp"

template<typename T = int>
constexpr Vec<T> iotaVec(int n, T offset = 0)
{
    Vec<T> ans(n);
    std::iota(ALL(ans), offset);
    return ans;
}
template<typename Vs, typename... Args>
constexpr Vec<int> iotaSort(const Vs& vs, Args... args)
{
    auto is = iotaVec(vs.size());
    std::sort(ALL(is), args...);
    return is;
}
inline Vec<int> permInv(const Vec<int>& is)
{
    auto ris = is;
    for (int i = 0; i < (int)is.size(); i++) { ris[is[i]] = i; }
    return ris;
}
