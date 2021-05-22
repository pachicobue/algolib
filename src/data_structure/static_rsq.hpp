#pragma once
#include "../misc/common.hpp"
template<typename T>
class StaticRSQ
{
public:
    StaticRSQ(const Vec<T>& vs)
        : m_size(vs.size()),
          m_prefs(vs.size() + 1, T{}),
          m_suffs(vs.size() + 1, T{})
    {
        std::copy(vs.begin(), vs.end(), m_prefs.begin() + 1);
        for (int i : rep(m_size)) {
            m_prefs[i + 1] += m_prefs[i];
        }
        std::copy(vs.begin(), vs.end(), m_suffs.begin());
        for (int i : per(m_size)) {
            m_suffs[i] += m_suffs[i + 1];
        }
    }
    void unsafeSet(int i, const T& v)
    {
        assert(0 < i and i < m_size);
        m_prefs[i + 1] = m_prefs[i] + v, m_suffs[i] = m_suffs[i + 1] + v;
    }
    T prefixSum(int l, int r) const
    {
        assert(0 <= l and l <= r and r <= m_size);
        return m_prefs[r] - m_prefs[l];
    }
    T suffixSum(int l, int r) const
    {
        assert(0 <= l and l <= r and r <= m_size);
        return m_suffs[l] - m_suffs[r];
    }
private:
    int m_size;
    Vec<T> m_prefs, m_suffs;
};
