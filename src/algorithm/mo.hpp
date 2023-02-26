#pragma once
#include "../common.hpp"
class Mo
{
public:
    Mo(const Vec<int>& xs, const Vec<int>& ys) : m_xs{xs}, m_ys{ys}, m_is{iotaVec(m_xs.size())}
    {
        sortAll(m_is, [&](int i, int j) {
            return hilbert(m_xs[i], m_ys[i]) < hilbert(m_xs[j], m_ys[j]);
        });
    }
    template<typename R, typename L, typename D, typename U, typename S>
    void solve(R right, L left, D down, U up, S sol)
    {
        int x = 0, y = 0;
        for (int ii : rep(m_xs.size())) {
            const int i = m_is[ii];
            const int nx = m_xs[i], ny = m_ys[i];
            for (; x < nx; x++) { right(x, y); }
            for (; x > nx; x--) { left(x, y); }
            for (; y < ny; y++) { down(x, y); }
            for (; y > ny; y--) { up(x, y); }
            sol(i);
        }
    }

private:
    static constexpr i64 hilbert(int x, int y)
    {
        i64 ans = 0;
        constexpr i64 OFFs[] = {0, 3, 1, 2};
        for (int i : per(30)) {
            const int S = (isBitOn(x, i) << 1) | (isBitOn(y, i));
            ans += OFFs[S] * (1_i64 << (2 * i));
            if (S <= 1) { std::swap(x, y); }
            if (S == 1) { x = ~x, y = ~y; }
        }
        return ans;
    }
    Vec<int> m_xs, m_ys;
    Vec<int> m_is;
};
