#pragma once
#include "../common.hpp"
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
