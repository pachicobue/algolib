#pragma once
#include "../common.hpp"
/**
 * @brief 行列 (動的サイズ)
 */
template<typename T> class DynamicMatrix
{
    template<typename V> using IList = std::initializer_list<V>;
public:
    /**
     * @brief コンストラクタ
     * 
     * @param row 行数
     * @param column 列数
     */
    constexpr DynamicMatrix(int row, int column) : m_row{row}, m_column{column}, m_vss(row, Vec<T>(column, T{})) {}
    /**
     * @brief コンストラクタ
     * 
     * @param vss 
     */
    constexpr DynamicMatrix(const IList<IList<T>>& vss)
        : m_row{(int)vss.size()}, m_column{(int)(vss.begin()->size())}, m_vss(m_row, Vec<T>(m_column, T{}))
    {
        int i = 0;
        for (auto it = vss.begin(); it != vss.end(); it++) {
            assert((int)it->size() == m_column);
            std::ranges::copy(*it, m_vss[i++].begin());
        }
    }
    /**
     * @brief 行アクセス (const)
     * 
     * @param r 行番号
     * @return const Vec<T>& 行
     */
    constexpr const Vec<T>& operator[](int r) const { return assert(0 <= r and r < m_row), m_vss[r]; }
    /**
     * @brief 行アクセス (参照)
     * 
     * @param r 行番号
     * @return const Vec<T>& 行
     */
    constexpr Vec<T>& operator[](int r) { return assert(0 <= r and r < m_row), m_vss[r]; }
    /**
     * @brief -V
     * 
     * @param V 
     * @return DynamicMatrix -V
     */
    constexpr friend DynamicMatrix operator-(const DynamicMatrix& V)
    {
        DynamicMatrix ans(V.m_row, V.m_column);
        for (int i : rep(V.m_row)) {
            for (int j : rep(V.m_column)) { ans[i][j] = -V[i][j]; }
        }
        return ans;
    }
    /**
     * @brief V1+V2
     * 
     * @param V1 
     * @param V2 
     * @return DynamicMatrix V1+V2
     */
    constexpr friend DynamicMatrix operator+(const DynamicMatrix& V1, const DynamicMatrix& V2)
    {
        assert(V1.m_row == V2.m_row);
        assert(V1.m_column == V2.m_column);
        DynamicMatrix ans(V1.m_row, V1.m_column);
        for (int i : rep(V1.m_row)) {
            for (int j : rep(V1.m_column)) { ans[i][j] = V1[i][j] + V2[i][j]; }
        }
        return ans;
    }
    /**
     * @brief V1-V2
     * 
     * @param V1 
     * @param V2 
     * @return DynamicMatrix V1-V2
     */
    constexpr friend DynamicMatrix operator-(const DynamicMatrix& V1, const DynamicMatrix& V2)
    {
        assert(V1.m_row == V2.m_row);
        assert(V1.m_column == V2.m_column);
        DynamicMatrix ans(V1.m_row, V1.m_column);
        for (int i : rep(V1.m_row)) {
            for (int j : rep(V1.m_column)) { ans[i][j] = V1[i][j] - V2[i][j]; }
        }
        return ans;
    }
    /**
     * @brief V1*V2
     * 
     * @param V1 
     * @param V2 
     * @return DynamicMatrix V1*V2
     */
    constexpr friend DynamicMatrix operator*(const DynamicMatrix& V1, const DynamicMatrix& V2)
    {
        assert(V1.m_column == V2.m_row);
        DynamicMatrix ans(V1.m_row, V2.m_column);
        for (int i : rep(V1.m_row)) {
            for (int j : rep(V2.m_column)) {
                for (int k : rep(V1.m_column)) { ans[i][j] += V1[i][k] * V2[k][j]; }
            }
        }
        return ans;
    }
    /**
     * @brief cV 
     * 
     * @param V 
     * @param c スカラー
     * @return DynamicMatrix cV
     */
    constexpr friend DynamicMatrix operator*(const DynamicMatrix& V, const T& c)
    {
        DynamicMatrix ans(V.m_row, V.m_column);
        for (int i : rep(V.m_row)) {
            for (int j : rep(V.m_column)) { ans[i][j] = V[i][j] * c; }
        }
        return ans;
    }
    /**
     * @brief V/c 
     * 
     * @param V 
     * @param c スカラー
     * @return DynamicMatrix V/c
     */
    constexpr friend DynamicMatrix operator/(const DynamicMatrix& V, const T& c)
    {
        assert(c != 0);
        DynamicMatrix ans(V.m_row, V.m_column);
        for (int i : rep(V.m_row)) {
            for (int j : rep(V.m_column)) { ans[i][j] = V[i][j] / c; }
        }
        return ans;
    }
    /**
     * @brief V1 <- V1+V2
     * 
     * @param V1 
     * @param V2 
     * @return DynamicMatrix& V1
     */
    constexpr friend DynamicMatrix& operator+=(DynamicMatrix& V1, const DynamicMatrix& V2) { return V1 = V1 + V2; }
    /**
     * @brief V1 <- V1-V2
     * 
     * @param V1 
     * @param V2 
     * @return DynamicMatrix& V1
     */
    constexpr friend DynamicMatrix& operator-=(DynamicMatrix& V1, const DynamicMatrix& V2) { return V1 = V1 - V2; }
    /**
     * @brief V1 <- V1*V2
     * 
     * @param V1 
     * @param V2 
     * @return DynamicMatrix& V1
     */
    constexpr friend DynamicMatrix& operator*=(DynamicMatrix& V1, const DynamicMatrix& V2) { return V1 = V1 * V2; }
    /**
     * @brief V <- cV
     * 
     * @param V 
     * @param c スカラー
     * @return DynamicMatrix& V
     */
    constexpr friend DynamicMatrix& operator*=(DynamicMatrix& V, const T& c) { return V = V * c; }
    /**
     * @brief V <- V/c
     * 
     * @param V 
     * @param c スカラー
     * @return DynamicMatrix& V
     */
    constexpr friend DynamicMatrix& operator/=(DynamicMatrix& V, const T& c) { return V = V / c; }
    /**
     * @brief V^n
     * 
     * @param n 指数
     * @return DynamicMatrix V^n
     */
    constexpr DynamicMatrix pow(i64 n) const { return assert(m_row == m_column), powerMonoid(*this, n, DynamicMatrix::I(m_row)); }
    /**
     * @brief 単位行列
     * 
     * @param N サイズ
     * @return DynamicMatrix 単位行列
     */
    constexpr static DynamicMatrix I(int N)
    {
        DynamicMatrix ans(N, N);
        for (int i : rep(N)) { ans[i][i] = 1; }
        return ans;
    }
    /**
     * @brief 行数
     * 
     * @return int 行数
     */
    constexpr int row() const { return m_row; }
    /**
     * @brief 列数
     * 
     * @return int 列数
     */
    constexpr int column() const { return m_column; }
#ifdef HOGEPACHI
    friend Ostream& operator<<(Ostream& os, const DynamicMatrix& m)
    {
        os << "[\n";
        for (int i : rep(m.m_row)) {
            os << "[";
            for (int j : rep(m.m_column)) { os << m[i][j] << ","; }
            os << "]\n";
        }
        return (os << "]\n");
    }
#endif
private:
    int m_row, m_column;
    Vec<Vec<T>> m_vss;
};
