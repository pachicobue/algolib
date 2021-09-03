#pragma once
#include "../misc/common.hpp"
template<typename T>
class MonotonicCHT
{
    using L = Pair<T, T>;
    static constexpr L NIL = {0, INF<T>};
    static bool needLess(const L& l1, const L& l2, const L& l3)
    {
        const auto [a1, b1] = l1;
        const auto [a2, b2] = l2;
        const auto [a3, b3] = l3;
        const T x12 = floorDiv(b2 - b1, a1 - a2),
                x23 = floorDiv(b3 - b2, a2 - a3);
        return x12 >= x23;
    }
    static bool comp(const L& l1, const L& l2, T x)
    {
        const auto [a1, b1] = l1;
        const auto [a2, b2] = l2;
        if (a1 == a2) {
            return b1 <= b2;
        } else if (a1 > a2) {
            return x <= floorDiv(b2 - b1, a1 - a2);
        } else {
            return floorDiv(b1 - b2, a2 - a1) < x;
        }
    }

public:
    MonotonicCHT() : m_prev_x{-INF<T>} {}
    void addLine(T a, T b)
    {
        const L l{a, b};
        if (m_lines.empty()) {
            m_lines.push_back(l);
            return;
        }
        auto& [ma, mb] = m_lines.back();
        assert(ma >= a);
        if (a == ma) {
            chmin(mb, b);
        } else {
            while (m_lines.size() >= 2) {
                const int n = m_lines.size();
                const auto& l0 = m_lines[n - 2];
                const auto& l1 = m_lines[n - 1];
                if (not needLess(l0, l1, l)) { break; }
                m_lines.pop_back();
            }
            m_lines.push_back(l);
        }
    }
    L minLine(const T x)
    {
        if (m_lines.empty()) { return NIL; }
        assert(m_prev_x <= x);
        m_prev_x = x;
        while (m_lines.size() >= 2) {
            const auto& l0 = m_lines[0];
            const auto& l1 = m_lines[1];
            if (comp(l0, l1, x)) { break; }
            m_lines.pop_front();
        }
        return m_lines.front();
    }

private:
    T m_prev_x;
    Deq<L> m_lines;
};
