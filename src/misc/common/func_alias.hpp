#pragma once
#include "type_alias.hpp"
#pragma region FuncAlias
template<typename T>
bool chmin(T& a, const T& b)
{
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<typename T>
bool chmax(T& a, const T& b)
{
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<typename T>
constexpr T fdiv(T x, T y)
{
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? x / y : (x - y + 1) / y;
}
template<typename T>
constexpr T cdiv(T x, T y)
{
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? (x + y - 1) / y : x / y;
}
template<typename T, typename I>
constexpr T modPower(T v, I n, T mod)
{
    T ans = 1 % mod;
    for (; n > 0; n >>= 1, (v *= v) %= mod) {
        if (n % 2 == 1) { (ans *= v) %= mod; }
    }
    return ans;
}
template<typename T, typename I>
constexpr T power(T v, I n)
{
    T ans = 1;
    for (; n > 0; n >>= 1, v *= v) {
        if (n % 2 == 1) { ans *= v; }
    }
    return ans;
}
template<typename T, typename I>
constexpr T power(T v, I n, const T& e)
{
    T ans = e;
    for (; n > 0; n >>= 1, v *= v) {
        if (n % 2 == 1) { ans *= v; }
    }
    return ans;
}
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
template<typename T>
void iotaAll(Vec<T>& vs, T offset = T{})
{
    std::iota(vs.begin(), vs.end(), offset);
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
    return std::lower_bound(vs.begin(), vs.end(), v) - vs.begin();
}
template<typename Vs, typename F>
void eraseIf(Vs& vs, F f)
{
    vs.erase(std::remove_if(vs.begin(), vs.end(), f), vs.end());
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
    iotaAll(ans, offset);
    return ans;
}
template<typename T, typename F = Lt<T>>
Vec<int> iotaVec(const Vec<T>& vs, F comp = F{})
{
    auto is = iotaVec(vs.size(), 0);
    sortAll(is, [&](int i, int j) { return comp(vs[i], vs[j]); });
    return is;
}
template<typename T>
Vec<T> operator+=(Vec<T>& vs1, const Vec<T>& vs2)
{
    vs1.insert(vs1.end(), vs2.begin(), vs2.end());
    return vs1;
}
template<typename T>
Vec<T> operator+(const Vec<T>& vs1, const Vec<T>& vs2)
{
    return Vec<T>{vs1} += vs2;
}
#pragma endregion
