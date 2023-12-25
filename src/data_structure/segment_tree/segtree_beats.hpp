#pragma once
#include "../../common.hpp"
/**
 * @brief Segment Tree Beats!
 * 
 * @tparam T 値型(失敗したかを保持する)
 * @tparam e 値の単位元
 * @tparam merge 値のマージ
 * @tparam F 作用素型
 * @tparam id 作用素の単位元
 * @tparam compose 作用素の合成
 * @tparam apply モノイド作用(失敗する可能性あり)
 */
template<std::semiregular T, auto e, auto merge, std::regular F, auto id, auto compose, auto apply, auto failed>
    requires requires(const T& x, const T& y, const F& f, const F& g) {
        {
            e()
        } -> std::same_as<T>;
        {
            merge(x, y)
        } -> std::same_as<T>;
        {
            id()
        } -> std::same_as<F>;
        {
            compose(f, g)
        } -> std::same_as<F>;
        {
            apply(f, x)
        } -> std::same_as<T>;
        {
            failed(x)
        } -> std::same_as<bool>;
    }
class SegBeats
{
public:
    /**
     * @brief コンストラクタ
     * 
     * @param xs ベースとなる数列
     */
    template<std::ranges::input_range Xs>
        requires std::convertible_to<std::ranges::range_value_t<Xs>, T>
    SegBeats(Xs&& xs)
        : m_size(std::ranges::size(xs)),
          m_half((int)std::bit_ceil((u64)m_size)),
          m_depth((int)std::bit_width((u64)m_half)),
          m_vals(m_half << 1, e()),
          m_ops(m_half << 1, id())
    {
        std::ranges::copy(xs, m_vals.begin() + m_half);
        for (int i : irange(m_half - 1, 0, -1)) { up(i); }
    }
    /**
     * @brief コンストラクタ
     * 
     * @param N 数列長
     * @param x 初期値
     */
    SegBeats(int N, const T& x = e())
        : m_size(N),
          m_half((int)std::bit_ceil((u64)m_size)),
          m_depth((int)std::bit_width((u64)m_half)),
          m_vals(m_half << 1, e()),
          m_ops(m_half << 1, id())
    {
        std::ranges::fill_n(m_vals.begin() + m_half, N, x);
        for (int i : irange(m_half - 1, 0, -1)) { up(i); }
    }
    /**
     * @brief 1点取得 X[i]
     * 
     * @param i 
     * @return T X[i]
     */
    T get(int i) { return assert(i < m_size), fold(i, i + 1); }
    /**
     * @brief 1点更新 X[i] <- x
     * 
     * @param i 
     * @param x 
     */
    void set(int i, const T& x)
    {
        assert(0 <= i and i < m_size);
        i += m_half;
        topDown(i), topDown(i + 1);
        m_ops[i]  = id();
        m_vals[i] = x;
        while (i >>= 1) { up(i); }
    }
    /**
     * @brief 範囲取得 \prod_{l<=i<r}X[i]
     * 
     * @param l 
     * @param r 
     * @return T 
     */
    T fold(int l, int r)
    {
        assert(0 <= l and l <= r and r <= m_size);
        if (l >= r) { return e(); }
        l += m_half, r += m_half;
        topDown(l), topDown(r);
        T xl = e(), xr = e();
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { xl = merge(xl, m_vals[l++]); }
            if (r & 1) { xr = merge(m_vals[--r], xr); }
        }
        return merge(xl, xr);
    }
    /**
     * @brief 範囲作用 X[i] <- f(X[i]) (l<=i<r)
     * 
     * @param l 
     * @param r 
     * @param f 
     */
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
#ifdef HOGEPACHI
    friend Ostream& operator<<(Ostream& os, const SegBeats& lseg)
    {
        auto lseg2 = lseg;
        os << "[";
        for (int i : rep(lseg.m_size)) { os << (i == 0 ? "" : ",") << lseg2.get(i); }
        return (os << "]\n");
    }
#endif
private:
    void up(int i) { m_vals[i] = merge(m_vals[i << 1], m_vals[i << 1 | 1]); }
    void update(int i, const F& f)
    {
        if (f == id()) { return; }
        m_ops[i]  = compose(f, m_ops[i]);
        m_vals[i] = apply(f, m_vals[i]);
        if (failed(m_vals[i])) { down(i), up(i); }
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
    int m_size, m_half, m_depth;
    Vec<T> m_vals;
    Vec<F> m_ops;
};
