#pragma once
#include "../common.hpp"
template<typename V> Vec<int> morrisPratt(const V& vs)
{
    const int N = std::size(vs);
    Vec<int> A(N + 1, -1);
    for (int i = 0, j = -1; i < N; i++) {
        while (j != -1 and vs[i] != vs[j]) { j = A[j]; }
        j        = (j == -1 ? 0 : j + 1);
        A[i + 1] = j;
    }
    return A;
}
