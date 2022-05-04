#pragma once
#include "../misc/common.hpp"

template<typename mint>
class NTT
{
    // DynamicModint 非対応
    static_assert(not mint::isDynamic(),
                  "class NTT: Not support dynamic modint.");

private:
    static constexpr u32 MOD = mint::mod();
    static constexpr u32 ROOT = mint::root();
    static constexpr u32 L_MAX = mint::max2p();
    static constexpr u32 N_MAX = (1 << L_MAX);

public:
    static Vec<mint> convolute(Vec<mint> as, Vec<mint> bs)
    {
        const int AN = as.size();
        const int BN = bs.size();
        const int CN = AN + BN - 1;
        const int L = clog(CN);
        const int N = (1 << L);
        as.resize(N, 0), bs.resize(N, 0);
        transform(as, L, false), transform(bs, L, false);
        for (int i : rep(N)) {
            as[i] *= bs[i];
        }
        transform(as, L, true);
        as.resize(CN);
        return as;
    }
    static void transform(Vec<mint>& as, int L, bool rev)
    {
        const int N = as.size();
        assert(N <= N_MAX);
        assert((1 << L) == N);
        if (N == 1) { return; }

        const auto l_range = (rev ? irange(1, L + 1, 1) : irange(L, 0, -1));
        for (int l : l_range) {
            const int H = 1 << l;
            const int B = N / H;
            for (int b : rep(B)) {
                const mint W = zeta(l, rev);
                mint W_h = 1;
                for (int h : rep(H / 2)) {
                    const int y1 = H * b + h;
                    const int y2 = y1 + H / 2;
                    const mint a1 = as[y1];
                    const mint a2 = as[y2];
                    const mint na1 = (rev ? a1 + a2 * W_h : a1 + a2);
                    const mint na2 = (rev ? a1 - a2 * W_h : (a1 - a2) * W_h);
                    as[y1] = na1;
                    as[y2] = na2;
                    W_h *= W;
                }
            }
        }
        if (rev) {
            const mint iN = mint::sinv(N);
            for (auto& a : as) {
                a *= iN;
            }
        }
    }

private:
    static mint zeta(int i, bool rev)
    {
        static Vec<mint> zs;   // zs[i] = 1の2^i乗根
        static Vec<mint> izs;  // izs[i] = zs[i]の逆元
        if (zs.empty()) {
            zs.resize(L_MAX + 1, 1);
            izs.resize(L_MAX + 1, 1);
            zs[L_MAX] = mint(ROOT).pow((MOD - 1) / (1 << L_MAX));
            izs[L_MAX] = zs[L_MAX].inv();
            for (int l : per(L_MAX)) {
                zs[l] = zs[l + 1] * zs[l + 1];
                izs[l] = izs[l + 1] * izs[l + 1];
            }
        }
        return (rev ? izs[i] : zs[i]);
    }
};
