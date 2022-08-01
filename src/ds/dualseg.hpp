#pragma once
#include "../misc/common.hpp"
template<typename OpMonoid>
class DualSegTree
{
    using F = typename OpMonoid::F;
    static constexpr F id()
    {
        return OpMonoid::id();
    }

public:
    DualSegTree(const Vec<F>& vs)
        : m_size(vs.size()),
          m_depth(ceillog(m_size) + 1),
          m_half(1 << m_depth),
          m_ops(m_half << 1, id())
    {
        std::copy(vs.begin(), vs.end(), m_ops.begin() + m_half);
    }
    F get(int i) const
    {
        assert(0 <= i and i < m_size);
        F ans = id();
        i += m_half;
        for (int h : per(m_depth)) {
            ans = compose(ans, m_ops[i >> h]);
        }
        return ans;
    }
    void set(int i, const F& f)
    {
        assert(0 <= i and i < m_size);
        i += m_half;
        clean(i), clean(i + 1);
        m_ops[i] = f;
    }
    void act(int l, int r, const F& f)
    {
        assert(0 <= l and r <= m_size);
        if (l >= r) { return; }
        int li = l + m_half, ri = r + m_half;
        clean(li), clean(ri);
        for (; li < ri; li >>= 1, ri >>= 1) {
            if (li & 1) { update(li++, f); }
            if (ri & 1) { update(--ri, f); }
        }
    }
    friend Ostream& operator<<(Ostream& os, const DualSegTree& seg)
    {
        os << "[";
        for (int i : rep(seg.m_size)) {
            os << (i == 0 ? "" : ",") << seg.get(i);
        }
        return (os << "]\n");
    }

private:
    void down(int i)
    {
        update(i << 1, m_ops[i]), update(i << 1 | 1, m_ops[i]);
        m_ops[i] = id();
    }
    void clean(int i)
    {
        const int b = (i / (i & -i)) >> 1;
        for (const int h : per(m_depth)) {
            const int v = i >> h;
            if (v > b) { break; }
            down(v);
        }
    }
    void update(int i, const F& f)
    {
        m_ops[i] = compose(f, m_ops[i]);
    }
    int m_size, m_depth, m_half;
    Vec<F> m_ops;
    static inline OpMonoid compose;
};
