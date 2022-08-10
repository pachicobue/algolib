#pragma once
#include "../common.hpp"
#include "divisors_moebius.hpp"
#include "divisors_zeta.hpp"
template<typename T>
Vec<T> gcdConvolute(const Vec<T>& f, const Vec<T>& g)
{
    const int N = (int)std::min(f.size(), g.size());
    auto F = divisorsZeta(f, false), G = divisorsZeta(g, false);
    F.resize(N), G.resize(N);
    for (int i : rep(N)) {
        F[i] *= G[i];
    }
    return divisorsMoebius(F, false);
}
