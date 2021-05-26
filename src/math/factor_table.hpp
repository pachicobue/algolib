#pragma once
#include "../misc/common.hpp"
Vec<int> factorTable(const int sup)
{
    Vec<int> fact = iotaVec(sup);
    for (int i = 2; i < sup; i++) {
        if (fact[i] != i) { continue; }
        for (int j = i + i; j < sup; j += i) {
            fact[j] = i;
        }
    }
    return fact;
}
