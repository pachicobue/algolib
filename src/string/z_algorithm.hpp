#pragma once
#include "../common.hpp"
template<typename It>
Vec<int> z_algorithm(It first, It last)
{
    auto get = [&](int i) { return *std::next(first, i); };
    const int sz = std::distance(first, last);
    Vec<int> ans(sz, -1);
    for (int i = 1, j = 0; i < sz;) {
        while (i + j < sz and get(j) == get(i + j)) { j++; }
        ans[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (i + k < sz and k + ans[k] < j) {
            ans[i + k] = ans[k];
            k++;
        }
        i += k, j -= k;
    }
    ans[0] = sz;
    return ans;
}
