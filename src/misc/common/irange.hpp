#pragma once
#include "type_alias.hpp"
class irange
{
private:
    struct itr
    {
        itr(int start = 0, int step = 1) : m_cnt{start}, m_step{step} {}
        bool operator!=(const itr& it) const
        {
            return m_cnt != it.m_cnt;
        }
        int operator*()
        {
            return m_cnt;
        }
        itr& operator++()
        {
            m_cnt += m_step;
            return *this;
        }
        int m_cnt, m_step;
    };
    int m_start, m_end, m_step;

public:
    irange(int start, int end, int step = 1)
    {
        assert(step != 0);
        const int d = std::abs(step);
        const int l = (step > 0 ? start : end);
        const int r = (step > 0 ? end : start);
        int n = (r - l) / d + ((r - l) % d ? 1 : 0);
        if (l >= r) { n = 0; }
        m_start = start;
        m_end = start + step * n;
        m_step = step;
    }
    itr begin() const
    {
        return itr{m_start, m_step};
    }
    itr end() const
    {
        return itr{m_end, m_step};
    }
};
irange rep(int end)
{
    return irange(0, end, 1);
}
irange per(int rend)
{
    return irange(rend - 1, -1, -1);
}
