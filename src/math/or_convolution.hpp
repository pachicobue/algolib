#pragma once
#include "../common.hpp"
#include "and_convolution.hpp"
template<typename T>
Vec<T> orConvolute(Vec<T> f, Vec<T> g)
{
    const int N = ceil2(std::max(f.size(), g.size()));
    f.resize(N), g.resize(N);
    auto F = setZeta(f, true), G = setZeta(g, true);
    for (int i : rep(N)) { F[i] *= G[i]; }
    return setMoebius(F, true);
}
