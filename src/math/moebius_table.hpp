#pragma once
#include "../misc/common.hpp"
#include "factor_table.hpp"
Vec<int> moebiusTable(const int sup)
{
    const auto f_table = factorTable(sup);
    auto moebius = [&](int n) {
        int ans = 1;
        for (int prev = 1; n > 1; prev = f_table[n], n /= prev, ans = -ans) {
            if (prev == f_table[n]) { return 0; }
        }
        return ans;
    };
    Vec<int> ans(sup, 0);
    for (int i : rep(sup)) {
        ans[i] = moebius(i);
    }
    return ans;
}
