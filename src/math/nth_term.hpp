#pragma once
#include "../misc/common.hpp"
#include "berlekamp_massey.hpp"
#include "fps_div_nth.hpp"
template<typename mint, typename I>
mint nthTerm(const Vec<mint>& as, I N)
{
    const FPS g{berlekampMassey(as)};
    const int L = g.size();
    const auto f = FPS<mint>{as}.mult(g, L - 1);
    return divNth(f, g, N);
}
