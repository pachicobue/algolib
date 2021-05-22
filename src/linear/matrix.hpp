#pragma once
#include "../misc/common.hpp"
template<typename T>
class Mat
{
public:
    Mat(const int row, const int column) : m_row{row},
                                           m_column{column},
                                           m_vss(row, Vec<T>(column, 0)) {}
    const Vec<T>& operator[](const int r) const
    {
        assert(0 <= r and r < m_row);
        return m_vss[r];
    }
    Vec<T>& operator[](const int r)
    {
        assert(0 <= r and r < m_row);
        return m_vss[r];
    }
    friend Mat operator-(const Mat& m)
    {
        Mat ans(m.m_row, m.m_column);
        for (int i : rep(m.m_row)) {
            for (int j : rep(m.m_column)) {
                ans[i][j] = -m[i][j];
            }
        }
        return ans;
    }
    friend Mat operator+(const Mat& m1, const Mat& m2) { return Mat{m1} += m2; }
    friend Mat operator-(const Mat& m1, const Mat& m2) { return Mat{m1} -= m2; }
    friend Mat operator*(const Mat& m1, const Mat& m2) { return Mat{m1} *= m2; }
    friend Mat operator*(const Mat& m, const T& t) { return Mat{m} *= t; }
    friend Mat operator/(const Mat& m, const T& t) { return Mat{m} /= t; }
    friend Mat operator*(const T& t, const Mat& m) { return m * t; }
    template<typename I>
    Mat pow(const Mat& m, I n) const
    {
        return power(m, n, I());
    }
    friend Mat& operator+=(Mat& m1, const Mat& m2)
    {
        assert(m1.m_row == m2.m_row);
        assert(m1.m_column == m2.m_column);
        Mat ans(m1.m_row, m1.m_column);
        for (int i : rep(m1.m_row)) {
            for (int j : rep(m1.m_column)) {
                m1[i][j] += m2[i][j];
            }
        }
        return m1;
    }
    friend Mat& operator-=(Mat& m1, const Mat& m2)
    {
        assert(m1.m_row == m2.m_row);
        assert(m1.m_column == m2.m_column);
        Mat ans(m1.m_row, m1.m_column);
        for (int i : rep(m1.m_row)) {
            for (int j : rep(m1.m_column)) {
                m1[i][j] -= m2[i][j];
            }
        }
        return m1;
    }
    friend Mat& operator*=(Mat& m1, const Mat& m2)
    {
        assert(m1.m_row == m1.m_column);
        assert(m2.m_row == m2.m_column);
        Mat ans(m1.m_row, m2.m_column);
        for (int i : rep(m1.m_row)) {
            for (int j : rep(m2.m_column)) {
                for (int k : rep(m1.m_column)) {
                    ans[i][j] = m1[i][k] * m2[k][j];
                }
            }
        }
        return m1 = ans;
    }
    friend Mat& operator*=(Mat& m, const T& t)
    {
        Mat ans(m.m_row, m.m_column);
        for (int i : rep(m.m_row)) {
            for (int j : rep(m.m_column)) {
                m[i][j] *= t;
            }
        }
        return m;
    }
    friend Mat& operator/=(Mat& m, const T& t)
    {
        Mat ans(m.m_row, m.m_column);
        for (int i : rep(m.m_row)) {
            for (int j : rep(m.m_column)) {
                m[i][j] /= t;
            }
        }
        return m;
    }
    friend Ostream& operator<<(Ostream& os, const Mat& m)
    {
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
    static Mat I(int N)
    {
        Mat ans(N, N);
        for (int i : rep(N)) { ans[i][i] = 1; }
        return ans;
    }
    int row() const { return m_row; }
    int column() const { return m_column; }

private:
    int m_row, m_column;
    Vec<Vec<T>> m_vss;
};
