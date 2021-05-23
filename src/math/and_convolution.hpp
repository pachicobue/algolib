#pragma once
#include "../misc/common.hpp"
#include "set_moebius.hpp"
#include "set_zeta.hpp"
template<typename T>
Vec<T> andConvolute(Vec<T> f, Vec<T> g)
{
    const int N = ceil2(std::max(f.size(), g.size()));
    f.resize(N), g.resize(N);
    auto F = setZeta(f, false), G = setZeta(g, false);
    for (int i : rep(N)) {
        F[i] *= G[i];
    }
    return setMoebius(F, false);
}
