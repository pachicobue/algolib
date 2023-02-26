#pragma once
#include "../common.hpp"
#include "../utility/int_nthroot.hpp"
#include "../algorithm/babystep_giantstep.hpp"

template<typename mint>
inline i64 discreteLog(mint X, mint Y)
{
    static_assert(mint::isDynamic(), "Only dynamic-modint supportted!");
    i64 P = mint::mod();
    if (P == 1) { return 0; }
    if (X == 0) { return (Y == 1 ? 0 : (Y == 0 ? 1 : -1)); }

    mint pX = 1;
    const int offset = bitWidth(P);
    for (int d : rep(offset)) {
        if (pX == Y) { return d; }
        pX *= X;
    }
    const i64 g = std::gcd((i64)pX.val(), P);
    if (Y.val() % g != 0) { return -1; }
    const i64 nP = P / g;
    mint::setMod(nP);
    const mint npX = pX.val();
    const mint nX = X.val(), nY = npX.inv() * Y.val();
    const i64 W = intNthRoot(nP, 2);
    const mint nXW = nX.pow(W), nXI = nX.inv();
    auto f_wtimes = [&](i64 x) { return (nXW * x).val(); };
    auto f_inv = [&](i64 x) { return (nXI * x).val(); };
    const i64 n
        = (nY == 1 ? 0_i64
                   : babyStepGiantStep(f_wtimes, f_inv, (i64)nX.val(), (i64)nY.val(), nP, W));
    mint::setMod(P);

    if (n == -1) { return -1; }
    return offset + n;
}
