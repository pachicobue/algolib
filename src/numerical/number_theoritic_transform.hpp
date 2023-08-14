#pragma once
#include "../common.hpp"
#include "../number/primitive_root.hpp"
template<typename mint> class NumberTheoriticTransform
{
private:
    static constexpr u64 mod() { return mint::mod(); }
    static constexpr u64 root() { return primitiveRoot(mint::mod()); }
    static constexpr int order() { return order2(mint::mod() - 1); }
public:
    static constexpr Vec<mint> convolute(Vec<mint> as, Vec<mint> bs)
    {
        const int AN = as.size(), BN = bs.size();
        const int CN = AN + BN - 1;
        const int N  = (int)std::bit_ceil((u64)CN);
        as.resize(N, 0), bs.resize(N, 0);
        transform(as, false), transform(bs, false);
        for (int i : rep(N)) { as[i] *= bs[i]; }
        transform(as, true), as.resize(CN);
        return as;
    }
    static constexpr void transform(Vec<mint>& as, bool rev)
    {
        const int N = as.size();
        assert((N & (N - 1)) == 0);
        assert(N <= (1 << order()));
        if (N == 1) { return; }
        const int L        = floorLog2(N);
        const auto l_range = (rev ? irange(1, L + 1, 1) : irange(L, 0, -1));
        for (int l : l_range) {
            const int H = (1 << l), B = N / H;
            for (int b : rep(B)) {
                const mint W = zeta(l, rev);
                for (mint W_h = 1; int h : rep(H / 2)) {
                    const int y1 = H * b + h, y2 = y1 + H / 2;
                    const mint a1 = as[y1], a2 = as[y2];
                    const mint na1 = (rev ? a1 + a2 * W_h : a1 + a2), na2 = (rev ? a1 - a2 * W_h : (a1 - a2) * W_h);
                    as[y1] = na1, as[y2] = na2;
                    W_h *= W;
                }
            }
        }
        if (rev) {
            const mint iN = mint::sinv(N);
            for (auto& a : as) { a *= iN; }
        }
    }
private:
    static mint zeta(int i, bool rev)
    {
        static Vec<mint> zs, izs;  // zs[i] = 1の2^i乗根, izs[i] = zs[i]の逆元
        if (zs.empty()) {
            const auto MOD = mod(), ROOT = root();
            const auto LMAX = order();
            zs.resize(LMAX + 1, 1), izs.resize(LMAX + 1, 1);
            zs[LMAX] = mint(ROOT).pow((MOD - 1) / (1 << LMAX)), izs[LMAX] = zs[LMAX].inv();
            for (int l : per(LMAX)) { zs[l] = zs[l + 1] * zs[l + 1], izs[l] = izs[l + 1] * izs[l + 1]; }
        }
        return (rev ? izs[i] : zs[i]);
    }
};
