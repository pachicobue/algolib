#pragma once
#include "../misc/common.hpp"
#include "divisors_moebius.hpp"
#include "divisors_zeta.hpp"
template<typename T>
Vec<T> lcmConvolute(const Vec<T>& f, const Vec<T>& g)
{
    const int N = (int)std::min(f.size(), g.size());
    auto F = divisorsZeta(f, true), G = divisorsZeta(g, true);
    F.resize(N), G.resize(N);
    for (int i : rep(N)) {
        F[i] *= G[i];
    }
    return divisorsMoebius(F, true);
}
