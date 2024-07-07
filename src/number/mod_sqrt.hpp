#pragma once
#include <cassert>
#include <optional>
#include "../internal.hpp"

/**
 * @brief X^2=A (mod P) となる X
 * @attention P は素数とすること
 * @see https://37zigen.com/tonelli-shanks-algorithm
 *
 * @param A
 * @return Opt<mint> X^2=A (mod P) となる X (存在しない場合は std::nullopt )
 */
template <typename mint> auto modSqrt(const mint& A) -> Opt<mint> {
    const u64 P = mint::mod();
    if (A == 0) { return 0; }
    if (P == 2) { return 1; }
    if (A.pow((P - 1) / 2) != 1) { return std::nullopt; }
    const int q = order2(P - 1);
    const i64 Q = (i64)(P >> q);
    auto ordLog = [&](mint X) -> int { // order_2(log(X)) (但し log(X)=0 (mod Q))
        for (int i : per(q + 1)) {
            if (X == 1) { return i; }
            X *= X;
        }
        return 0;
    };

    mint Eraser = 1; // log(Eraser)=1 (mod 2)　かつ log(Eraser)=0 (mod Q)
    for (mint Z = 2;; Z += 1) {
        Eraser = Z.pow(Q);
        if (ordLog(Eraser) == 0) { break; }
    }
    Vec<mint> pErasers(q, Eraser); // pEraser[i] = Eraser^(2^i)
    for (int i : rep(q - 1)) { pErasers[i + 1] = pErasers[i] * pErasers[i]; }

    mint X = A.pow((Q + 1) / 2), Error = A.pow(Q); // Error=X^2/A (以降 log(Error)=0 (mod Q) )
    while (Error != 1) {
        const int o = ordLog(Error);
        assert(o >= 1);
        X *= pErasers[o - 1], Error *= pErasers[o];
    }
    return X;
}
