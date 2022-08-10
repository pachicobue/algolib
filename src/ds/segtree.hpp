#pragma once
#include "../common.hpp"
template<typename MergeMonoid>
class SegTree
{
    using T = typename MergeMonoid::T;
    static constexpr T e()
    {
        return MergeMonoid::e();
    }

public:
    SegTree(const Vec<T>& vs)
        : m_size(vs.size()),
          m_half(ceil2(m_size)),
          m_vals(m_half << 1, MergeMonoid::e())
    {
        std::copy(vs.begin(), vs.end(), m_vals.begin() + m_half);
        for (int i = m_half - 1; i >= 1; i--) {
            up(i);
        }
    }
    SegTree(int N, const T& v = MergeMonoid::e()) : SegTree{Vec<T>(N, v)} {}
    T get(int i) const
    {
        assert(0 <= i and i < m_size);
        return m_vals[i + m_half];
    }
    void set(int i, const T& v)
    {
        assert(0 <= i and i < m_size);
        m_vals[i += m_half] = v;
        while (i >>= 1) {
            up(i);
        }
    }
    T fold(int l, int r) const
    {
        assert(0 <= l and l <= r and r <= m_size);
        T lv = e(), rv = e();
        int li = l + m_half, ri = r + m_half;
        for (; li < ri; li >>= 1, ri >>= 1) {
            if (li & 1) { lv = merge(lv, m_vals[li++]); }
            if (ri & 1) { rv = merge(m_vals[--ri], rv); }
        }
        return merge(lv, rv);
    }
    friend Ostream& operator<<(Ostream& os, const SegTree& seg)
    {
        os << "[";
        for (int i : rep(seg.m_size)) {
            os << (i == 0 ? "" : ",") << seg.m_vals[i + seg.m_half];
        }
        return (os << "]");
    }

private:
    void up(int i)
    {
        m_vals[i] = merge(m_vals[i << 1], m_vals[i << 1 | 1]);
    }
    int m_size, m_half;
    Vec<T> m_vals;
    static inline MergeMonoid merge;
};
