#pragma once
#include "../common.hpp"
class Doubling
{
public:
    Doubling(const Vec<int>& nexts, i64 K)
    {
        const int N = nexts.size();
        const int lg = bitWidth(K);
        m_nextss.assign(lg, Vec<int>(N, -1));
        m_nextss[0] = nexts;
        for (int d : rep(lg - 1)) {
            for (int i : rep(N)) {
                if (m_nextss[d][i] == -1) { continue; }
                m_nextss[d + 1][i] = m_nextss[d][m_nextss[d][i]];
            }
        }
    }
    Doubling(const Vec<int>& nexts) : Doubling(nexts, (i64)nexts.size()) {}

    int kthNext(int p, i64 k) const
    {
        const int N = m_nextss[0].size();
        const int lg = m_nextss.size();
        assert(k < (1_i64 << lg));
        for (int d : rep(lg)) {
            if (0 <= p and p < N) {
                if (isBitOn(k, d)) { p = m_nextss[d][p]; }
            }
        }
        return p;
    }

    template<typename F>
    i64 distance(int p, F f) const
    {
        if (f(p)) { return 0; }
        const int lg = m_nextss.size();
        i64 ans = 0;
        for (int d : per(lg)) {
            const int np = m_nextss[d][p];
            if (not f(np)) {
                p = np;
                ans += (1_i64 << d);
            }
        }
        if (f(m_nextss[0][p])) {
            return ans + 1;
        } else {
            return -1;
        }
    }

private:
    Vec<Vec<int>> m_nextss;
};
