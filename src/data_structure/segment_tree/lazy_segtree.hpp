#pragma once
#include "../../common.hpp"
template<typename MergeMonoid, typename OpMonoid, typename Act>
class LazySeg
{
    using T = typename MergeMonoid::T;
    using F = typename OpMonoid::F;
    static constexpr T e() { return MergeMonoid::e(); }
    static constexpr F id() { return OpMonoid::id(); }

public:
    LazySeg(const Vec<T>& vs)
        : m_size(vs.size()),
          m_depth(ceillog(m_size) + 1),
          m_half(1 << (m_depth - 1)),
          m_vs(m_half << 1, e()),
          m_ops(m_half << 1, id())
    {
        std::copy(vs.begin(), vs.end(), m_vs.begin() + m_half);
        for (int i : irange(m_half - 1, 0, -1)) { up(i); }
    }
    LazySeg(int N, const T& v = MergeMonoid::e()) : LazySeg{Vec<T>(N, v)} {}
    T get(const int a)
    {
        assert(a < m_size);
        return fold(a, a + 1);
    }
    void set(int i, const T& v)
    {
        assert(0 <= i and i < m_size);
        i += m_half;
        topDown(i), topDown(i + 1);
        m_ops[i] = id();
        m_vs[i] = v;
        while (i >>= 1) { up(i); }
    }
    T fold(int l, int r)
    {
        assert(0 <= l and l <= r and r <= m_size);
        if (l >= r) { return e(); }
        l += m_half, r += m_half;
        topDown(l), topDown(r);
        T accl = e(), accr = e();
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { accl = merge(accl, m_vs[l++]); }
            if (r & 1) { accr = merge(m_vs[--r], accr); }
        }
        return merge(accl, accr);
    }
    void act(int l, int r, const F& f)
    {
        assert(0 <= l and l <= r and r <= m_size);
        int li = l + m_half, ri = r + m_half;
        topDown(li), topDown(ri);
        for (; li < ri; li >>= 1, ri >>= 1) {
            if (li & 1) { update(li++, f); }
            if (ri & 1) { update(--ri, f); }
        }
        bottomUp(l + m_half), bottomUp(r + m_half);
    }
    friend Ostream& operator<<(Ostream& os, const LazySeg& lseg)
    {
        auto lseg2 = lseg;
        os << "[";
        for (int i : rep(lseg.m_size)) { os << (i == 0 ? "" : ",") << lseg2.get(i); }
        return (os << "]\n");
    }

private:
    void up(int i) { m_vs[i] = merge(m_vs[i << 1], m_vs[i << 1 | 1]); }
    void update(int i, const F& f)
    {
        m_ops[i] = compose(f, m_ops[i]);
        m_vs[i] = apply(f, m_vs[i]);
    }
    void down(int i)
    {
        update(i << 1, m_ops[i]), update(i << 1 | 1, m_ops[i]);
        m_ops[i] = id();
    }
    void topDown(int i)
    {
        const int j = (i / (i & -i)) >> 1;
        for (const int h : per(m_depth)) {
            const int v = i >> h;
            if (v > j) { break; }
            down(v);
        }
    }
    void bottomUp(int i)
    {
        i = (i / (i & -i)) >> 1;
        for (; i >= 1; i >>= 1) { up(i); }
    }
    int m_size, m_depth, m_half;
    Vec<T> m_vs;
    Vec<F> m_ops;
    static inline MergeMonoid merge;
    static inline OpMonoid compose;
    static inline Act apply;
};
