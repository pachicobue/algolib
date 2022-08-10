#pragma once
#include "../common.hpp"
template<typename mint>
mint modsqrt(const mint& A)
{
    const u64 P = mint::mod();
    if (A == 0) { return 0; }
    if (P == 2) { return 1; }
    const u64 h = (P - 1) >> 1;
    if (A.pow(h).val() != 1) { return 0; }
    u64 q = P - 1, Q = 0;
    while ((q & 1) == 0) {
        q >>= 1, Q++;
    }
    mint Eraser = 1;
    for (mint Z = 2;; Z += 1) {
        if (Z.pow(h) != 1) {
            Eraser = Z.pow(q);
            break;
        }
    }
    mint Error = A.pow(q), X = A.pow((q + 1) / 2);
    while (Error.val() != 1) {
        u64 l = 0;
        mint pError = Error;
        for (u64 i = 0; i < Q; i++, pError *= pError) {
            if (pError.val() == 1) {
                l = Q - i;
                break;
            }
        }
        mint pEraser = Eraser;
        for (u64 i = 0; i < l - 1; i++, pEraser *= pEraser) {}
        X *= pEraser, Error *= (pEraser * pEraser);
    }
    return X;
}
