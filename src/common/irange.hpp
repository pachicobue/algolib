#pragma once
#include "type.hpp"
#include "macro.hpp"
class irange
{
private:
    struct itr
    {
        constexpr itr(i64 start = 0, i64 step = 1) : m_cnt{start}, m_step{step} {}
        constexpr bool operator!=(const itr& it) const { return m_cnt != it.m_cnt; }
        constexpr i64 operator*() { return m_cnt; }
        constexpr itr& operator++() { return m_cnt += m_step, *this; }
        i64 m_cnt, m_step;
    };
    i64 m_start, m_end, m_step;

public:
    static constexpr i64 cnt(i64 start, i64 end, i64 step)
    {
        if (step == 0) { return -1; }
        const i64 d = (step > 0 ? step : -step);
        const i64 l = (step > 0 ? start : end);
        const i64 r = (step > 0 ? end : start);
        i64 n = (r - l) / d + ((r - l) % d ? 1 : 0);
        if (l >= r) { n = 0; }
        return n;
    }
    constexpr irange(i64 start, i64 end, i64 step = 1)
        : m_start{start}, m_end{m_start + step * cnt(start, end, step)}, m_step{step}
    {
        assert(step != 0);
    }
    constexpr itr begin() const { return itr{m_start, m_step}; }
    constexpr itr end() const { return itr{m_end, m_step}; }
};
constexpr irange rep(i64 end) { return irange(0, end, 1); }
constexpr irange per(i64 rend) { return irange(rend - 1, -1, -1); }
#define LOOP(n) for (auto _ UNUSED : rep(n))
