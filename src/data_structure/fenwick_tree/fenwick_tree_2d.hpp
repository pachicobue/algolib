#pragma once
#include "../../common.hpp"
template<typename T>
class FenwickTree2D
{
public:
    FenwickTree2D(const Vec<Vec<T>>& vss)
        : m_hsize(vss.size()),
          m_wsize(vss.front().size()),
          m_hcap(ceil2(m_hsize)),
          m_wcap(ceil2(m_wsize)),
          m_vss(m_hcap + 1, Vec<T>(m_wcap + 1, T{}))
    {
        for (int i : rep(m_hsize)) {
            for (int j : rep(m_wsize)) { add(i, j, vss[i][j]); }
        }
    }
    FenwickTree2D(int N, int M, const T& v = T{}) : FenwickTree2D{Vec<Vec<T>>(N, Vec<T>(M, v))} {}
    void add(int i, int j, const T& v)
    {
        assert(0 <= i and i < m_hsize);
        assert(0 <= j and j < m_wsize);
        for (int iind = i + 1; iind <= m_hcap; iind += iind & (-iind)) {
            for (int jind = j + 1; jind <= m_wcap; jind += jind & (-jind)) {
                m_vss[iind][jind] += v;
            }
        }
    }
    T sum(int i, int j) const
    {
        assert(0 <= i and i <= m_hsize);
        assert(0 <= j and j <= m_wsize);
        T sum{};
        for (int iind = i; iind != 0; iind &= iind - 1) {
            for (int jind = j; jind != 0; jind &= jind - 1) { sum += m_vss[iind][jind]; }
        }
        return sum;
    }
    T sum(int imin, int imax, int jmin, int jmax) const
    {
        assert(0 <= imin and imin <= imax and imax <= m_hsize);
        assert(0 <= jmin and jmin <= jmax and jmax <= m_wsize);
        return sum(imax, jmax) - sum(imax, jmin) - sum(imin, jmax) + sum(imin, jmin);
    }
    friend Ostream& operator<<(Ostream& os, const FenwickTree2D& fw)
    {
        os << "[";
        for (int i : rep(fw.m_hsize)) {
            os << "[";
            for (int j : rep(fw.m_wsize)) {
                os << (i == 0 ? "" : ",") << fw.sum(i, i + 1, j, j + 1);
            }
            os << "]\n";
        }
        return os;
    }

private:
    int m_hsize, m_wsize;
    int m_hcap, m_wcap;
    Vec<Vec<T>> m_vss;
};
