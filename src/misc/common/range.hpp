#pragma once
#include "type_alias.hpp"
#pragma region Range
class range
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
    range(int start, int end, int step = 1)
        : m_start{start}, m_end{end}, m_step{step}
    {
        assert(m_step == 1 or m_step == -1);
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
range rep(int end)
{
    return range(0, end, 1);
}
range per(int rend)
{
    return range(rend - 1, -1, -1);
}

class ndRep
{
private:
    struct itr
    {
        itr(const Vec<int>& ns) : m_ns{ns}, m_cs(ns.size(), 0), m_end{false} {}
        bool operator!=(const itr&) const
        {
            return not m_end;
        }
        const Vec<int>& operator*()
        {
            return m_cs;
        }
        itr& operator++()
        {
            for (const int i : per(m_ns.size())) {
                m_cs[i]++;
                if (m_cs[i] < m_ns[i]) {
                    break;
                } else {
                    if (i == 0) { m_end = true; }
                    m_cs[i] = 0;
                }
            }
            return *this;
        }
        Vec<int> m_ns, m_cs;
        bool m_end;
    };
    Vec<int> m_ns;

public:
    ndRep(const Vec<int>& ns) : m_ns{ns} {}
    itr begin() const
    {
        return itr{m_ns};
    }
    itr end() const
    {
        return itr{m_ns};
    }
};
#pragma endregion
