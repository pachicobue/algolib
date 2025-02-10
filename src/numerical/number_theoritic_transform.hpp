#pragma once
#include <bit>
#include <cassert>
#include "../internal.hpp"
#include "../number/primitive_root.hpp"
/**
 * @brief Number Theoretic Transform
 *
 * @tparam mint modint (NTT friendlyな素数)
 */
template <typename mint> class NumberTheoriticTransform {
private:
    static constexpr auto mod() -> u64 {
        return mint::mod();
    }
    static constexpr auto root() -> u64 {
        return primitiveRootFast(mint::mod());
    }
    static constexpr auto order() -> int {
        return order2(mint::mod() - 1);
    }
public:
    /**
     * @brief 畳み込み
     *
     * @param F
     * @param G
     * @return Vec<mint> 畳み込み結果
     */
    static auto convolute(Vec<mint> F, Vec<mint> G) -> Vec<mint> {
        const int A = F.size(), B = G.size();
        const int C = A + B - 1;
        const int N = (int)std::bit_ceil((u64)C);
        F.resize(N, 0), G.resize(N, 0);
        transform(F, false), transform(G, false);
        for (int i : rep(N)) {
            F[i] *= G[i];
        }
        transform(F, true), F.resize(C);
        return F;
    }
    /**
     * @brief NTTを行う
     *
     * @param [in,out] F 変換する数列 (変換結果もここに入る)
     * @param rev 逆変換か
     */
    static auto transform(Vec<mint>& F, bool rev) -> void {
        const int N = F.size();
        assert((N & (N - 1)) == 0);
        assert(N <= (1 << order()));
        if (N == 1) {
            return;
        }
        const int L = floorLog2(N);
        const auto l_range = (rev ? irange(1, L + 1, 1) : irange(L, 0, -1));
        for (int l : l_range) {
            const int H = (1 << l), B = N / H;
            for (int b : rep(B)) {
                const mint W = zeta(l, rev);
                for (mint W_h = 1; int h : rep(H / 2)) {
                    const int y1 = H * b + h, y2 = y1 + H / 2;
                    const mint f1 = F[y1], f2 = F[y2];
                    const mint nf1 = (rev ? f1 + f2 * W_h : f1 + f2), nf2 = (rev ? f1 - f2 * W_h : (f1 - f2) * W_h);
                    F[y1] = nf1, F[y2] = nf2;
                    W_h *= W;
                }
            }
        }
        if (rev) {
            const mint iN = mint{1} / N;
            for (auto& a : F) {
                a *= iN;
            }
        }
    }
private:
    static auto zeta(int i, bool rev) -> mint {
        static Vec<mint> zs, izs; // zs[i] = 1の2^i乗根, izs[i] = zs[i]の逆元
        if (zs.empty()) {
            const auto MOD = mod(), ROOT = root();
            const auto LMAX = order();
            zs.resize(LMAX + 1, 1), izs.resize(LMAX + 1, 1);
            zs[LMAX] = mint(ROOT).pow((MOD - 1) / (1 << LMAX)), izs[LMAX] = zs[LMAX].inv();
            for (int l : per(LMAX)) {
                zs[l] = zs[l + 1] * zs[l + 1], izs[l] = izs[l + 1] * izs[l + 1];
            }
        }
        return (rev ? izs[i] : zs[i]);
    }
};
