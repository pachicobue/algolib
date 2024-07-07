#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <concepts>
#include <ranges>
#include "../../internal.hpp"
/**
 * @brief 双対セグ木
 *
 * @tparam F 作用素型
 * @tparam id 作用素の単位元
 * @tparam compose 作用素の合成
 */
template <std::semiregular F, auto id, auto compose>
requires requires(const F& f, const F& g) {
    {
        id()
    } -> std::convertible_to<F>;
    {
        compose(f, g)
    } -> std::convertible_to<F>;
}
class DualSegTree {
public:
    /**
     * @brief コンストラクタ
     *
     * @param fs ベースとなる作用素列
     */
    template <std::ranges::input_range Fs> DualSegTree(Fs&& fs)
        requires std::ranges::sized_range<Fs> && std::convertible_to<std::ranges::range_value_t<Fs>, F>
        : m_size(std::ranges::size(fs)),
          m_half((int)std::bit_ceil((u64)m_size)),
          m_depth((int)std::bit_width((u64)m_half)),
          m_ops(m_half << 1, id()) {
        std::ranges::copy(fs, m_ops.begin() + m_half);
    }
    /**
     * @brief コンストラクタ
     *
     * @param N 作用素列長
     * @param f 作用素の初期値
     */
    DualSegTree(int N, const F& f = id()) : DualSegTree(Vec<F>(N, f)) {}

    /**
     * @brief 1点取得 F[i]
     *
     * @param i
     * @return F F[i]
     */
    auto get(int i) const -> F {
        assert(0 <= i and i < m_size);
        F ans = id();
        i += m_half;
        for (int h : per(m_depth)) { ans = compose(ans, m_ops[i >> h]); }
        return ans;
    }
    /**
     * @brief 1点更新 F[i] <- f
     *
     * @param i
     * @param f
     */
    auto set(int i, const F& f) -> void {
        assert(0 <= i and i < m_size);
        i += m_half;
        clean(i), clean(i + 1);
        m_ops[i] = f;
    }
    /**
     * @brief 区間作用 F[i] <- (f \circ F[i]) (l <= i < r)
     *
     * @param l
     * @param r
     * @param f
     */
    auto act(int l, int r, const F& f) -> void {
        assert(0 <= l and r <= m_size);
        if (l >= r) { return; }
        int li = l + m_half, ri = r + m_half;
        clean(li), clean(ri);
        for (; li < ri; li >>= 1, ri >>= 1) {
            if (li & 1) { update(li++, f); }
            if (ri & 1) { update(--ri, f); }
        }
    }
#ifdef HOGEPACHI
    friend auto operator<<(Ostream& os, const DualSegTree& seg) -> Ostream& {
        os << "[";
        for (int i : rep(seg.m_size)) { os << (i == 0 ? "" : ",") << seg.get(i); }
        return (os << "]\n");
    }
#endif
private:
    auto down(int i) -> void {
        update(i << 1, m_ops[i]), update(i << 1 | 1, m_ops[i]);
        m_ops[i] = id();
    }
    auto clean(int i) -> void {
        const int b = (i / (i & -i)) >> 1;
        for (const int h : per(m_depth)) {
            const int v = i >> h;
            if (v > b) { break; }
            down(v);
        }
    }
    auto update(int i, const F& f) -> void { m_ops[i] = compose(f, m_ops[i]); }
    int m_size, m_half, m_depth;
    Vec<F> m_ops;
};
