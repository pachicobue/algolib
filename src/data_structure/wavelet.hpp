#pragma once
#include "../misc/common.hpp"
#include "bit_vector.hpp"

template<typename T>
class WaveletMatrix
{
public:
    WaveletMatrix(Vec<T> vs, int lg = sizeof(T) * 8)
        : m_n(vs.size()), m_lg{lg}, m_bvs(lg, BitVector(m_n))
    {
        Vec<T> nvs(m_n);
        for (int bi : per(lg)) {
            for (int i : rep(m_n)) {
                if (btest(vs[i], bi)) { m_bvs[bi].set(i); }
            }
            int is[2] = {0, m_bvs[bi].zero()};
            for (int i : rep(m_n)) {
                nvs[is[btest(vs[i], bi)]++] = vs[i];
            }
            std::swap(vs, nvs);
        }
    }
    int rangeFreq(int l, int r, T vmin, T vsup)
    {
        assert(0 <= l and l <= r and r <= m_n);
        return less(r, vsup) - less(r, vmin) - less(l, vsup) + less(l, vmin);
    }
    T quantile(int l, int r, int k)
    {
        assert(0 <= l and l <= r and r <= m_n);
        assert(0 <= k and k < r - l);
        T ans = 0;
        for (int bi : per(m_lg)) {
            const int z = m_bvs[bi].zero();
            const int zl = m_bvs[bi].rank0(l);
            const int zr = m_bvs[bi].rank0(r);
            if (zr - zl <= k) {
                ans |= (T{1} << bi);
                k -= (zr - zl);
                l = z + m_bvs[bi].rank1(l), r = z + m_bvs[bi].rank1(r);
            } else {
                l = zl, r = zr;
            }
        }
        return ans;
    }

private:
    int less(int i, T v)
    {
        assert(0 <= i and i <= m_n);
        int ans = 0;
        for (int bi : per(m_lg)) {
            if (btest(v, bi)) {
                const int z = m_bvs[bi].zero();
                ans += z;
                i = z + m_bvs[bi].rank1(i);
            } else {
                i = m_bvs[bi].rank1(0);
            }
        }
        return ans;
    }

    int m_n;
    int m_lg;
    Vec<BitVector> m_bvs;
};
