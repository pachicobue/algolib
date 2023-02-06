#pragma once
#include "type.hpp"
#include "macro.hpp"
template<typename Vs, typename V>
constexpr void fillAll(Vs& arr, const V& v)
{
    if constexpr (std::is_convertible<V, Vs>::value) {
        arr = v;
    } else {
        for (auto& subarr : arr) { fillAll(subarr, v); }
    }
}
template<typename Vs>
constexpr void sortAll(Vs& vs)
{
    std::sort(ALL(vs));
}
template<typename Vs, typename C>
constexpr void sortAll(Vs& vs, C comp)
{
    std::sort(ALL(vs), comp);
}
template<typename Vs>
constexpr void reverseAll(Vs& vs)
{
    std::reverse(ALL(vs));
}
template<typename V, typename Vs>
constexpr V sumAll(const Vs& vs)
{
    if constexpr (std::is_convertible<Vs, V>::value) {
        return static_cast<V>(vs);
    } else {
        V ans = 0;
        for (const auto& v : vs) { ans += sumAll<V>(v); }
        return ans;
    }
}
template<typename Vs>
constexpr int minInd(const Vs& vs)
{
    return std::min_element(ALL(vs)) - std::begin(vs);
}
template<typename Vs>
constexpr int maxInd(const Vs& vs)
{
    return std::max_element(ALL(vs)) - std::begin(vs);
}
template<typename Vs, typename V>
constexpr int lbInd(const Vs& vs, const V& v)
{
    return std::lower_bound(ALL(vs), v) - std::begin(vs);
}
template<typename Vs, typename V>
constexpr int ubInd(const Vs& vs, const V& v)
{
    return std::upper_bound(ALL(vs), v) - std::begin(vs);
}
template<typename Vs, typename V>
constexpr void plusAll(Vs& vs, const V& v)
{
    for (auto& v_ : vs) { v_ += v; }
}
template<typename Vs>
constexpr void concat(Vs& vs1, const Vs& vs2)
{
    for (const auto& v2 : vs2) { vs1.push_back(v2); }
}
template<typename T, typename F>
constexpr Vec<T> genVec(int n, F gen)
{
    Vec<T> ans;
    std::generate_n(std::back_insert_iterator(ans), n, gen);
    return ans;
}
template<typename T = int>
constexpr Vec<T> iotaVec(int n, T offset = 0)
{
    Vec<T> ans(n);
    std::iota(ans.begin(), ans.end(), offset);
    return ans;
}
