#pragma once
#include "../../common.hpp"
#include "bit_vector.hpp"
template<typename T>
class WaveletMatrix
{
public:
    WaveletMatrix(Vec<T> vs)
        : m_n(vs.size()),
          m_min{vs[minInd(vs)]},
          m_max{vs[maxInd(vs)]},
          m_lg{bitWidth(m_max + 1)},
          m_bvs(m_lg, BitVector(m_n))
    {
        assert(m_min >= 0);
        Vec<T> nvs(m_n);
        for (int bi : per(m_lg)) {
            for (int i : rep(m_n)) {
                if (isBitOn(vs[i], bi)) { m_bvs[bi].set(i); }
            }
            int is[2] = {0, m_bvs[bi].zero()};
            for (int i : rep(m_n)) { nvs[is[isBitOn(vs[i], bi)]++] = vs[i]; }
            std::swap(vs, nvs);
        }
    }
    int rangeFreq(int l, int r, T vmin, T vsup)
    {
        assert(0 <= l and l <= r and r <= m_n);
        assert(vmin <= vsup);
        return lessFreq(l, r, vsup) - lessFreq(l, r, vmin);
    }
    T quantile(int l, int r, int k)
    {
        assert(0 <= l and l <= r and r <= m_n);
        assert(0 <= k and k < r - l);
        T ans = 0;
        for (int bi : per(m_lg)) {
            const int lz = m_bvs[bi].rank0(l), rz = m_bvs[bi].rank0(r);
            if (rz - lz <= k) {
                const int z = m_bvs[bi].zero();
                ans |= (T{1} << bi);
                k -= (rz - lz);
                l += z - lz, r += z - rz;
            } else {
                l = lz, r = rz;
            }
        }
        return ans;
    }

private:
    int lessFreq(int l, int r, T v)
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
    T m_min, m_max;
    int m_lg;
    Vec<BitVector> m_bvs;
};
