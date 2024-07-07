#pragma once
#include "../internal.hpp"
template <typename V> auto z_algorithm(const V& vs) -> Vec<int> {
    const int N = std::size(vs);
    Vec<int> ans(N, -1);
    for (int i = 1, j = 0; i < N;) {
        while (i + j < N and vs[j] == vs[i + j]) { j++; }
        ans[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (i + k < N and k + ans[k] < j) {
            ans[i + k] = ans[k];
            k++;
        }
        i += k, j -= k;
    }
    ans[0] = N;
    return ans;
}
