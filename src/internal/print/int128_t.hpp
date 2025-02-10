#pragma once
#include <algorithm>
#include "../type.hpp"
inline Ostream& operator<<(Ostream& os, u128 v) {
    Str ans;
    if (v == 0) {
        ans = "0";
    }
    while (v) {
        ans.push_back('0' + v % 10), v /= 10;
    }
    std::reverse(ans.begin(), ans.end());
    return os << ans;
}
inline Ostream& operator<<(Ostream& os, i128 v) {
    bool minus = false;
    if (v < 0) {
        minus = true, v = -v;
    }
    return os << (minus ? "-" : "") << (u128)v;
}
