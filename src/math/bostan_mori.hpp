#pragma once
#include "fps.hpp"
template<typename mint, typename I>
mint bostanMori(FPS<mint> f, FPS<mint> g, I N)
{
    assert(not g.isZero());
    const int f_zero = f.lsb(), g_zero = g.lsb();
    assert(g_zero <= f_zero);
    if (N < I(f_zero - g_zero)) { return 0; }
    f <<= f_zero, g <<= g_zero;
    N -= (f_zero - g_zero);

    while (N > 0) {
        f.shrink(N + 1), g.shrink(N + 1);
        FPS<mint> mg;
        for (int i : rep(g.size())) {
            mg[i] = g[i] * (i % 2 == 0 ? 1 : -1);
        }
        const auto G = g * mg;
        const auto F = f * mg;
        for (int i : rep(f.size())) {
            f[i] = F.at(2 * i + (N % 2));
        }
        for (int i : rep(g.size())) {
            g[i] = G.at(2 * i);
        }
        N /= 2;
    }
    return f[0] / g[0];
}
