#pragma once
#include "ntt.hpp"
#include "garner.hpp"
#include "modint.hpp"

template<typename mint>
Vec<mint> convolute_mod(const Vec<mint>& as, const Vec<mint>& bs)
{
    constexpr u32 L_MAX = mint::max2p();
    constexpr u32 N_MAX = (1 << L_MAX);
    const int AN = as.size();
    const int BN = bs.size();
    const int N = AN + BN - 1;
    if (N <= 10) {
        Vec<mint> cs(N, 0);
        for (int i : rep(AN)) {
            for (int j : rep(BN)) {
                cs[i + j] += as[i] * bs[j];
            }
        }
        return cs;
    }
    if (N <= N_MAX) {
        // mintはNTT Friendlyなのでそのまま畳み込み
        return NTT<mint>::convolute(as, bs);
    } else {
        assert(N <= (1 << 24));
        using submint1 = modint<469762049, 3, 26>;
        using submint2 = modint<167772161, 3, 25>;
        using submint3 = modint<754974721, 11, 24>;
        // mod 3つでGarner復元
        Vec<submint1> as1(AN), bs1(BN);
        Vec<submint2> as2(AN), bs2(BN);
        Vec<submint3> as3(AN), bs3(BN);
        for (int i : rep(AN)) {
            as1[i] = as[i].val(), as2[i] = as[i].val(), as3[i] = as[i].val();
        }
        for (int i : rep(BN)) {
            bs1[i] = bs[i].val(), bs2[i] = bs[i].val(), bs3[i] = bs[i].val();
        }
        const auto cs1 = NTT<submint1>::convolute(as1, bs1);
        const auto cs2 = NTT<submint2>::convolute(as2, bs2);
        const auto cs3 = NTT<submint3>::convolute(as3, bs3);
        Vec<mint> cs(N);
        for (int i : rep(N)) {
            cs[i] = restore_mod<mint>(cs1[i], cs2[i], cs3[i]);
        }
        return cs;
    }
}

Vec<i64> convolute_i64(const Vec<i64>& as, const Vec<i64>& bs)
{
    const int AN = as.size();
    const int BN = bs.size();
    const int N = AN + BN - 1;
    assert(N <= (1 << 24));
    if (N <= 10) {
        Vec<i64> cs(N, 0);
        for (int i : rep(AN)) {
            for (int j : rep(BN)) {
                cs[i + j] += as[i] * bs[j];
            }
        }
        return cs;
    }
    using submint1 = modint<469762049, 3, 26>;
    using submint2 = modint<167772161, 3, 25>;
    using submint3 = modint<754974721, 11, 24>;
    // mod 3つでGarner復元
    Vec<submint1> as1(N), bs1(N);
    Vec<submint2> as2(N), bs2(N);
    Vec<submint3> as3(N), bs3(N);
    for (int i : rep(N)) {
        as1[i] = as[i], bs1[i] = bs[i];
        as2[i] = as[i], bs2[i] = bs[i];
        as3[i] = as[i], bs3[i] = bs[i];
    }
    const auto cs1 = NTT<submint1>::convolute(as1, bs1);
    const auto cs2 = NTT<submint2>::convolute(as2, bs2);
    const auto cs3 = NTT<submint3>::convolute(as3, bs3);
    Vec<i64> cs(N);
    for (int i : rep(N)) {
        cs[i] = restore_i64(cs1[i], cs2[i], cs3[i]);
    }
    return cs;
}
