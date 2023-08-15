#pragma once
#include "../../common.hpp"
/**
 * @brief 2次元Fenwick Tree
 */
template<typename T> class FenwickTree2D
{
public:
    /**
     * @brief コンストラクタ
     * 
     * @param xss ベースとなる2次元数列
     */
    FenwickTree2D(const Vec<Vec<T>>& xss)
        : m_hsize(xss.size()),
          m_wsize(xss.front().size()),
          m_hcap((int)std::bit_ceil((u64)m_hsize)),
          m_wcap((int)std::bit_ceil((u64)m_wsize)),
          m_xss(m_hcap + 1, Vec<T>(m_wcap + 1, T{}))
    {
        for (int i : rep(m_hsize)) { std::ranges::copy(xss[i], m_xss[i + 1].begin() + 1); }
        for (int i : irange(1, m_hcap)) {
            for (int j : irange(1, m_wcap)) { m_xss[i][j + (j & -j)] += m_xss[i][j]; }
        }
        for (int i : irange(1, m_hcap)) {
            for (int j : irange(1, m_wcap)) { m_xss[i + (i & -i)][j] += m_xss[i][j]; }
        }
    }
    /**
     * @brief コンストラクタ
     * 
     * @param N 縦
     * @param M 横
     * @param x 初期値
     */
    FenwickTree2D(int N, int M, const T& x = T{}) : FenwickTree2D{Vec<Vec<T>>(N, Vec<T>(M, x))} {}
    /**
     * @brief 一点加算 X[i][j] <- X[i][j]+x
     * 
     * @param i 
     * @param j 
     * @param x 加算値
     */
    void add(int i, int j, const T& x)
    {
        assert(0 <= i and i < m_hsize);
        assert(0 <= j and j < m_wsize);
        for (int iind = i + 1; iind <= m_hcap; iind += iind & (-iind)) {
            for (int jind = j + 1; jind <= m_wcap; jind += jind & (-jind)) { m_xss[iind][jind] += x; }
        }
    }
    /**
     * @brief 2次元累積和 \sum_{0<=i<isup}\sum_{0<=j<jsup}X[i][j]
     * 
     * @param isup 
     * @param jsup 
     * @return T 2次元累積和
     */
    T sum(int isup, int jsup) const
    {
        assert(0 <= isup and isup <= m_hsize);
        assert(0 <= jsup and jsup <= m_wsize);
        T sum{};
        for (int i = isup; i != 0; i &= i - 1) {
            for (int j = jsup; j != 0; j &= j - 1) { sum += m_xss[i][j]; }
        }
        return sum;
    }
    /**
     * @brief 矩形領域和 \sum_{imin<=i<isup}\sum_{jmin<=j<jsup}X[i][j] を求める
     * 
     * @param imin 
     * @param isup 
     * @param jmin 
     * @param jsup 
     * @return T 矩形領域和
     */
    T sum(int imin, int isup, int jmin, int jsup) const
    {
        assert(0 <= imin and imin <= isup and isup <= m_hsize);
        assert(0 <= jmin and jmin <= jsup and jsup <= m_wsize);
        return sum(isup, jsup) - sum(isup, jmin) - sum(imin, jsup) + sum(imin, jmin);
    }
#ifdef HOGEPACHI
    friend Ostream& operator<<(Ostream& os, const FenwickTree2D& fw)
    {
        os << "[";
        for (int i : rep(fw.m_hsize)) {
            os << "[";
            for (int j : rep(fw.m_wsize)) { os << (i == 0 ? "" : ",") << fw.sum(i, i + 1, j, j + 1); }
            os << "]\n";
        }
        return os;
    }
#endif
private:
    int m_hsize, m_wsize;
    int m_hcap, m_wcap;
    Vec<Vec<T>> m_xss;
};
