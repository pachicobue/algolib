#pragma once
#include "../misc/common.hpp"
template<int block_size>
class Mo
{
public:
    Mo(const Vec<int>& xs, const Vec<int>& ys)
        : m_xs{xs}, m_ys{ys}, m_is(m_xs.size())
    {
        iotaAll(m_is);
        sortAll(m_is, [&](int i, int j) {
            const int ib = m_xs[i] / block_size;
            const int jb = m_xs[j] / block_size;
            return ib != jb ? ib < jb : m_ys[i] < m_ys[j];
        });
    }
    template<typename R, typename L, typename D, typename U>
    int next(R right, L left, D down, U up)
    {
        assert(m_ii < (int)m_is.size());
        const int i = m_is[m_ii++];
        const int nx = m_xs[i], ny = m_ys[i];
        for (; m_x < nx; m_x++) {
            right(m_x, m_y);
        }
        for (; m_x > nx; m_x--) {
            left(m_x, m_y);
        }
        for (; m_y < ny; m_y++) {
            down(m_x, m_y);
        }
        for (; m_y > ny; m_y--) {
            up(m_x, m_y);
        }
        return i;
    }

private:
    int m_ii = 0;
    int m_x = 0, m_y = 0;
    Vec<int> m_xs, m_ys;
    Vec<int> m_is;
};
