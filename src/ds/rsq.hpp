#pragma once
#include "../misc/common.hpp"
template<typename T>
class RSQ
{
public:
    RSQ(const Vec<T>& vs)
        : m_size(vs.size()),
          m_vs(vs),
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
    const T& operator[](int i) const
    {
        assert(0 <= i and i < m_size);
        return m_vs[i];
    }
    void unsafeSet(int i, const T& v)
    {
        assert(0 <= i and i < m_size);
        m_vs[i] = v;
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
    void recalc()
    {
        std::copy(m_vs.begin(), m_vs.end(), m_prefs.begin() + 1);
        for (int i : rep(m_size)) {
            m_prefs[i + 1] += m_prefs[i];
        }
        std::copy(m_vs.begin(), m_vs.end(), m_suffs.begin());
        for (int i : per(m_size)) {
            m_suffs[i] += m_suffs[i + 1];
        }
    }

private:
    int m_size;
    Vec<T> m_vs;
    Vec<T> m_prefs, m_suffs;
};
