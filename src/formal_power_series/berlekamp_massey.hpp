#pragma once
#include "../common.hpp"

template<typename T>
Vec<T> berlekampMassey(const Vec<T>& A)
{
    const int N = (int)A.size();
    Vec<T> B{1}, C{1};
    T b = 1;
    for (int j : irange(1, N + 1)) {
        int m = (int)B.size(), l = (int)C.size();
        T d = 0;
        for (int i : rep(l)) { d += A[j - l + i] * C[i]; }
        B.push_back(0), m++;
        if (d == 0) { continue; }
        const T c = -d / b;
        if (l < m) {
            auto temp = C;
            C.insert(C.begin(), m - l, 0);
            for (int i : rep(m)) { C[m - 1 - i] += c * B[m - 1 - i]; }
            B = temp, b = d;
        } else {
            for (int i : rep(m)) { C[l - 1 - i] += c * B[m - 1 - i]; }
        }
    }
    reverseAll(C);
    return C;
}
