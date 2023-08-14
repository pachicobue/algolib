#pragma once
#include "number_theoritic_transform.hpp"
#include "../number/garner.hpp"
#include "../utility/modint.hpp"
/**
 * @brief cs[i]=\sum_{i=j+k}as[j]*bs[k] を満たす数列cs (Mod)
 * @attention NTT-Friendlyじゃない場合は 長さ(1<<24) 未満にすること
 * 
 * @tparam mint modint
 * @param as 
 * @param bs 
 * @return Vec<mint> cs[i]=\sum_{i=j+k}as[j]*bs[k] を満たす数列cs
 */
template<typename mint> constexpr Vec<mint> convoluteMod(const Vec<mint>& as, const Vec<mint>& bs)
{
    const int LMAX = order2(mint::mod() - 1), NMAX = (1 << LMAX);
    const int AN = as.size(), BN = bs.size();
    if (AN == 0 or BN == 0) { return {}; }
    const int N = AN + BN - 1;
    if (std::min(AN, BN) <= 100) {  // AB<=(A+B)log(A+B) で計算量的に損するケースはこれで潰せる
        Vec<mint> ans(N, 0);
        for (int i : rep(AN)) {
            for (int j : rep(BN)) { ans[i + j] += as[i] * bs[j]; }
        }
        return ans;
    }
    if (N <= NMAX) {
        // mintはNTT Friendlyなのでそのまま畳み込み
        return NumberTheoriticTransform<mint>::convolute(as, bs);
    } else {
        assert(N <= (1 << 24));
        using submint1 = modint<469762049>;
        using submint2 = modint<167772161>;
        using submint3 = modint<754974721>;
        // mod 3つでGarner復元
        Vec<submint1> as1(AN), bs1(BN);
        Vec<submint2> as2(AN), bs2(BN);
        Vec<submint3> as3(AN), bs3(BN);
        for (int i : rep(AN)) { as1[i] = as[i].val(), as2[i] = as[i].val(), as3[i] = as[i].val(); }
        for (int i : rep(BN)) { bs1[i] = bs[i].val(), bs2[i] = bs[i].val(), bs3[i] = bs[i].val(); }
        const auto cs1 = NumberTheoriticTransform<submint1>::convolute(as1, bs1);
        const auto cs2 = NumberTheoriticTransform<submint2>::convolute(as2, bs2);
        const auto cs3 = NumberTheoriticTransform<submint3>::convolute(as3, bs3);
        Vec<mint> cs(N);
        for (int i : rep(N)) { cs[i] = Garner::restoreMod<mint>(cs1[i], cs2[i], cs3[i]); }
        return cs;
    }
}
/**
 * @brief cs[i]=\sum_{i=j+k}as[j]*bs[k] を満たす数列cs (符号付き整数)
 * @attention NTT-Friendlyじゃない場合は 長さ(1<<24) 未満にすること
 * @attention オーバーフローに注意
 * 
 * @param as 
 * @param bs 
 * @return Vec<i64> cs[i]=\sum_{i=j+k}as[j]*bs[k] を満たす数列cs
 */
constexpr Vec<i64> convoluteInt(const Vec<i64>& as, const Vec<i64>& bs)
{
    const int AN = as.size(), BN = bs.size();
    if (AN == 0 or BN == 0) { return {}; }
    const int N = AN + BN - 1;
    if (std::min(AN, BN) <= 100) {  // AB<=(A+B)log(A+B) で計算量的に損するケースはこれで潰せる
        Vec<i64> ans(N, 0);
        for (int i : rep(AN)) {
            for (int j : rep(BN)) { ans[i + j] += as[i] * bs[j]; }
        }
        return ans;
    }
    assert(N <= (1 << 24));
    if (AN * 4 - 1 <= BN / AN) {
        Vec<i64> cs(N, 0);
        for (int sj : irange(0, BN, AN)) {
            const int tj   = std::min(BN, sj + AN);
            const auto bbs = Vec<i64>(std::begin(bs) + sj, std::begin(bs) + tj);
            const auto bcs = convoluteInt(as, bbs);
            for (int dj : rep(bcs.size())) { cs[sj + dj] += bcs[dj]; }
        }
        return cs;
    }
    using submint1 = modint<469762049>;
    using submint2 = modint<167772161>;
    using submint3 = modint<754974721>;
    // mod 3つでGarner復元
    Vec<submint1> as1(AN), bs1(BN);
    Vec<submint2> as2(AN), bs2(BN);
    Vec<submint3> as3(AN), bs3(BN);
    for (int i : rep(AN)) { as1[i] = as[i], as2[i] = as[i], as3[i] = as[i]; }
    for (int i : rep(BN)) { bs1[i] = bs[i], bs2[i] = bs[i], bs3[i] = bs[i]; }
    const auto cs1 = NumberTheoriticTransform<submint1>::convolute(as1, bs1);
    const auto cs2 = NumberTheoriticTransform<submint2>::convolute(as2, bs2);
    const auto cs3 = NumberTheoriticTransform<submint3>::convolute(as3, bs3);
    Vec<i64> cs(N);
    for (int i : rep(N)) { cs[i] = Garner::restoreInt(cs1[i], cs2[i], cs3[i]); }
    return cs;
}
/**
 * @brief cs[i]=\sum_{i+j=k}as[j]*bs[k] を満たす数列cs (mod)
 * 
 * @tparam mint modint
 * @param as 
 * @param bs 
 * @return Vec<mint> cs[i]=\sum_{i+j=k}as[j]*bs[k] を満たす数列cs
 */
template<typename mint> constexpr Vec<mint> convoluteModReverse(Vec<mint> as, const Vec<mint>& bs)
{
    const int N = (int)as.size(), M = (int)bs.size();
    reverseAll(as);
    const auto cs = convoluteMod(as, bs);
    Vec<mint> ans(M);
    for (int i : rep(M)) { ans[i] = cs[i + N - 1]; }
    return ans;
}
/**
 * @brief cs[i]=\sum_{i+j=k}as[j]*bs[k] を満たす数列cs (int)
 * 
 * @param as 
 * @param bs 
 * @return Vec<i64> cs[i]=\sum_{i+j=k}as[j]*bs[k] を満たす数列cs
 */
constexpr Vec<i64> convoluteIntReverse(Vec<i64> as, const Vec<i64>& bs)
{
    const int N = (int)as.size(), M = (int)bs.size();
    reverseAll(as);
    const auto cs = convoluteInt(as, bs);
    Vec<i64> ans(M);
    for (int i : rep(M)) { ans[i] = cs[i + N - 1]; }
    return ans;
}
