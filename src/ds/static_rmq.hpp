#pragma once
#include "../common.hpp"
#include "ds_table.hpp"
template<typename TotalOrd>
class StaticRMQ
{
    using T = typename TotalOrd::T;

public:
    StaticRMQ(const Vec<T>& vs)
        : m_size(vs.size()),
          m_bn(wind(m_size + bs - 1)),
          m_vals{vs},
          m_bucket_vals([&]() {
              Vec<T> ans(m_bn);
              for (int i : rep(m_size)) {
                  ans[wind(i)]
                      = (i % bs == 0 ? m_vals[i] : std::min(ans[wind(i)], m_vals[i], comp));
              }
              return ans;
          }()),
          m_masks(m_size, 0),
          m_st(m_bucket_vals)
    {
        for (int i : rep(m_bn)) {
            Vec<int> g(bs, m_size), stack;
            for (const int j : rep(bs)) {
                if (ind(i, j) >= m_size) { break; }
                for (; not stack.empty() and not comp(m_vals[stack.back()], m_vals[ind(i, j)]);
                     stack.pop_back()) {}
                g[j] = stack.empty() ? m_size : stack.back(), stack.push_back(ind(i, j));
            }
            for (int j : rep(bs)) {
                if (ind(i, j) >= m_size) { break; }
                m_masks[ind(i, j)] = g[j] == m_size
                                         ? static_cast<B>(0)
                                         : (m_masks[g[j]] | static_cast<B>(1) << (g[j] - i * bs));
            }
        }
    }
    T fold(int l, int r) const
    {
        assert(0 <= l and l < r and r <= m_size);
        const int lb = (l + bs - 1) / bs, rb = r / bs;
        if (lb > rb) {
            return brmq(l, r);
        } else {
            return lb < rb
                       ? (l < bs * lb
                              ? (bs * rb < r ? std::min(
                                     {m_st.fold(lb, rb), brmq(l, bs * lb), brmq(bs * rb, r)}, comp)
                                             : std::min(m_st.fold(lb, rb), brmq(l, bs * lb), comp))
                              : (bs * rb < r ? std::min(m_st.fold(lb, rb), brmq(bs * rb, r), comp)
                                             : m_st.fold(lb, rb)))
                       : (l < bs * lb
                              ? (bs * rb < r ? std::min(brmq(l, bs * lb), brmq(bs * rb, r), comp)
                                             : brmq(l, bs * lb))
                              : (bs * rb < r ? brmq(bs * rb, r) : T{}));
        }
    }

private:
    using B = u64;
    static constexpr int bs = sizeof(B) * 8;
    static constexpr int bslog = log2p1(bs) - 1;
    static constexpr int wind(int n) { return n >> (bslog); }
    static constexpr int bind(int n) { return n ^ (wind(n) << bslog); }
    static constexpr int ind(int w, int b) { return (w << bslog) | b; }
    T brmq(int l, int r) const
    {
        const B w = m_masks[r - 1] >> (l % bs);
        return w == 0 ? m_vals[r - 1] : m_vals[l + lsbp1(w) - 1];
    }
    struct SemiGroup
    {
        using T = typename TotalOrd::T;
        T operator()(const T& x1, const T& x2) const { return std::min(x1, x2, comp); }
    };
    static inline TotalOrd comp;
    int m_size, m_bn;
    Vec<T> m_vals, m_bucket_vals;
    Vec<B> m_masks;
    DisjointSparseTable<SemiGroup> m_st;
};
