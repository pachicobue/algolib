#pragma once
#include "type_alias.hpp"
#include "macro.hpp"
class irange
{
private:
    struct itr
    {
        itr(i64 start = 0, i64 step = 1) : m_cnt{start}, m_step{step} {}
        bool operator!=(const itr& it) const
        {
            return m_cnt != it.m_cnt;
        }
        i64 operator*()
        {
            return m_cnt;
        }
        itr& operator++()
        {
            return m_cnt += m_step, *this;
        }
        i64 m_cnt, m_step;
    };
    i64 m_start, m_end, m_step;

public:
    irange(i64 start, i64 end, i64 step = 1)
    {
        assert(step != 0);
        const i64 d = std::abs(step);
        const i64 l = (step > 0 ? start : end);
        const i64 r = (step > 0 ? end : start);
        i64 n = (r - l) / d + ((r - l) % d ? 1 : 0);
        if (l >= r) { n = 0; }
        m_start = start, m_end = start + step * n, m_step = step;
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
irange rep(i64 end)
{
    return irange(0, end, 1);
}
irange per(i64 rend)
{
    return irange(rend - 1, -1, -1);
}
#define LOOP(n) for (auto _ UNUSED : rep(n))
