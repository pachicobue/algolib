#pragma once
#include "../misc/common.hpp"
template<int lg>
class Wavelet
{
public:
    Wavelet(Vec<u64> vs) : m_size{(int)vs.size()}
    {
        for (int i : rep(lg)) {
            m_zns[i] = 0;
            m_tables[i] = FID(m_size);
        }
        Vec<u64> z(m_size), o(m_size);
        int zn = 0, on = 0;
        for (int d : rep(lg)) {
            zn = 0, on = 0;
            for (int i : rep(m_size)) {
                const bool b = btest(vs[i], lg - d - 1);
                m_tables[d].set(i, b);
                (b ? o[on++] : z[zn++]) = vs[i];
            }
            m_tables[d].build();
            m_zns[d] = zn;
            std::swap(vs, z);
            for (int i : rep(on)) {
                vs[zn + i] = o[i];
            }
        }
    }
    int lessThan(int l, int r, u64 v) const
    {
        assert(l <= r);
        int ans = 0;
        for (int i : rep(lg)) {
            const int zl = m_tables[i].zero(l), zr = m_tables[i].zero(r);
            const int z = m_zns[i];
            if (btest(v, lg - i - 1)) {
                ans += zr - zl;
                l += z - zl, r += z - zr;
            } else {
                l = zl, r = zr;
            }
        }
        return ans;
    }
    int rangeFreq(int l, int r, u64 vmin, u64 vsup) const
    {
        return lessThan(l, r, vsup) - lessThan(l, r, vmin);
    }
    u64 quantile(int l, int r, int n) const
    {
        assert(l <= r), assert(r - l > n);
        u64 ans = 0;
        for (int i : rep(lg)) {
            const int zl = m_tables[i].zero(l), zr = m_tables[i].zero(r);
            const int z = m_zns[i];
            if (n >= zr - zl) {
                ans += u64(1) << (lg - i - 1);
                l += z - zl, r += z - zr, n -= (zr - zl);
            } else {
                l = zl, r = zr;
            }
        }
        return ans;
    }
private:
    static constexpr int bucket_size = sizeof(u64) * 8;
    static constexpr int bslog = log2p1(bucket_size) - 1;
    static constexpr u64 bcut(const u64 n, const int l)
    {
        return (l == 0 ? 0ULL : (n << (64 - l) >> (64 - l)));
    }
    static constexpr int wind(const int n)
    {
        return n >> (bslog);
    }
    static constexpr int bind(const int n)
    {
        return bcut(n, bslog);
    }
    class FID
    {
    private:
        int m_size, m_bn;
        Vec<u64> m_datas;
        Vec<int> m_larges;
    public:
        FID() : m_size{0} {}
        FID(const int b)
            : m_size{b},
              m_bn{wind(m_size) + 2},
              m_datas(m_bn, 0),
              m_larges(m_bn, 0)
        {}
        void build()
        {
            for (int i : range(1, m_larges.size())) {
                m_larges[i] = m_larges[i - 1] + popcount(m_datas[i - 1]);
            }
        }
        bool operator[](const int n) const
        {
            return btest(m_datas[wind(n)], bind(n));
        }
        void set(const int n, const bool b)
        {
            m_datas[wind(n)] |= u64{b} << bind(n);
        }
        int one(const int n) const
        {
            return m_larges[wind(n)]
                   + popcount(bcut(m_datas[wind(n)], bind(n)));
        }
        int zero(const int n) const
        {
            return n - one(n);
        }
    };
    int m_size;
    Arr<int, lg> m_zns;
    Arr<FID, lg> m_tables;
};
