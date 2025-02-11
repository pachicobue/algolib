#pragma once
#include <algorithm>
#include <cassert>
#include <initializer_list>
#include "../internal.hpp"
/**
 * @brief 行列 (静的サイズ)
 */
template <typename T, int row, int column> class StaticMatrix {
    template <typename V> using IList = std::initializer_list<V>;
public:
    /**
     * @brief コンストラクタ
     */
    constexpr StaticMatrix() {
        mdSeqFill(m_vss, T{});
    }
    /**
     * @brief コンストラクタ
     *
     * @param vss
     */
    constexpr StaticMatrix(const IList<IList<T>>& vss) {
        assert(row == vss.size());
        assert(column == vss.begin()->size());
        int i = 0;
        for (auto it = vss.begin(); it != vss.end(); it++) {
            assert((int)it->size() == column);
            std::ranges::copy(*it, m_vss[i++].begin());
        }
    }
    /**
     * @brief 行アクセス (const)
     *
     * @param r 行番号
     * @return Arr<T, column>& 行
     */
    constexpr auto operator[](int r) const -> const Arr<T, column>& {
        return m_vss[r];
    }
    /**
     * @brief 行アクセス (参照)
     *
     * @param r 行番号
     * @return Arr<T, column>& 行
     */
    constexpr auto operator[](int r) -> Arr<T, column>& {
        return m_vss[r];
    }
    /**
     * @brief -V
     *
     * @param V
     * @return StaticMatrix -V
     */
    constexpr friend auto operator-(const StaticMatrix& V) -> StaticMatrix {
        StaticMatrix ans;
        for (const int r : rep(row)) {
            for (const int c : rep(column)) {
                ans[r][c] = -V[r][c];
            }
        }
        return ans;
    }
    /**
     * @brief V1+V2
     *
     * @param V1
     * @param V2
     * @return StaticMatrix V1+V2
     */
    constexpr friend auto operator+(const StaticMatrix& V1, const StaticMatrix& V2) -> StaticMatrix {
        StaticMatrix ans;
        for (int i : rep(row)) {
            for (int j : rep(column)) {
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
     * @return StaticMatrix V1-V2
     */
    constexpr friend auto operator-(const StaticMatrix& V1, const StaticMatrix& V2) -> StaticMatrix {
        StaticMatrix ans;
        for (int i : rep(row)) {
            for (int j : rep(column)) {
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
     * @return StaticMatrix V1*V2
     */
    template <int c> constexpr friend auto operator*(const StaticMatrix<T, row, c>& V1, const StaticMatrix<T, c, column>& V2) -> StaticMatrix {
        StaticMatrix<T, row, column> ans;
        for (int i : rep(row)) {
            for (int j : rep(column)) {
                for (int k : rep(c)) {
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
     * @return StaticMatrix cV
     */
    constexpr friend auto operator*(const StaticMatrix& V, const T& c) -> StaticMatrix {
        StaticMatrix ans;
        for (int i : rep(row)) {
            for (int j : rep(column)) {
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
     * @return StaticMatrix V/c
     */
    constexpr friend auto operator/(const StaticMatrix& V, const T& c) -> StaticMatrix {
        assert(c != 0);
        StaticMatrix ans;
        for (int i : rep(row)) {
            for (int j : rep(column)) {
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
     * @return StaticMatrix& V1
     */
    constexpr friend auto operator+=(StaticMatrix& V1, const StaticMatrix& V2) -> StaticMatrix& {
        return V1 = V1 + V2;
    }
    /**
     * @brief V1 <- V1-V2
     *
     * @param V1
     * @param V2
     * @return StaticMatrix& V1
     */
    constexpr friend auto operator-=(StaticMatrix& V1, const StaticMatrix& V2) -> StaticMatrix& {
        return V1 = V1 - V2;
    }
    /**
     * @brief V1 <- V1*V2
     *
     * @param V1
     * @param V2
     * @return StaticMatrix& V1
     */
    constexpr friend auto operator*=(StaticMatrix& V1, const StaticMatrix& V2) -> StaticMatrix& {
        return V1 = V1 * V2;
    }
    /**
     * @brief V <- cV
     *
     * @param V
     * @param c スカラー
     * @return StaticMatrix& V
     */
    constexpr friend auto operator*=(StaticMatrix& V, const T& c) -> StaticMatrix& {
        return V = V * c;
    }
    /**
     * @brief V <- V/c
     *
     * @param V
     * @param c スカラー
     * @return StaticMatrix& V
     */
    constexpr friend auto operator/=(StaticMatrix& V, const T& c) -> StaticMatrix& {
        return V = V / c;
    }
    /**
     * @brief V^n
     *
     * @param n 指数
     * @return StaticMatrix V^n
     */
    constexpr auto pow(i64 n) const -> StaticMatrix {
        return powerMonoid(*this, n, I());
    }
    /**
     * @brief 単位行列
     *
     * @return StaticMatrix 単位行列
     */
    constexpr static auto I() -> StaticMatrix {
        static_assert(row == column, "StaticMatrix::I() should be rectangular!");
        StaticMatrix ans;
        for (const int i : rep(row)) {
            ans[i][i] = 1;
        }
        return ans;
    }
#ifdef HOGEPACHI
    friend auto operator<<(Ostream& os, const StaticMatrix& m) -> Ostream& {
        os << "[\n";
        for (const int i : rep(row)) {
            os << "[";
            for (const int j : rep(column)) {
                os << m[i][j] << ",";
            }
            os << "]\n";
        }
        return (os << "]");
    }
#endif
private:
    Arr<Arr<T, column>, row> m_vss;
};
