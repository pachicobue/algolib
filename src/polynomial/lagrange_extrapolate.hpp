#pragma once
#include "../common.hpp"

template<typename mint>
mint lagrangeExtrapolate(const Vec<mint>& ys, const mint& X)
{
    const int N = ys.size();
    const int x = X.val();
    if (x < N) { return ys[x]; }
    Vec<mint> ls(N, 1), rs(N, 1);
    for (int i : rep(N - 1)) { ls[i + 1] = ls[i] * (X - i); }
    for (int i : per(N - 1)) { rs[i] = rs[i + 1] * (X - i - 1); }
    Vec<mint> Fs(N);
    Vec<mint> Gs(N);
    for (int i : rep(N)) {
        Fs[i] = ys[i] * mint::ifact(i) * mint::ifact(N - 1 - i) * ((N - 1 - i) % 2 == 0 ? 1 : -1);
        Gs[i] = ls[N - 1 - i] * rs[N - 1 - i];
    }
    mint ans = 0;
    for (int i : rep(N)) { ans += Fs[i] * Gs[N - 1 - i]; }
    return ans;
}
