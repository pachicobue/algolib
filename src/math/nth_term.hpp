#pragma once
#include "../common.hpp"
#include "berlekamp_massey.hpp"
#include "bostan_mori.hpp"
template<typename mint, typename I>
mint nthTerm(const Vec<mint>& as, I N)
{
    const FPS g{berlekampMassey(as)};
    const int L = g.size();
    const auto f = FPS<mint>{as}.mult(g, L - 1);
    return bostanMori(f, g, N);
}
