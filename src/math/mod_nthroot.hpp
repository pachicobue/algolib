#pragma once
#include "../misc/common.hpp"
#include "../ds/intdict.hpp"
#include "extgcd.hpp"
#include "prime_factors.hpp"
template<typename mint>
mint modNthRoot(mint A, i64 k)
{
    const i64 P = mint::mod();
    assert(P > 0);
    if (A == 0) { return 0; }
    if (k == 0) { return A; }
    const i64 g = std::gcd(P - 1, k);
    if (A.pow((P - 1) / g).val() != 1) { return 0; }
    A = A.pow(inverse(k / g, (P - 1) / g));

    if (g == 1) { return A; }
    const auto fs = primeFactors(g);
    for (const auto& [p, e] : fs) {
        i64 pe = 1;
        LOOP (e) {
            pe *= p;
        }
        i64 q = P - 1, Q = 0;
        while (q % p == 0) {
            q /= p, Q++;
        }
        auto [y, z] = extgcd(-q, pe);
        if (y <= 0) { y += pe, z += q; }
        mint X = A.pow(z);
        if ((int)Q == e) {
            A = X;
            continue;
        }

        mint Eraser = 1;
        const i64 h = (P - 1) / p;
        for (mint Z = 2;; Z += 1) {
            if (Z.pow(h) != 1) {
                Eraser = Z.pow(q);
                break;
            }
        }
        mint Error = A.pow(y * q);

        mint pEraser = Eraser;
        LOOP (Q - 1) {
            pEraser = pEraser.pow(p);
        }
        const mint ipEraser = pEraser.inv();

        IntDict<i64, i64> memo;
        {
            const i64 M
                = std::max(1_i64, (i64)(std::sqrt(p) * std::sqrt(Q - e)));
            const i64 B = std::max(1_i64, ((i64)p - 1) / M);
            const mint ppEraser = pEraser.pow(B);
            mint prod = 1;
            for (i64 i = 0; i < p; i += B, prod *= ppEraser) {
                memo[prod.val()] = i;
            }
        }

        while (Error.val() != 1) {
            i64 l = 0;
            mint pError = Error;
            for (i64 i : rep(Q)) {
                const auto npError = pError.pow(p);
                if (npError == 1) {
                    l = Q - (i + 1);
                    break;
                }
                pError = npError;
            }

            i64 c = -1;
            {
                mint small = pError.inv();
                for (i64 j = 0;; j++, small *= ipEraser) {
                    if (memo.contains(small.val())) {
                        const i64 i = memo[small.val()];
                        c = i + j;
                        break;
                    }
                }
            }
            auto pEraser2 = Eraser.pow(c);
            LOOP (l - e) {
                pEraser2 = pEraser2.pow(p);
            }
            X *= pEraser2, Error *= pEraser2.pow(pe);
        }
        A = X;
    }
    return A;
}
