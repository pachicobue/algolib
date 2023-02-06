#pragma once
#include "../../common.hpp"
class SegSkeleton
{
public:
    SegSkeleton(int size) : m_size(size), m_half(ceil2(m_size)), m_segs(m_half * 2, {0, 0})
    {
        for (int i = 1; i <= m_half; i <<= 1) {
            const int l = m_half / i;
            for (int j : rep(i)) { m_segs[i + j] = {l * j, l * (j + 1)}; }
        }
    }
    template<typename F>
    void act(int l, int r, F f) const
    {
        assert(0 <= l and l <= r and r <= m_size);
        int li = l + m_half, ri = r + m_half;
        for (; li < ri; li >>= 1, ri >>= 1) {
            if (li & 1) {
                const auto& [xl, xr] = m_segs[li];
                f(li++, xl, xr);
            }
            if (ri & 1) {
                const auto& [xl, xr] = m_segs[--ri];
                f(ri, xl, xr);
            }
        }
    }

private:
    int m_size, m_half;
    Vec<Pair<int, int>> m_segs;
};
