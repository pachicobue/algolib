#pragma once
#include "../misc/common.hpp"
template<typename T>
Vec<T> divisors(const T n)
{
    Vec<T> head, tail;
    for (T i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            head.push_back(i);
            if (i * i != n) { tail.push_back(n / i); }
        }
    }
    std::copy(tail.begin(), tail.end(), head.end());
    return head;
}
