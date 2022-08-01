#pragma once
#include "print/int128_t.hpp"
#ifdef HOGEPACHI
#    include "print/print_stl.hpp"
namespace show_impl {
template<typename T>
void dump(T x)
{
    std::cerr << x;
}
template<typename T, typename... Args>
void dump(T x, Args... args)
{
    std::cerr << x << ",", dump(args...);
}
}  // namespace show_impl
#    define SHOW(...)                                  \
        (std::cerr << "LINE " << __LINE__ << ": "      \
                   << "(" << #__VA_ARGS__ << ") = ("), \
            show_impl::dump(__VA_ARGS__), std::cerr << ")" << std::endl
#else
#    define SHOW(...) void(0)
#endif
