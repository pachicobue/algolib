#pragma once
#include "../common.hpp"
class Doubling
{
public:
    Doubling(const Vec<int>& f, i64 K)
    {
        const int N = f.size();
        const int lg = bitWidth(K);
        m_nextss.assign(lg, Vec<int>(N, -1));
        m_nextss[0] = f;
        for (int d : rep(lg - 1)) {
            for (int i : rep(N)) {
                if (m_nextss[d][i] == -1) { continue; }
                m_nextss[d + 1][i] = m_nextss[d][m_nextss[d][i]];
            }
        }
    }

    int kthNext(int x, i64 k) const
    {
        const int N = m_nextss[0].size();
        const int lg = m_nextss.size();
        assert(k < (1_i64 << lg));
        for (int d : rep(lg)) {
            if (0 <= x and x < N) {
                if (isBitOn(k, d)) { x = m_nextss[d][x]; }
            }
        }
        return x;
    }

    template<typename F>
    i64 distance(int x, F pred) const
    {
        if (pred(x)) { return 0; }
        const int lg = m_nextss.size();
        i64 ans = 0;
        for (int d : per(lg)) {
            const int np = m_nextss[d][x];
            if (not pred(np)) {
                x = np;
                ans += (1_i64 << d);
            }
        }
        if (pred(m_nextss[0][x])) {
            return ans + 1;
        } else {
            return -1;
        }
    }

private:
    Vec<Vec<int>> m_nextss;
};
