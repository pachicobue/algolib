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
template<typename Vs>
constexpr Vs reversed(const Vs& vs)
{
    auto rvs = vs;
    reverseAll(rvs);
    return rvs;
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
    std::copy(ALL(vs2), std::back_inserter(vs1));
}
template<typename Vs>
constexpr void concatted(const Vs& vs1, const Vs& vs2)
{
    auto vs = vs1;
    concat(vs, vs2);
    return vs;
}
template<typename T, typename F>
constexpr Vec<T> genVec(int n, F gen)
{
    Vec<T> ans;
    std::generate_n(std::back_inserter(ans), n, gen);
    return ans;
}
template<typename T = int>
constexpr Vec<T> iotaVec(int n, T offset = 0)
{
    Vec<T> ans(n);
    std::iota(ALL(ans), offset);
    return ans;
}
template<typename Vs>
constexpr void rearrange(Vs& vs, const Vec<int>& is)
{
    auto vs_ = vs;
    for (int i = 0; i < (int)is.size(); i++) { vs[i] = vs_[is[i]]; }
}
inline Vec<int> reversePerm(const Vec<int>& is)
{
    auto ris = is;
    for (int i = 0; i < (int)is.size(); i++) { ris[is[i]] = i; }
    return ris;
}
