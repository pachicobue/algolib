#pragma once
#include "../common.hpp"
/**
 * @brief 複数列のCartesian Product上の Rep
 * @note mdRep({{A0,A1}, {B0, B1, B2}}) = {(A0,B0),(A1,B0),(A0,B1),(A1,B1),(A0,B2),(A1,B2)} となる (※順番に注意)
 */
class mdRep
{
private:
    struct itr
    {
        itr(const Vec<Vec<i64>>& ranges) : m_ranges{ranges}, m_indexes(m_ranges.size(), 0), m_end{false} {}
        bool operator!=(const itr&) const { return not m_end; }
        const Vec<i64> operator*() const
        {
            Vec<i64> Ans(m_ranges.size());
            for (int i : rep(m_ranges.size())) { Ans[i] = m_ranges[i][m_indexes[i]]; }
            return Ans;
        }
        itr& operator++()
        {
            for (int i : rep(m_ranges.size())) {
                m_indexes[i]++;
                if (m_indexes[i] < (int)m_ranges[i].size()) { break; }
                if (i == (int)m_ranges.size() - 1) { m_end = true; }
                m_indexes[i] = 0;
            }
            return *this;
        }

        const Vec<Vec<i64>>& m_ranges;
        Vec<int> m_indexes;
        bool m_end;
    };
    Vec<Vec<i64>> m_ranges;
public:
    /**
     * @brief コンストラクタ
     * 
     * @param ranges (ranges[0] x ... x ranges[D-1]) が Rep範囲 になる
     */
    mdRep(const Vec<Vec<i64>>& ranges) : m_ranges(ranges) { assert(not ranges.empty()); }
    /**
     * @brief begin
     * @attention range-based for からのみ呼ばれる想定
     * 
     * @return itr begin()
     */
    itr begin() const { return itr{m_ranges}; }
    /**
     * @brief end
     * @attention range-based for からのみ呼ばれる想定
     * 
     * @return itr end()
     */
    itr end() const { return itr{m_ranges}; }
};
