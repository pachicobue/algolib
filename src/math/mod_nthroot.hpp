#pragma once
#include "../misc/common.hpp"
#include "../data_structure/intdict.hpp"
#include "extgcd.hpp"
#include "prime_factors.hpp"

template<typename mint>
mint modNthRoot(mint A, u64 k)
{
    const u64 P = mint::mod();
    if (A == 0) { return 0; }
    if (k == 0) { return A; }
    const u64 g = std::gcd(P - 1, k);
    if (A.pow((P - 1) / g).val() != 1) { return 0; }
    A = A.pow(inverse<u128>(k / g, (P - 1) / g));

    if (g == 1) { return A; }
    const auto fs = primeFactors(g);
    for (const auto& [p, e] : fs) {
        u64 pe = 1;
        for (int i = 0; i < e; i++) {
            pe *= p;
        }
        u64 q = P - 1, Q = 0;
        while (q % p == 0) {
            q /= p, Q++;
        }
        const u64 y = pe - inverse<u128>(q, pe);
        const u64 z = ((u128)y * q + 1) / (u128)pe;
        mint X = A.pow(z);
        if ((int)Q == e) {
            A = X;
            continue;
        }

        mint Eraser = 1;
        const u64 h = (P - 1) / p;
        for (mint Z = 2;; Z += 1) {
            if (Z.pow(h) != 1) {
                Eraser = Z.pow(q);
                break;
            }
        }
        mint Error = A.pow((u128)y * q);

        mint pEraser = Eraser;
        for (u64 i = 0; i < Q - 1; i++) {
            pEraser = pEraser.pow(p);
        }
        const mint ipEraser = pEraser.inv();

        IntDict<u64, u64> memo;
        {
            const u64 M
                = std::max(1_u64, (u64)(std::sqrt(p) * std::sqrt(Q - e)));
            const u64 B = std::max(1_u64, ((u64)p - 1) / M);
            const mint ppEraser = pEraser.pow(B);
            mint prod = 1;
            for (u64 i = 0; i < p; i += B, prod *= ppEraser) {
                memo[prod.val()] = i;
            }
        }

        while (Error.val() != 1) {
            u64 l = 0;
            mint pError = Error;
            for (u64 i = 0; i < Q; i++) {
                const auto npError = pError.pow(p);
                if (npError == 1) {
                    l = Q - (i + 1);
                    break;
                }
                pError = npError;
            }

            u64 c = -1;
            {
                mint small = pError.inv();
                for (u64 j = 0;; j++, small *= ipEraser) {
                    if (memo.contains(small.val())) {
                        const u64 i = memo[small.val()];
                        c = i + j;
                        break;
                    }
                }
            }
            auto pEraser2 = Eraser.pow(c);
            for (u64 i = 0; i < l - e; i++) {
                pEraser2 = pEraser2.pow(p);
            }
            X *= pEraser2, Error *= pEraser2.pow(pe);
        }
        A = X;
    }
    return A;
}
