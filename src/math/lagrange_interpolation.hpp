#pragma once
#include "../misc/common.hpp"
#include "fps.hpp"
template<typename mint>
FPS<mint> lagrangeInterpolate(const Vec<mint> ys)
{
    const int N = ys.size();
    Vec<mint> fs(N + 1);
    iotaAll(fs);
    for (int i = 2; i <= N; i++) {
        fs[i] = fs[i - 1] * i;
    }

    Vec<mint> as(N + 1);
    for (int i = 0; i <= N; i++) {
        mint res = fs[i];
        for (int j = 0; j < i; j++) {
            res -= as[i] * mint::fact(i) * mint::ifact(i - j);
        }
        as[i] = res * mint::ifact(i);
    }
    FPS<mint> ans, g{1};
    for (int i = 0; i <= N; i++) {
        ans += as[i] * g;
        g *= FPS<mint>{1, -i};
    }
    return ans;
}
