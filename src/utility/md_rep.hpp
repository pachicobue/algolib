#pragma once
#include "../internal.hpp"
/**
 * @brief 複数列のCartesian Product上の Rep
 * @note mdRep({{A0,A1}, {B0, B1, B2}}) = {(A0,B0),(A0,B1),(A0,B2),(A1,B0),(A1,B1),(A1,B2)} となる
 */
template <typename T> class mdRep {
private:
    struct itr {
        itr(const Vec<Vec<T>>& ranges) : m_ranges{ranges}, m_indexes(m_ranges.size(), 0), m_end{ranges.empty()} {}
        auto operator!=(const itr&) const -> bool { return not m_end; }
        auto operator*() const -> const Vec<T>& {
            Vec<T> Ans(m_ranges.size());
            for (int i : rep(m_ranges.size())) { Ans[i] = m_ranges[i][m_indexes[i]]; }
            return Ans;
        }
        auto operator++() -> itr& {
            for (int i : per(m_ranges.size())) {
                m_indexes[i]++;
                if (m_indexes[i] < (int)m_ranges[i].size()) { break; }
                if (i == 0) { m_end = true; }
                m_indexes[i] = 0;
            }
            return *this;
        }

        const Vec<Vec<T>>& m_ranges;
        Vec<int> m_indexes;
        bool m_end;
    };
    Vec<Vec<T>> m_ranges;
public:
    /**
     * @brief コンストラクタ
     *
     * @param ranges (ranges[0] x ... x ranges[D-1]) が Rep範囲 になる
     */
    mdRep(const Vec<Vec<T>>& ranges) : m_ranges(ranges) {}
    /**
     * @brief begin
     * @attention range-based for からのみ呼ばれる想定
     *
     * @return itr begin()
     */
    auto begin() const -> itr { return itr{m_ranges}; }
    /**
     * @brief end
     * @attention range-based for からのみ呼ばれる想定
     *
     * @return itr end()
     */
    auto end() const -> itr { return itr{m_ranges}; }
};
