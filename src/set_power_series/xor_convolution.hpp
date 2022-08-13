#pragma once
#include "../common.hpp"
#include "set_hadamard.hpp"
template<typename T>
Vec<T> xorConvolute(Vec<T> f, Vec<T> g)
{
    const int N = ceil2(std::max(f.size(), g.size()));
    f.resize(N), g.resize(N);
    auto F = setHadamard(f, false), G = setHadamard(g, false);
    for (int i : rep(N)) { F[i] *= G[i]; }
    return setHadamard(F, true);
}
