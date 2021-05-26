#pragma once
#include "type_alias.hpp"
#pragma region VecUtils
template<typename T>
void fillAll(Vec<T>& vs, const T& v)
{
    std::fill(vs.begin(), vs.end(), v);
}
template<typename T, typename C = Lt<T>>
void sortAll(Vec<T>& vs, C comp = C{})
{
    std::sort(vs.begin(), vs.end(), comp);
}
template<typename T>
void reverseAll(Vec<T>& vs)
{
    std::reverse(vs.begin(), vs.end());
}
template<typename T>
void uniqueAll(Vec<T>& vs)
{
    sortAll(vs);
    vs.erase(std::unique(vs.begin(), vs.end()), vs.end());
}
template<typename T, typename V = T>
V sumAll(const Vec<T>& vs)
{
    return std::accumulate(vs.begin(), vs.end(), V{});
}
template<typename T>
int minInd(const Vec<T>& vs)
{
    return std::min_element(vs.begin(), vs.end()) - vs.begin();
}
template<typename T>
int maxInd(const Vec<T>& vs)
{
    return std::max_element(vs.begin(), vs.end()) - vs.begin();
}
template<typename T>
int lbInd(const Vec<T>& vs, const T& v)
{
    return std::lower_bound(vs.begin(), vs.end(), v) - vs.begin();
}
template<typename T>
int ubInd(const Vec<T>& vs, const T& v)
{
    return std::upper_bound(vs.begin(), vs.end(), v) - vs.begin();
}
template<typename T, typename F>
Vec<T> genVec(int n, F gen)
{
    Vec<T> ans;
    std::generate_n(std::back_insert_iterator(ans), n, gen);
    return ans;
}
Vec<int> iotaVec(int n, int offset = 0)
{
    Vec<int> ans(n);
    std::iota(ans.begin(), ans.end(), offset);
    return ans;
}
template<typename T>
Vec<T> revVec(const Vec<T>& vs)
{
    auto ans = vs;
    reverseAll(ans);
    return ans;
}
#pragma endregion
