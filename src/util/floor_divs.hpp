#pragma once
#include "common.hpp"

class FloorDivs
{
public:
    FloorDivs(i64 X) : m_numerator{X}
    {
        assert(X >= 1);
        for (i64 y = 1; y * y <= X; y++) { m_divs.push_back(y); }
        const i64 Y = m_divs.back();
        for (i64 x = X / (Y + 1); x >= 1; x--) {
            const i64 y = X / x;
            if (m_divs.back() < y) { m_divs.push_back(y); }
        }
    };
    const Vec<i64>& divs() const { return m_divs; }
    i64 at(int i) const
    {
        assert(0 <= i and i < (int)m_divs.size());
        return m_divs[i];
    }
    int pos(i64 y) const
    {
        i64 id = 0;
        if (y * y <= m_numerator) {
            id = y - 1;
        } else {
            id = (i64)m_divs.size() - (m_numerator / y);
        }
        assert(m_divs[id] == y);
        return id;
    }
    int divNum() const { return m_divs.size(); }

private:
    i64 m_numerator;
    Vec<i64> m_divs;
};
