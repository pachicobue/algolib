#pragma once
#include "print/int128_t.hpp"
#ifdef HOGEPACHI
#    include "print/array.hpp"
#    include "print/deque.hpp"
#    include "print/map.hpp"
#    include "print/multimap.hpp"
#    include "print/multiset.hpp"
#    include "print/pair.hpp"
#    include "print/priority_queue.hpp"
#    include "print/queue.hpp"
#    include "print/set.hpp"
#    include "print/stack.hpp"
#    include "print/tuple.hpp"
#    include "print/unordered_map.hpp"
#    include "print/unordered_multimap.hpp"
#    include "print/unordered_multiset.hpp"
#    include "print/unordered_set.hpp"
#    include "print/vector.hpp"
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
