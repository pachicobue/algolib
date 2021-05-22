#pragma once
#include "../misc/common.hpp"
class segments
{
    using P = Pair<int, int>;
public:
    segments(int size)
        : m_ceil(ceil2(size)), m_segs(m_ceil << 1, P{0, 0}), m_num{m_ceil << 1}
    {
        for (int sz = 1; sz <= m_ceil; sz <<= 1) {
            const int len = m_ceil / sz;
            for (int j : range(sz, sz * 2)) {
                m_segs[j] = {len * (j - sz), len * (j - sz + 1)};
            }
        }
    }
    Vec<int> under(int l, int r) const
    {
        if (l >= r or r > m_ceil) { return Vec<int>{}; }
        Vec<int> lis, ris;
        int li = l + m_ceil, ri = r + m_ceil;
        for (; li < ri; li >>= 1, ri >>= 1) {
            if (li & 1) { lis.push_back(li++); }
            if (ri & 1) { ris.push_back(--ri); }
        }
        reverseAll(ris);
        return lis + ris;
    }
    Vec<int> over(int i) const
    {
        if (i >= m_ceil) { return Vec<int>{}; }
        Vec<int> aboves;
        i += m_ceil;
        for (; i >= 1; i >>= 1) {
            aboves.push_back(i);
        }
        reverseAll(aboves);
        return aboves;
    }
    const P& operator[](int i) const
    {
        return m_segs[i];
    }
    int size() const
    {
        return m_num;
    }
private:
    int m_ceil;
    Vec<P> m_segs;
    int m_num;
};
