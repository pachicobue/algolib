#pragma once
#include <bits/stdc++.h>
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using f64 = double;
using f80 = long double;
using f128 = __float128;
constexpr i32 operator"" _i32(u64 v)
{
    return v;
}
constexpr i32 operator"" _u32(u64 v)
{
    return v;
}
constexpr i64 operator"" _i64(u64 v)
{
    return v;
}
constexpr u64 operator"" _u64(u64 v)
{
    return v;
}
constexpr f64 operator"" _f64(f80 v)
{
    return v;
}
constexpr f80 operator"" _f80(f80 v)
{
    return v;
}
using Istream = std::istream;
using Ostream = std::ostream;
using Str = std::string;
template<typename T>
using Lt = std::less<T>;
template<typename T>
using Gt = std::greater<T>;
template<typename T>
using IList = std::initializer_list<T>;
template<int n>
using BSet = std::bitset<n>;
template<typename T1, typename T2>
using Pair = std::pair<T1, T2>;
template<typename... Ts>
using Tup = std::tuple<Ts...>;
template<typename T, int N>
using Arr = std::array<T, N>;
template<typename... Ts>
using Deq = std::deque<Ts...>;
template<typename... Ts>
using Set = std::set<Ts...>;
template<typename... Ts>
using MSet = std::multiset<Ts...>;
template<typename... Ts>
using USet = std::unordered_set<Ts...>;
template<typename... Ts>
using UMSet = std::unordered_multiset<Ts...>;
template<typename... Ts>
using Map = std::map<Ts...>;
template<typename... Ts>
using MMap = std::multimap<Ts...>;
template<typename... Ts>
using UMap = std::unordered_map<Ts...>;
template<typename... Ts>
using UMMap = std::unordered_multimap<Ts...>;
template<typename... Ts>
using Vec = std::vector<Ts...>;
template<typename... Ts>
using Stack = std::stack<Ts...>;
template<typename... Ts>
using Queue = std::queue<Ts...>;
template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, Vec<T>, Gt<T>>;

using NSec = std::chrono::nanoseconds;
using USec = std::chrono::microseconds;
using MSec = std::chrono::milliseconds;
using Sec = std::chrono::seconds;
