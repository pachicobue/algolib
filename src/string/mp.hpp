#pragma once
#include "../misc/common.hpp"
template<typename It>
Vec<int> mp(It first, It last)
{
    auto get = [&](int i) { return *std::next(first, i); };
    const int sz = std::distance(first, last);
    Vec<int> A(sz + 1, -1);
    for (int i = 0, j = -1; i < sz; i++) {
        while (j != -1 and get(i) != get(j)) {
            j = A[j];
        }
        j = (j == -1 ? 0 : j + 1);
        A[i + 1] = j;
    }
    return A;
}
