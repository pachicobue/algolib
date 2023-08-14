#pragma once
#include "../common.hpp"
#include "../algorithm/ext_gcd.hpp"
#include "../utility/int_nthroot.hpp"
#include "pollard_rho.hpp"
/**
 * @brief X^K=A (mod P)
 * @attention P は素数とすること
 * @see https://yukicoder.me/problems/no/981/editorial
 * 
 * @param A 
 * @param K 
 * @return Opt<mint> X^K=A (mod P) となる X (存在しない場合は std::nullopt )
 */
template<typename mint> Opt<mint> modNthRoot(mint A, i64 K)
{
    constexpr auto Null = std::nullopt;
    const i64 P         = mint::mod();
    if (K == 0) { return A == 1 ? Opt<mint>{1_i64} : Opt<mint>{Null}; }
    if (A == 0 or A == 1) { return A; }
    const i64 g = std::gcd(P - 1, K);
    if (A.pow((P - 1) / g) != 1) { return Null; }
    A = A.pow(inverseMod(K / g, (P - 1) / g));  // g*log(X)-log(A)=0 (mod (P-1)) に変形
    if (g == 1) { return A; }

    Vec<Tup<i64, int, int>> factors;  // (素因数p, ord_p(g), ord_p(P-1))
    {
        i64 Q = P - 1;
        for (const auto& [p, a] : primeFactors(g)) {
            int b = 0;
            while (Q % p == 0) { Q /= p, b++; }
            factors.push_back({p, a, b});
        }
    }

    for (const auto& [p, a, b] : factors) {  // (p^a)*log(X)-log(A)=0 (mod P-1) を解く (Aを更新しながら順に解く)
        const i64 pa = powerInt(p, a), pb = powerInt(p, b);
        const i64 Q = (P - 1) / pb;
        mint X      = (Q == 1 ? mint{1} : A.pow(inverseMod(pa, Q)));
        if (a == b) {
            A = X;
            continue;
        }

        auto ordLog_p = [&](mint X) {  // order_p(log(X)) 但し log(X)=0 (mod Q)
            for (int i : per(b + 1)) {
                if (X == 1) { return i; }
                X = X.pow(p);
            }
            return 0;
        };
        auto trunc = [&](mint X, int ord) {  // log(X)が e*p^{b-1} になるまで、Xを左シフトした値
            assert(ord < b);
            LOOP ((b - 1) - ord) { X = X.pow(p); }
            return X;
        };
        mint Eraser = 1;  // log(Eraser)!=0 (mod p) かつ log(Eraser)=0 (mod Q)
        for (mint Z = 2;; Z += 1) {
            Eraser = Z.pow(Q);
            if (ordLog_p(Eraser) == 0) { break; }
        }
        Vec<mint> pErasers(b, Eraser);  // pEraser[i] = Eraser^(p^i)
        for (int i : rep(b - 1)) { pErasers[i + 1] = pErasers[i].pow(p); }
        assert(pErasers[b - 1].pow(p) == 1);
        const mint ipEraser = pErasers[b - 1].inv();

        // log_{Eraser^(p^(b-1))} (X) を求める離散対数問題パート(BabyStep-GiantStep)
        const i64 M = std::max(1_i64, (i64)intSqrt(p * (b - a) / 3)), W = ceilDiv((p - 1), M);
        Map<u64, i64> Memo;  // Eraser^((W*x)*p^{b-1}) -> W*x
        for (mint E = 1, ER = pErasers[b - 1].pow(W); i64 x : rep(M)) { Memo[E.val()] = W * x, E *= ER; }
        auto logErase = [&](mint X) {  // X=Erase^(k*p^{b-1}) となる k を返す
            for (i64 i : rep(W + 1)) {
                if (Memo.contains(X.val())) { return Memo[X.val()] + i; }
                X *= ipEraser;
            }
            return -1_i64;
        };

        mint Error = (X.pow(pa) / A);  // log(Error) (mod Q) を保ちつつ、 log(Error)=0 (mod p^b) にする
        while (true) {
            const int o = ordLog_p(Error);
            assert(o >= a);
            if (o == b) { break; }
            const i64 e = logErase(trunc(Error, o));
            assert(e != -1);
            X *= pErasers[o - a].pow(p - e), Error *= pErasers[o].pow(p - e);
        }
        A = X;
    }
    return A;
}
