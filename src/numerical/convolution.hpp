#pragma once
#include "number_theoritic_transform.hpp"
#include "../number/garner.hpp"
#include "../utility/modint.hpp"
/**
 * @brief H[i]=\sum_{i=j+k}F[j]*G[k] を満たす数列H (Mod)
 * @attention NTT-Friendlyじゃない場合は 長さ(1<<24) 未満にすること
 * 
 * @tparam mint modint
 * @param F 
 * @param G 
 * @return Vec<mint> H[i]=\sum_{i=j+k}F[j]*G[k] を満たす数列H
 */
template<typename mint> Vec<mint> convoluteMod(const Vec<mint>& F, const Vec<mint>& G)
{
    const int LMAX = order2(mint::mod() - 1), NMAX = (1 << LMAX);
    const int A = F.size(), B = G.size();
    if (A == 0 or B == 0) { return {}; }
    const int N = A + B - 1;
    if (std::min(A, B) <= 100) {  // AB<=(A+B)log(A+B) で計算量的に損するケースはこれで潰せる
        Vec<mint> ans(N, 0);
        for (int i : rep(A)) {
            for (int j : rep(B)) { ans[i + j] += F[i] * G[j]; }
        }
        return ans;
    }
    if (N <= NMAX) {
        // mintはNTT Friendlyなのでそのまま畳み込み
        return NumberTheoriticTransform<mint>::convolute(F, G);
    } else {
        assert(N <= (1 << 24));
        using submint1 = modint<469762049>;
        using submint2 = modint<167772161>;
        using submint3 = modint<754974721>;
        // mod 3つでGarner復元
        Vec<submint1> as1(A), bs1(B);
        Vec<submint2> as2(A), bs2(B);
        Vec<submint3> as3(A), bs3(B);
        for (int i : rep(A)) { as1[i] = F[i].val(), as2[i] = F[i].val(), as3[i] = F[i].val(); }
        for (int i : rep(B)) { bs1[i] = G[i].val(), bs2[i] = G[i].val(), bs3[i] = G[i].val(); }
        const auto cs1 = NumberTheoriticTransform<submint1>::convolute(as1, bs1);
        const auto cs2 = NumberTheoriticTransform<submint2>::convolute(as2, bs2);
        const auto cs3 = NumberTheoriticTransform<submint3>::convolute(as3, bs3);
        Vec<mint> cs(N);
        for (int i : rep(N)) { cs[i] = Garner::restoreMod<mint>(cs1[i], cs2[i], cs3[i]); }
        return cs;
    }
}
/**
 * @brief H[i]=\sum_{i=j+k}F[j]*G[k] を満たす数列H (符号付き整数)
 * @attention 長さ(1<<24) 未満にすること
 * @attention オーバーフローに注意
 * 
 * @param F 
 * @param G 
 * @return Vec<i64> H[i]=\sum_{i=j+k}F[j]*G[k] を満たす数列H
 */
inline Vec<i64> convoluteInt(const Vec<i64>& F, const Vec<i64>& G)
{
    const int A = F.size(), B = G.size();
    if (A == 0 or B == 0) { return {}; }
    const int N = A + B - 1;
    if (std::min(A, B) <= 100) {  // AB<=(A+B)log(A+B) で計算量的に損するケースはこれで潰せる
        Vec<i64> ans(N, 0);
        for (int i : rep(A)) {
            for (int j : rep(B)) { ans[i + j] += F[i] * G[j]; }
        }
        return ans;
    }
    assert(N <= (1 << 24));
    using submint1 = modint<469762049>;
    using submint2 = modint<167772161>;
    using submint3 = modint<754974721>;
    // mod 3つでGarner復元
    Vec<submint1> as1(A), bs1(B);
    Vec<submint2> as2(A), bs2(B);
    Vec<submint3> as3(A), bs3(B);
    for (int i : rep(A)) { as1[i] = F[i], as2[i] = F[i], as3[i] = F[i]; }
    for (int i : rep(B)) { bs1[i] = G[i], bs2[i] = G[i], bs3[i] = G[i]; }
    const auto cs1 = NumberTheoriticTransform<submint1>::convolute(as1, bs1);
    const auto cs2 = NumberTheoriticTransform<submint2>::convolute(as2, bs2);
    const auto cs3 = NumberTheoriticTransform<submint3>::convolute(as3, bs3);
    Vec<i64> cs(N);
    for (int i : rep(N)) { cs[i] = Garner::restoreInt(cs1[i], cs2[i], cs3[i]); }
    return cs;
}
/**
 * @brief H[i]=\sum_{i+j=k}F[j]*G[k] を満たす数列H (mod)
 * @attention NTT-Friendlyじゃない場合は 長さ(1<<24) 未満にすること
 * 
 * @tparam mint modint
 * @param F 
 * @param G 
 * @return Vec<mint> H[i]=\sum_{i+j=k}F[j]*G[k] を満たす数列H
 */
template<typename mint> Vec<mint> convoluteModReverse(Vec<mint> F, const Vec<mint>& G)
{
    const int A = (int)F.size(), B = (int)G.size();
    seqReverse(F);
    const auto cs = convoluteMod(F, G);
    Vec<mint> ans(B);
    for (int i : rep(B)) { ans[i] = cs[i + A - 1]; }
    return ans;
}
/**
 * @brief H[i]=\sum_{i+j=k}F[j]*G[k] を満たす数列H (int)
 * @attention 長さ(1<<24) 未満にすること
 * 
 * @param F 
 * @param G 
 * @return Vec<i64> H[i]=\sum_{i+j=k}F[j]*G[k] を満たす数列H
 */
inline Vec<i64> convoluteIntReverse(Vec<i64> F, const Vec<i64>& G)
{
    const int A = (int)F.size(), B = (int)G.size();
    seqReverse(F);
    const auto cs = convoluteInt(F, G);
    Vec<i64> ans(B);
    for (int i : rep(B)) { ans[i] = cs[i + A - 1]; }
    return ans;
}
