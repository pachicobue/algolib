#pragma once
#include "../misc/common.hpp"
template<int column>
class BitMat
{
public:
    BitMat(int row) : m_row{row},
                      m_vss(m_row) {}
    const BSet<column>& operator[](const int r) const
    {
        assert(0 <= r and r < m_row);
        return m_vss[r];
    }
    BSet<column>& operator[](const int r)
    {
        assert(0 <= r and r < m_row);
        return m_vss[r];
    }
    friend BitMat operator^(const BitMat& m1, const BitMat& m2)
    {
        assert(m1.m_row == m2.m_row);
        BitMat ans(m1.m_row);
        for (int i : rep(m1.row)) { ans[i] = m1[i] ^ m2[i]; }
        return ans;
    }
    template<int col2>
    friend BitMat operator*(const BitMat& m1, const BitMat<col2>& m2)
    {
        assert(column == m2.m_row);
        BitMat<col2> ans(m1.m_row);
        for (int i : rep(m1.m_row)) {
            for (int j : rep(column)) {
                if (not m1[i][j]) { continue; }
                ans[i] ^= m2[j];
            }
        }
        return ans;
    }
    template<typename I>
    BitMat pow(I n) { return power(*this, n, I(m_row)); }
    friend BitMat& operator^=(BitMat& m1, const BitMat& m2)
    {
        assert(m1.m_row == m2.m_row);
        for (int i : rep(m1.m_row)) { m1[i] ^= m2[i]; }
        return m1;
    }
    friend BitMat& operator*=(BitMat& m1, const BitMat& m2) { return m1 = m1 * m2; }
    friend Ostream& operator<<(Ostream& os, const BitMat& m)
    {
        os << "[\n";
        for (int i : rep(m.m_row)) { os << "[" << m[i] << "]\n"; }
        return (os << "]");
    }
    static BitMat I(const int n)
    {
        BitMat ans(n);
        for (int i : rep(n)) { ans[i].set(i); }
        return ans;
    }

    int row() const { return m_row; }

private:
    int m_row;
    Vec<BSet<column>> m_vss;
};
