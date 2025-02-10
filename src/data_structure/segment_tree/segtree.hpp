#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <concepts>
#include <ranges>
#include "../../internal.hpp"
/**
 * @brief セグメント木
 *
 * @tparam T 値型
 * @tparam e 値の単位元
 * @tparam merge 値のマージ
 */
template <std::semiregular T, auto e, auto merge>
requires requires(const T& x, const T& y) {
    {
        e()
    } -> std::convertible_to<T>;
    {
        merge(x, y)
    } -> std::convertible_to<T>;
}
class SegTree {
public:
    /**
     * @brief コンストラクタ
     *
     * @param xs ベースとなる数列
     */
    template <std::ranges::input_range Xs>
    requires std::ranges::sized_range<Xs> && std::convertible_to<std::ranges::range_value_t<Xs>, T>
    SegTree(Xs&& xs)
        : m_size(std::ranges::size(xs)), m_half((int)std::bit_ceil((u64)m_size)), m_vals(m_half << 1, e()) {
        std::ranges::copy(xs, m_vals.begin() + m_half);
        for (int i : irange(m_half - 1, 0, -1)) {
            up(i);
        }
    }
    /**
     * @brief コンストラクタ
     *
     * @param N 数列長
     * @param x 初期値
     */
    SegTree(int N, const T& x = e())
        : SegTree(Vec<T>(N, x)) {
    }
    /**
     * @brief 1点取得 X[i]
     *
     * @param i
     * @return T
     */
    auto get(int i) -> T const {
        return assert(0 <= i and i < m_size), m_vals[i + m_half];
    }
    /**
     * @brief 1点更新 X[i] <- v
     *
     * @param i
     * @param x
     */
    auto set(int i, const T& x) -> void {
        assert(0 <= i and i < m_size);
        m_vals[i += m_half] = x;
        while (i >>= 1) {
            up(i);
        }
    }
    /**
     * @brief 範囲取得 \prod_{l<=i<r}X[i]
     *
     * @param l
     * @param r
     * @return T
     */
    auto fold(int l, int r) const -> T {
        assert(0 <= l and l <= r and r <= m_size);
        T lx = e(), rx = e();
        int li = l + m_half, ri = r + m_half;
        for (; li < ri; li >>= 1, ri >>= 1) {
            if (li & 1) {
                lx = merge(lx, m_vals[li++]);
            }
            if (ri & 1) {
                rx = merge(m_vals[--ri], rx);
            }
        }
        return merge(lx, rx);
    }
#ifdef HOGEPACHI
    friend auto operator<<(Ostream& os, const SegTree& seg) -> Ostream& {
        os << "[";
        for (int i : rep(seg.m_size)) {
            os << (i == 0 ? "" : ",") << seg.m_vals[i + seg.m_half];
        }
        return (os << "]");
    }
#endif
private:
    auto up(int i) -> void {
        m_vals[i] = merge(m_vals[i << 1], m_vals[i << 1 | 1]);
    }
    int m_size, m_half;
    Vec<T> m_vals;
};
