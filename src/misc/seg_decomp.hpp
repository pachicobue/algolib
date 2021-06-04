#pragma once
#include "common.hpp"
class SegDecomp
{
    using P = Pair<int, int>;

public:
    SegDecomp(int size) : m_half(ceil2(size)), m_segs(m_half << 1, P{0, 0})
    {
        for (int i = 1; i <= m_half; i <<= 1) {
            const int l = m_half / i;
            for (int j : rep(i)) {
                m_segs[i + j] = {l * j, l * (j + 1)};
            }
        }
    }
    Vec<int> under(int l, int r) const
    {
        if (l >= r or r > m_half) { return Vec<int>{}; }
        Vec<int> lis, ris;
        int li = l + m_half, ri = r + m_half;
        for (; li < ri; li >>= 1, ri >>= 1) {
            if (li & 1) { lis.push_back(li++); }
            if (ri & 1) { ris.push_back(--ri); }
        }
        reverseAll(ris);
        return lis + ris;
    }
    Vec<int> over(int i) const
    {
        if (i >= m_half) { return Vec<int>{}; }
        Vec<int> aboves;
        i += m_half;
        for (; i >= 1; i >>= 1) {
            aboves.push_back(i);
        }
        reverseAll(aboves);
        return aboves;
    }
    const P& operator[](int i) const
    {
        assert(1 <= i and i < (m_half << 1));
        return m_segs[i];
    }
    int size() const
    {
        return (m_half << 1);
    }

private:
    int m_half;
    Vec<P> m_segs;
};
