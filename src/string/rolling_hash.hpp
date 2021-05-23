#pragma once
#include "../misc/common.hpp"
class RollingHash
{
public:
    template<typename It>
    RollingHash(It first, It last, u64 base_ = rng64.val<u64>(2, mask61 - 1))
        : m_size(std::distance(first, last)),
          m_ps(m_size + 1, 1),
          m_hs(m_size + 1, 0),
          m_base{base_}
    {
        for (int i : range(1, m_size + 1)) {
            m_ps[i] = mod(mul(m_ps[i - 1], m_base)),
            m_hs[i] = mod(mul(m_hs[i - 1], m_base) + *std::next(first, i - 1));
        }
    }
    u64 operator()(int l, int r) const
    {
        return mod(m_hs[r] + offset - mul(m_hs[l], m_ps[r - l]));
    }
    template<typename C>
    void push_back(C c)
    {
        m_size++;
        m_ps.push_back(mod(mul(m_ps.back(), m_base)));
        m_hs.push_back(mod(mul(m_hs.back(), m_base) + c));
    }

private:
    static constexpr u64 mask30 = (1_u64 << 30) - 1;
    static constexpr u64 mask31 = (1_u64 << 31) - 1;
    static constexpr u64 mask61 = (1_u64 << 61) - 1;
    static constexpr u64 offset = mask61 * 7_u64;
    static constexpr u64 mod(u64 x)
    {
        const u64 y = (x >> 61) + (x & mask61);
        return y >= mask61 ? y - mask61 : y;
    }
    static constexpr u64 mul(u64 x, u64 y)
    {
        const u64 xh = x >> 31, xl = x & mask31;
        const u64 yh = y >> 31, yl = y & mask31;
        const u64 z = xl * yh + xh * yl;
        const u64 zh = z >> 30, zl = z & mask30;
        return xh * yh * 2 + zh + (zl << 31) + xl * yl;
    }
    int m_size;
    Vec<u64> m_ps, m_hs;
    u64 m_base;
};
