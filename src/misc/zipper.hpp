#pragma once
#include "common.hpp"
#pragma region Zipper
template<typename T>
class Zipper
{
public:
    Zipper() {}
    Zipper(const Vec<T>& vs) : m_vs(vs), m_calced(false) {}
    T unzip(int n)
    {
        assert(0 <= n and n < (int)m_vs.size());
        calc();
        return m_vs[n];
    }
    int zip(T v)
    {
        calc();
        return std::lower_bound(m_vs.begin(), m_vs.end(), v) - m_vs.begin();
    }
    void add(T v)
    {
        m_vs.push_back(v);
        m_calced = false;
    }
    void add(const std::vector<T>& vs)
    {
        for (const auto v : vs) {
            m_vs.push_back(v);
        }
        m_calced = false;
    }
    int size()
    {
        calc();
        return m_vs.size();
    }

private:
    void calc()
    {
        if (not m_calced) {
            uniqueAll(m_vs);
            m_calced = true;
        }
    }
    Vec<T> m_vs;
    bool m_calced = true;
};
#pragma endregion
