#pragma once
#include <algorithm>
#include <cassert>
#include <initializer_list>
#include "../internal.hpp"
/**
 * @brief 行列 (動的サイズ)
 */
template <typename T> class DynamicMatrix {
    template <typename V> using IList = std::initializer_list<V>;
public:
    /**
     * @brief コンストラクタ
     *
     * @param row 行数
     * @param column 列数
     */
    DynamicMatrix(int row, int column)
        : m_row{row}, m_column{column}, m_vss(row, Vec<T>(column, T{})) {
    }
    /**
     * @brief コンストラクタ
     *
     * @param vss
     */
    DynamicMatrix(const IList<IList<T>>& vss)
        : m_row{(int)vss.size()}, m_column{(int)(vss.begin()->size())}, m_vss(m_row, Vec<T>(m_column, T{})) {
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
    auto operator[](int r) const -> const Vec<T>& {
        return assert(0 <= r and r < m_row), m_vss[r];
    }
    /**
     * @brief 行アクセス (参照)
     *
     * @param r 行番号
     * @return const Vec<T>& 行
     */
    auto operator[](int r) -> Vec<T>& {
        return assert(0 <= r and r < m_row), m_vss[r];
    }
    /**
     * @brief -V
     *
     * @param V
     * @return DynamicMatrix -V
     */
    friend auto operator-(const DynamicMatrix& V) -> DynamicMatrix {
        DynamicMatrix ans(V.m_row, V.m_column);
        for (int i : rep(V.m_row)) {
            for (int j : rep(V.m_column)) {
                ans[i][j] = -V[i][j];
            }
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
    friend auto operator+(const DynamicMatrix& V1, const DynamicMatrix& V2) -> DynamicMatrix {
        assert(V1.m_row == V2.m_row);
        assert(V1.m_column == V2.m_column);
        DynamicMatrix ans(V1.m_row, V1.m_column);
        for (int i : rep(V1.m_row)) {
            for (int j : rep(V1.m_column)) {
                ans[i][j] = V1[i][j] + V2[i][j];
            }
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
    friend auto operator-(const DynamicMatrix& V1, const DynamicMatrix& V2) -> DynamicMatrix {
        assert(V1.m_row == V2.m_row);
        assert(V1.m_column == V2.m_column);
        DynamicMatrix ans(V1.m_row, V1.m_column);
        for (int i : rep(V1.m_row)) {
            for (int j : rep(V1.m_column)) {
                ans[i][j] = V1[i][j] - V2[i][j];
            }
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
    friend auto operator*(const DynamicMatrix& V1, const DynamicMatrix& V2) -> DynamicMatrix {
        assert(V1.m_column == V2.m_row);
        DynamicMatrix ans(V1.m_row, V2.m_column);
        for (int i : rep(V1.m_row)) {
            for (int j : rep(V2.m_column)) {
                for (int k : rep(V1.m_column)) {
                    ans[i][j] += V1[i][k] * V2[k][j];
                }
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
    friend auto operator*(const DynamicMatrix& V, const T& c) -> DynamicMatrix {
        DynamicMatrix ans(V.m_row, V.m_column);
        for (int i : rep(V.m_row)) {
            for (int j : rep(V.m_column)) {
                ans[i][j] = V[i][j] * c;
            }
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
    friend auto operator/(const DynamicMatrix& V, const T& c) -> DynamicMatrix {
        assert(c != 0);
        DynamicMatrix ans(V.m_row, V.m_column);
        for (int i : rep(V.m_row)) {
            for (int j : rep(V.m_column)) {
                ans[i][j] = V[i][j] / c;
            }
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
    friend auto operator+=(DynamicMatrix& V1, const DynamicMatrix& V2) -> DynamicMatrix& {
        return V1 = V1 + V2;
    }
    /**
     * @brief V1 <- V1-V2
     *
     * @param V1
     * @param V2
     * @return DynamicMatrix& V1
     */
    friend auto operator-=(DynamicMatrix& V1, const DynamicMatrix& V2) -> DynamicMatrix& {
        return V1 = V1 - V2;
    }
    /**
     * @brief V1 <- V1*V2
     *
     * @param V1
     * @param V2
     * @return DynamicMatrix& V1
     */
    friend auto operator*=(DynamicMatrix& V1, const DynamicMatrix& V2) -> DynamicMatrix& {
        return V1 = V1 * V2;
    }
    /**
     * @brief V <- cV
     *
     * @param V
     * @param c スカラー
     * @return DynamicMatrix& V
     */
    friend auto operator*=(DynamicMatrix& V, const T& c) -> DynamicMatrix& {
        return V = V * c;
    }
    /**
     * @brief V <- V/c
     *
     * @param V
     * @param c スカラー
     * @return DynamicMatrix& V
     */
    friend auto operator/=(DynamicMatrix& V, const T& c) -> DynamicMatrix& {
        return V = V / c;
    }
    /**
     * @brief V^n
     *
     * @param n 指数
     * @return DynamicMatrix V^n
     */
    auto pow(i64 n) const -> DynamicMatrix {
        return assert(m_row == m_column), powerMonoid(*this, n, DynamicMatrix::I(m_row));
    }
    /**
     * @brief 単位行列
     *
     * @param N サイズ
     * @return DynamicMatrix 単位行列
     */
    static auto I(int N) -> DynamicMatrix {
        DynamicMatrix ans(N, N);
        for (int i : rep(N)) {
            ans[i][i] = 1;
        }
        return ans;
    }
    /**
     * @brief 行数
     *
     * @return int 行数
     */
    auto row() const -> int {
        return m_row;
    }
    /**
     * @brief 列数
     *
     * @return int 列数
     */
    auto column() const -> int {
        return m_column;
    }
#ifdef HOGEPACHI
    friend auto operator<<(Ostream& os, const DynamicMatrix& m) -> Ostream& {
        os << "[\n";
        for (int i : rep(m.m_row)) {
            os << "[";
            for (int j : rep(m.m_column)) {
                os << m[i][j] << ",";
            }
            os << "]\n";
        }
        return (os << "]\n");
    }
#endif
private:
    int m_row, m_column;
    Vec<Vec<T>> m_vss;
};
