#pragma once
#include "../common.hpp"
template<typename T, int row, int column>
class ArrMat
{
public:
    ArrMat()
    {
        for (auto& vs : m_vss) { fillAll(vs, T{}); }
    }
    ArrMat(const IList<IList<T>>& vss)
    {
        assert(row == vss.size());
        assert(column == vss.begin()->size());
        int i = 0;
        for (auto it = vss.begin(); it != vss.end(); it++) {
            std::copy(it->begin(), it->end(), m_vss[i++].begin());
        }
    }
    ArrMat(const ArrMat& m) : m_vss{m.m_vss} {}
    ArrMat& operator=(const ArrMat& m)
    {
        for (const int i : rep(row)) {
            for (const int j : rep(column)) { m_vss[i][j] = m[i][j]; }
        }
        return *this;
    }
    const Arr<T, column>& operator[](const int r) const { return m_vss[r]; }
    Arr<T, column>& operator[](const int r) { return m_vss[r]; }
    friend ArrMat operator-(const ArrMat& m)
    {
        ArrMat ans;
        for (const int r : rep(row)) {
            for (const int c : rep(column)) { ans[r][c] = -m[r][c]; }
        }
        return ans;
    }
    friend ArrMat operator+(const ArrMat& m1, const ArrMat& m2)
    {
        ArrMat ans;
        for (const int r : rep(row)) {
            for (const int c : rep(column)) { ans[r][c] = m1[r][c] + m2[r][c]; }
        }
        return ans;
    }
    friend ArrMat operator-(const ArrMat& m1, const ArrMat& m2)
    {
        ArrMat ans;
        for (const int r : rep(row)) {
            for (const int c : rep(column)) { ans[r][c] = m1[r][c] - m2[r][c]; }
        }
        return ans;
    }
    template<int c>
    friend ArrMat operator*(const ArrMat<T, row, c>& m1, const ArrMat<T, c, column>& m2)
    {
        ArrMat<T, row, column> ans;
        for (const int i : rep(row)) {
            for (const int j : rep(column)) {
                for (const int k : rep(c)) { ans[i][j] += m1[i][k] * m2[k][j]; }
            }
        }
        return ans;
    }
    friend ArrMat operator*(const ArrMat& m, const T& t)
    {
        ArrMat ans;
        for (const int r : rep(row)) {
            for (const int c : rep(column)) { ans[r][c] = m[r][c] * t; }
        }
        return ans;
    }
    friend ArrMat operator/(const ArrMat& m, const T& t)
    {
        ArrMat ans;
        for (const int r : rep(row)) {
            for (const int c : rep(column)) { ans[r][c] = m[r][c] / t; }
        }
        return ans;
    }
    friend ArrMat operator*(const T& t, const ArrMat& m) { return m * t; }
    friend ArrMat& operator+=(ArrMat& m1, const ArrMat& m2) { return m1 = m1 + m2; }
    friend ArrMat& operator-=(ArrMat& m1, const ArrMat& m2) { return m1 = m1 - m2; }
    friend ArrMat& operator*=(ArrMat& m1, const ArrMat& m2) { return m1 = m1 * m2; }
    friend ArrMat& operator*=(ArrMat& m, const T& t) { return m = m * t; }
    friend ArrMat& operator/=(ArrMat& m, const T& t) { return m = m / t; }
    friend std::ostream& operator<<(std::ostream& os, const ArrMat& m)
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
    ArrMat pow(Int n) const
    {
        return powerMonoid(*this, n, I());
    }
    static ArrMat I()
    {
        static_assert(row == column, "I() should be rectangular!");
        ArrMat ans;
        for (const int i : rep(row)) { ans[i][i] = 1; }
        return ans;
    }

private:
    Arr<Arr<T, column>, row> m_vss;
};
