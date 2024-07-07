#pragma once
#include <bit>
#include <cassert>
#include <concepts>
#include <ranges>
#include "../../internal.hpp"
/**
 * @brief Disjoint Sparse Table
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
class DisjointSparseTable {
public:
    /**
     * @brief コンストラクタ
     *
     * @param xs 数列
     */
    template <std::ranges::random_access_range Xs>
    requires std::ranges::sized_range<Xs> && std::convertible_to<std::ranges::range_value_t<Xs>, T>
    DisjointSparseTable(Xs&& xs) : m_size(std::ranges::size(xs)), m_depth((int)std::bit_width((u64)m_size)), m_xss(m_depth, xs) {
        for (int d : rep(m_depth)) {
            const int w = 1 << (m_depth - d - 1);
            for (int i = 1; i * w < m_size; i += 2) {
                int l = i * w - 1, r = i * w;
                for (int j : irange(1, w)) {
                    m_xss[d][l - j] = merge(xs[l - j], m_xss[d][l - j + 1]);
                    if (r + j < m_size) { m_xss[d][r + j] = merge(xs[r + j], m_xss[d][r + j - 1]); }
                }
            }
        }
    }
    /**
     * @brief 範囲取得
     *
     * @param l
     * @param r
     * @return T \prod{l<=i<r}X[i]
     */
    auto fold(int l, int r) const -> T {
        assert(0 <= l and l <= r and r <= m_size);
        if (l == r) { return e(); }
        if (r - l == 1) { return m_xss.back()[l]; }
        const int d = m_depth - (int)std::bit_width((u64)(l ^ (r - 1)));
        return merge(m_xss[d][l], m_xss[d][r - 1]);
    }
private:
    int m_size, m_depth;
    Vec<Vec<T>> m_xss;
};
