#pragma once
#include "common.hpp"
template<typename T, typename F>
T binSearch(T ng, T ok, F check)
{
    while (std::abs(ok - ng) > 1) {
        const T mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    return ok;
}
