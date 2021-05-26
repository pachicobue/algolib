#pragma once
#include "../misc/common.hpp"
template<typename SemiGroup>
class DSTable
{
    using T = typename SemiGroup::T;

public:
    DSTable(const Vec<T>& vs)
        : m_size(vs.size()), m_depth(log2p1(m_size)), m_vss(m_depth, vs)
    {
        for (int d : rep(m_depth)) {
            const int w = 1 << (m_depth - d - 1);
            for (int i = 1; i * w < m_size; i += 2) {
                int l = i * w - 1, r = i * w;
                for (int j : irange(1, w)) {
                    m_vss[d][l - j] = merge(vs[l - j], m_vss[d][l - j + 1]);
                    if (r + j < m_size) {
                        m_vss[d][r + j] = merge(vs[r + j], m_vss[d][r + j - 1]);
                    }
                }
            }
        }
    }
    T fold(int l, int r) const
    {
        assert(0 <= l and l < r and r <= m_size);
        if (r - l == 1) { return m_vss.back()[l]; }
        const int d = m_depth - log2p1(l ^ (r - 1));
        return merge(m_vss[d][l], m_vss[d][r - 1]);
    }

private:
    int m_size, m_depth;
    Vec<Vec<T>> m_vss;
    static inline SemiGroup merge;
};
