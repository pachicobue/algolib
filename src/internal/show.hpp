#pragma once
#include <iostream>
#include <source_location>
#include "print/int128_t.hpp" // IWYU pragma: export
#ifdef HOGEPACHI
#include "print/print_stl.hpp" // IWYU pragma: export
namespace show_impl {
auto dump(auto x, auto... args) -> void {
    std::cerr << x;
    if constexpr (sizeof...(args) > 0) { std::cerr << ", ", dump(args...); }
}
} // namespace show_impl

#define SHOW(...)                                                            \
    ((std::cerr << "LINE " << std::source_location::current().line() << ": " \
                << "(" << #__VA_ARGS__ << ") = ("),                          \
     show_impl::dump(__VA_ARGS__),                                           \
     std::cerr << ")" << std::endl)
#else
#define SHOW(...) void(0)
#endif
