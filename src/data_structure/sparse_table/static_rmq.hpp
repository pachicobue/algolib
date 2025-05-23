#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <concepts>
#include <ranges>
#include "../../internal.hpp"
#include "disjoint_sparse_table.hpp"
/**
 * @brief 静的数列のRMQ
 * @see https://noshi91.hatenablog.com/entry/2018/08/16/125415
 * @see https://qiita.com/okateim/items/e2f4a734db4e5f90e410
 *
 * @tparam T 値型
 * @tparam maximum 最大値(任意のxについて comp(maximum(),x)==False )
 * @tparam comp 比較関数
 */
template <std::semiregular T, auto maximum, auto comp>
requires requires(const T& x, const T& y) {
    {
        maximum()
    } -> std::convertible_to<T>;
    {
        comp(x, y)
    } -> std::same_as<bool>;
}
class StaticRMQ {
    using B = u64;
    static constexpr int bs = sizeof(B) * 8;
    static constexpr int bslog = (int)std::bit_width((u64)bs) - 1;
    static constexpr int wind(int n) {
        return n >> (bslog);
    }
    static constexpr int bind(int n) {
        return n ^ (wind(n) << bslog);
    }
    static constexpr int ind(int w, int b) {
        return (w << bslog) | b;
    }
public:
    /**
     * @brief コンストラクタ
     *
     * @param xs 数列
     */
    template <std::ranges::input_range Xs>
    requires std::ranges::sized_range<Xs> && std::convertible_to<std::ranges::range_value_t<Xs>, T>
    StaticRMQ(Xs&& xs)
        : m_size(std::ranges::size(xs)),
          m_bn{wind(m_size + bs - 1)},
          m_vals(std::ranges::begin(xs), std::ranges::end(xs)),
          m_masks(m_size, 0),
          m_st{[&]() {
              Vec<T> ans(m_bn);
              for (int i : rep(m_size)) {
                  ans[wind(i)] = (i % bs == 0 ? m_vals[i] : std::ranges::min(ans[wind(i)], m_vals[i], comp));
              }
              return ans;
          }()} {
        for (int i : rep(m_bn)) {
            Vec<int> g(bs, m_size), stack;
            for (const int j : rep(bs)) {
                if (ind(i, j) >= m_size) {
                    break;
                }
                for (; not stack.empty() and not comp(m_vals[stack.back()], m_vals[ind(i, j)]); stack.pop_back()) {
                }
                g[j] = (stack.empty() ? m_size : stack.back());
                stack.push_back(ind(i, j));
            }
            for (int j : rep(bs)) {
                if (ind(i, j) >= m_size) {
                    break;
                }
                m_masks[ind(i, j)] = g[j] == m_size ? B{0} : (m_masks[g[j]] | B{1} << (g[j] - i * bs));
            }
        }
    }
    /**
     * @brief 範囲Min
     *
     * @param l
     * @param r
     * @return T \min_{l<=i<r}X[i]
     */
    auto fold(int l, int r) const -> T {
        assert(0 <= l and l <= r and r <= m_size);
        const int lb = (l + bs - 1) / bs, rb = r / bs;
        if (lb > rb) {
            return brmq(l, r);
        } else {
            return std::ranges::min({m_st.fold(lb, rb), brmq(l, bs * lb), brmq(bs * rb, r)}, comp);
        }
    }
private:
    auto brmq(int l, int r) const -> T {
        if (l == r) {
            return maximum();
        }
        const B w = m_masks[r - 1] >> (l % bs);
        return w == 0 ? m_vals[r - 1] : m_vals[l + order2(w)];
    }
    int m_size, m_bn;
    Vec<T> m_vals, m_bucket_vals;
    Vec<B> m_masks;
    DisjointSparseTable<T, maximum, [](const T& x1, const T& x2) {
        return std::ranges::min(x1, x2, comp);
    }>
        m_st;
};
