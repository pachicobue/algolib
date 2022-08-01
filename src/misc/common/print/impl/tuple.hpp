#pragma once
#include <iostream>
#include <tuple>
namespace print_tuple_impl {
template<int n = 0, typename... Ts>
void dump(std::ostream& os, const std::tuple<Ts...>& v)
{
    constexpr int N = std::tuple_size<std::tuple<Ts...>>::value;
    if constexpr (n < N) {
        os << std::get<n>(v) << (n == N - 1 ? "" : ","), dump<n + 1>(os, v);
    }
}
}  // namespace print_tuple_impl
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& v)
{
    return (os << "("), print_tuple_impl::dump(os, v), (os << ")");
}
