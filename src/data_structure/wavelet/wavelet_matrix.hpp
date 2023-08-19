#pragma once
#include "../../common.hpp"
#include "bit_vector.hpp"
/**
 * @brief Wavelet 行列
 */
class WaveletMatrix
{
public:
    /**
     * @brief コンストラクタ
     * 
     * @param xs 数列(全て非負)
     */
    WaveletMatrix(Vec<i64> xs)
        : m_n(xs.size()),
          m_min{(i64)mdSeqMin(xs)},
          m_max{(i64)mdSeqMax(xs)},
          m_lg{(int)std::bit_width((u64)m_max + 1)},
          m_bvs(m_lg, BitVector(m_n))
    {
        assert(0 <= m_min);
        Vec<i64> nvs(m_n);
        for (int bi : per(m_lg)) {
            for (int i : rep(m_n)) {
                if (isBitOn(xs[i], bi)) { m_bvs[bi].set(i); }
            }
            int is[2] = {0, m_bvs[bi].zero()};
            for (int i : rep(m_n)) { nvs[is[isBitOn(xs[i], bi)]++] = xs[i]; }
            std::swap(xs, nvs);
        }
    }
    /**
     * @brief 矩形カウント #{i | l<=i<r && vmin<=X[i]<vsup}
     * 
     * @param l 
     * @param r 
     * @param vmin 
     * @param vsup 
     * @return int 矩形カウント
     */
    int rangeFreq(int l, int r, i64 vmin, i64 vsup)
    {
        assert(0 <= l and l <= r and r <= m_n);
        assert(vmin <= vsup);
        return lessFreq(l, r, vsup) - lessFreq(l, r, vmin);
    }
    /**
     * @brief X[l],...,X[r-1] で K番目に小さな値(0-indexed)
     * 
     * @param l 
     * @param r 
     * @param K 
     * @return i64 K番目に小さな値(0-indexed)
     */
    i64 quantile(int l, int r, int K)
    {
        assert(0 <= l and l <= r and r <= m_n);
        assert(0 <= K and K < r - l);
        i64 ans = 0;
        for (int bi : per(m_lg)) {
            const int lz = m_bvs[bi].rank0(l), rz = m_bvs[bi].rank0(r);
            if (rz - lz <= K) {
                const int z = m_bvs[bi].zero();
                ans |= (1_i64 << bi);
                K -= (rz - lz);
                l += z - lz, r += z - rz;
            } else {
                l = lz, r = rz;
            }
        }
        return ans;
    }
private:
    int lessFreq(int l, int r, i64 v)
    {
        assert(0 <= l and l <= r and r <= m_n);
        if (v <= m_min) { return 0; }
        if (v - 1 >= m_max) { return r - l; }
        int ans = 0;
        for (int bi : per(m_lg)) {
            const int lz = m_bvs[bi].rank0(l), rz = m_bvs[bi].rank0(r);
            if (isBitOn(v, bi)) {
                const int z = m_bvs[bi].zero();
                ans += rz - lz;
                l += z - lz, r += z - rz;
            } else {
                l = lz, r = rz;
            }
        }
        return ans;
    }
    int m_n;
    i64 m_min, m_max;
    int m_lg;
    Vec<BitVector> m_bvs;
};
