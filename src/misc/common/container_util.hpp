#pragma once
#include "type_alias.hpp"
template<typename Vs, typename V>
void fillAll(Vs& arr, const V& v)
{
    if constexpr (std::is_convertible<V, Vs>::value) {
        arr = v;
    } else {
        for (auto& subarr : arr) {
            fillAll(subarr, v);
        }
    }
}
template<typename Vs>
void sortAll(Vs& vs)
{
    std::sort(std::begin(vs), std::end(vs));
}
template<typename Vs, typename C>
void sortAll(Vs& vs, C comp)
{
    std::sort(std::begin(vs), std::end(vs), comp);
}
template<typename Vs>
void reverseAll(Vs& vs)
{
    std::reverse(std::begin(vs), std::end(vs));
}
template<typename V, typename Vs>
V sumAll(const Vs& vs)
{
    if constexpr (std::is_convertible<Vs, V>::value) {
        return static_cast<V>(vs);
    } else {
        V ans = 0;
        for (const auto& v : vs) {
            ans += sumAll<V>(v);
        }
        return ans;
    }
}
template<typename Vs>
int minInd(const Vs& vs)
{
    return std::min_element(std::begin(vs), std::end(vs)) - std::begin(vs);
}
template<typename Vs>
int maxInd(const Vs& vs)
{
    return std::max_element(std::begin(vs), std::end(vs)) - std::begin(vs);
}
template<typename Vs, typename V>
int lbInd(const Vs& vs, const V& v)
{
    return std::lower_bound(std::begin(vs), std::end(vs), v) - std::begin(vs);
}
template<typename Vs, typename V>
int ubInd(const Vs& vs, const V& v)
{
    return std::upper_bound(std::begin(vs), std::end(vs), v) - std::begin(vs);
}
template<typename Vs, typename V>
bool contains(const Vs& vs, const V& v)
{
    const int li = lbInd(vs, v);
    return (li < std::size(vs) and vs[li] == v);
}
template<typename Vs, typename V>
void plusAll(Vs& vs, const V& v)
{
    for (auto& v_ : vs) {
        v_ += v;
    }
}
template<typename T, typename F>
Vec<T> genVec(int n, F gen)
{
    Vec<T> ans;
    std::generate_n(std::back_insert_iterator(ans), n, gen);
    return ans;
}
template<typename T = int>
Vec<T> iotaVec(int n, T offset = 0)
{
    Vec<T> ans(n);
    std::iota(ans.begin(), ans.end(), offset);
    return ans;
}
