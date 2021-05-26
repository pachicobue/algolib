#pragma once
#include "../misc/common.hpp"
template<typename T>
Vec<bool> segSieve(T l, T r, const Vec<T>& ps)
{
    Vec<bool> ans = iotaVec(r - l, l);
    if (l <= 0 and 0 < r) { ans[0 - l] = false; }
    if (l <= 1 and 1 < r) { ans[1 - l] = false; }
    for (const T p : ps) {
        const T mq = std::max((l + p - 1) / p * p, p + p);
        for (T q = mq; q < r; q += p) {
            ans[q - l] = false;
        }
    }
    for (T p = l; p < r; p++) {
        if (not ans[p - l]) { continue; }
        for (T q = p + p; q < r; q += p) {
            ans[q - l] = false;
        }
    }
    return ans;
}
template<typename T>
Vec<bool> segSieve(T l, T r)
{
    T sqrt = 1;
    for (; (sqrt + 1) * (sqrt + 1) <= r; sqrt++) {}
    Vec<bool> isp(sqrt + 1, true);
    isp[0] = isp[1] = false;
    Vec<T> ps;
    for (T p = 2; p <= sqrt; p++) {
        if (not isp[p]) { continue; }
        ps.push_back(p);
        for (T q = p + p; q <= sqrt; q += p) {
            isp[q] = false;
        }
    }
    return segSieve(l, r, ps);
}
