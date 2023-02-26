#pragma once
#include "../common.hpp"
template<typename T, int row, int column>
class StaticMatrix
{
    template<typename V>
    using IList = std::initializer_list<V>;

public:
    StaticMatrix()
    {
        for (auto& vs : m_vss) { fillAll(vs, T{}); }
    }
    StaticMatrix(const IList<IList<T>>& vss)
    {
        assert(row == vss.size());
        assert(column == vss.begin()->size());
        int i = 0;
        for (auto it = vss.begin(); it != vss.end(); it++) {
            std::copy(it->begin(), it->end(), m_vss[i++].begin());
        }
    }
    StaticMatrix(const StaticMatrix& m) : m_vss{m.m_vss} {}
    StaticMatrix& operator=(const StaticMatrix& m)
    {
        for (const int i : rep(row)) {
            for (const int j : rep(column)) { m_vss[i][j] = m[i][j]; }
        }
        return *this;
    }
    const Arr<T, column>& operator[](const int r) const { return m_vss[r]; }
    Arr<T, column>& operator[](const int r) { return m_vss[r]; }
    friend StaticMatrix operator-(const StaticMatrix& m)
    {
        StaticMatrix ans;
        for (const int r : rep(row)) {
            for (const int c : rep(column)) { ans[r][c] = -m[r][c]; }
        }
        return ans;
    }
    friend StaticMatrix operator+(const StaticMatrix& m1, const StaticMatrix& m2)
    {
        StaticMatrix ans;
        for (const int r : rep(row)) {
            for (const int c : rep(column)) { ans[r][c] = m1[r][c] + m2[r][c]; }
        }
        return ans;
    }
    friend StaticMatrix operator-(const StaticMatrix& m1, const StaticMatrix& m2)
    {
        StaticMatrix ans;
        for (const int r : rep(row)) {
            for (const int c : rep(column)) { ans[r][c] = m1[r][c] - m2[r][c]; }
        }
        return ans;
    }
    template<int c>
    friend StaticMatrix operator*(const StaticMatrix<T, row, c>& m1,
                                  const StaticMatrix<T, c, column>& m2)
    {
        StaticMatrix<T, row, column> ans;
        for (const int i : rep(row)) {
            for (const int j : rep(column)) {
                for (const int k : rep(c)) { ans[i][j] += m1[i][k] * m2[k][j]; }
            }
        }
        return ans;
    }
    friend StaticMatrix operator*(const StaticMatrix& m, const T& t)
    {
        StaticMatrix ans;
        for (const int r : rep(row)) {
            for (const int c : rep(column)) { ans[r][c] = m[r][c] * t; }
        }
        return ans;
    }
    friend StaticMatrix operator/(const StaticMatrix& m, const T& t)
    {
        StaticMatrix ans;
        for (const int r : rep(row)) {
            for (const int c : rep(column)) { ans[r][c] = m[r][c] / t; }
        }
        return ans;
    }
    friend StaticMatrix operator*(const T& t, const StaticMatrix& m) { return m * t; }
    friend StaticMatrix& operator+=(StaticMatrix& m1, const StaticMatrix& m2)
    {
        return m1 = m1 + m2;
    }
    friend StaticMatrix& operator-=(StaticMatrix& m1, const StaticMatrix& m2)
    {
        return m1 = m1 - m2;
    }
    friend StaticMatrix& operator*=(StaticMatrix& m1, const StaticMatrix& m2)
    {
        return m1 = m1 * m2;
    }
    friend StaticMatrix& operator*=(StaticMatrix& m, const T& t) { return m = m * t; }
    friend StaticMatrix& operator/=(StaticMatrix& m, const T& t) { return m = m / t; }
    friend std::ostream& operator<<(std::ostream& os, const StaticMatrix& m)
    {
        os << "[\n";
        for (const int i : rep(row)) {
            os << "[";
            for (const int j : rep(column)) { os << m[i][j] << ","; }
            os << "]\n";
        }
        return (os << "]");
    }
    template<typename Int>
    StaticMatrix pow(Int n) const
    {
        return powerMonoid(*this, n, I());
    }
    static StaticMatrix I()
    {
        static_assert(row == column, "StaticMatrix::I() should be rectangular!");
        StaticMatrix ans;
        for (const int i : rep(row)) { ans[i][i] = 1; }
        return ans;
    }

private:
    Arr<Arr<T, column>, row> m_vss;
};
