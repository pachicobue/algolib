#pragma once
#include "../../common.hpp"
/**
 * @brief Fenwick Tree
 */
template<typename T> class FenwickTree
{
public:
    /**
     * @brief コンストラクタ
     * 
     * @param xs ベースとなる数列
     */
    FenwickTree(const Vec<T>& xs) : m_size(xs.size()), m_cap((int)std::bit_ceil((u64)m_size)), m_xs(m_cap + 1, T{})
    {
        std::ranges::copy(xs, m_xs.begin() + 1);
        for (int x : irange(1, m_cap)) { m_xs[x + (x & -x)] += m_xs[x]; }
    }
    /**
     * @brief コンストラクタ
     * 
     * @param N 数列長
     * @param x 初期値
     */
    FenwickTree(int N, const T& x = T{}) : FenwickTree{Vec<T>(N, x)} {}
    /**
     * @brief 一点加算 X[i] <- X[i]+x
     * 
     * @param i 
     * @param x 加算値
     */
    void add(int i, const T& x)
    {
        assert(0 <= i and i < m_size);
        for (int ind = i + 1; ind <= m_cap; ind += ind & (-ind)) { m_xs[ind] += x; }
    }
    /**
     * @brief 累積和 \sum_{0<=i<isup}X[i] 
     * 
     * @param isup 
     * @return T 累積和
     */
    T sum(int isup) const
    {
        assert(0 <= isup and isup <= m_size);
        T sum{};
        for (int ind = isup; ind != 0; ind &= ind - 1) { sum += m_xs[ind]; }
        return sum;
    }
    /**
     * @brief 区間和 \sum_{imin<=i<isup}X[i] 
     * 
     * @param imin 
     * @param imax 
     * @return T 区間和
     */
    T sum(int imin, int imax) const
    {
        assert(0 <= imin and imin <= imax and imax <= m_size);
        return sum(imax) - sum(imin);
    }
    /**
     * @brief pred(\sum_{0<=i<x})==True となる最小の x
     * 
     * @param pred 判定関数
     * @return int 最小のx (Trueになる x が存在しない場合 N+1)
     */
    int maxRight(auto pred)
    {
        if (pred(T{})) { return 0; }
        if (not pred(m_xs[m_cap])) { return m_size + 1; }
        int ng = 0, ok = m_cap;
        T sum = 0;
        while (ok - ng > 1) {
            const int mid = (ok + ng) / 2;
            if (pred(sum + m_xs[mid])) {
                ok = mid;
            } else {
                ng = mid, sum += m_xs[mid];
            }
        }
        return ok;
    }
#ifdef HOGEPACHI
    friend Ostream& operator<<(Ostream& os, const FenwickTree& fw)
    {
        os << "[";
        for (int i : rep(fw.m_size)) { os << (i == 0 ? "" : ",") << fw.sum(i, i + 1); }
        return (os << "]\n");
    }
#endif
private:
    int m_size, m_cap;
    Vec<T> m_xs;
};
