#pragma once
#include "../misc/common.hpp"
template<typename It>
Vec<int> manacher(It first, It last)
{
    auto get = [&](int i) { return *std::next(first, i); };
    const int sz = std::distance(first, last);
    Vec<int> ans(sz);
    for (int i = 0, k = 1, j = 0; i < sz; i += k, j -= k, k = 1) {
        while (i >= j and i + j < sz and get(i - j) == get(i + j)) {
            ++j;
        }
        ans[i] = j;
        while (i >= k and i + k < sz and k + ans[i - k] < j) {
            ans[i + k] = ans[i - k];
            k++;
        }
    }
    return ans;
}
