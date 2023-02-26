#pragma once
#include "../common.hpp"
class StopWatch
{
    using SysClock = std::chrono::system_clock;
    using Tp = SysClock::time_point;

public:
    StopWatch() : m_start{SysClock::now()}, m_rap{m_start} {}
    template<typename D = std::chrono::milliseconds>
    typename D::rep rap()
    {
        const auto now = SysClock::now();
        const auto ans = std::chrono::duration_cast<D>(now - m_rap).count();
        m_rap = now;
        return ans;
    }
    template<typename D = std::chrono::milliseconds>
    typename D::rep get()
    {
        const auto now = SysClock::now();
        return std::chrono::duration_cast<D>(now - m_rap).count();
    }
    template<typename D = std::chrono::milliseconds>
    typename D::rep total()
    {
        const auto now = SysClock::now();
        return std::chrono::duration_cast<D>(now - m_start).count();
    }

private:
    Tp m_start, m_rap;
};
