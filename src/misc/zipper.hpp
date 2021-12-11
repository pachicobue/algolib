#pragma once
#include "common.hpp"
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
        return lbInd(m_vs, v);
    }
    void add(T v)
    {
        m_vs.push_back(v);
        m_calced = false;
    }
    void add(const Vec<T>& vs)
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
    friend Ostream& operator<<(Ostream& os, const Zipper& zipper_)
    {
        auto zipper = zipper_;
        zipper.calc();
        return os << zipper.m_vs << "\n";
    }

private:
    void calc()
    {
        if (not m_calced) {
            sortAll(m_vs);
            m_vs.erase(std::unique(m_vs.begin(), m_vs.end()), m_vs.end());
            m_calced = true;
        }
    }
    Vec<T> m_vs;
    bool m_calced = true;
};
