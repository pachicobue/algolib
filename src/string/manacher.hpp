#pragma once
#include "../common.hpp"
template<typename V> Vec<int> manacher(const V& vs)
{
    const int N = std::size(vs);
    Vec<int> ans(N);
    for (int i = 0, k = 1, j = 0; i < N; i += k, j -= k, k = 1) {
        while (i >= j and i + j < N and vs[i - j] == vs[i + j]) { ++j; }
        ans[i] = j;
        while (i >= k and i + k < N and k + ans[i - k] < j) {
            ans[i + k] = ans[i - k];
            k++;
        }
    }
    return ans;
}
