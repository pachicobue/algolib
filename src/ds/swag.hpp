#pragma once
#include "../common.hpp"
template<typename SemiGroup>
class SlidingWindowAggregation
{
    using T = typename SemiGroup::T;

public:
    SlidingWindowAggregation() : m_merge{} {}
    void pushBack(const T& x)
    {
        m_backs.push_back(x);
        m_Backs.push_back(m_Backs.empty() ? x : m_merge(m_Backs.back(), x));
    }
    void pushFront(const T& x)
    {
        m_fronts.push_back(x);
        m_Fronts.push_back(m_Fronts.empty() ? x : m_merge(x, m_Fronts.back()));
    }
    void popBack()
    {
        if (m_Backs.empty()) {
            Vec<T> as = m_fronts;
            m_fronts.clear(), m_Fronts.clear();
            reverseAll(as);
            const int f = (int)as.size() / 2;
            for (int i : per(f)) {
                m_fronts.push_back(as[i]);
            }
            for (int i : irange(f, (int)as.size() - 1)) {
                m_backs.push_back(as[i]);
            }
            calc();
        } else {
            m_backs.pop_back(), m_Backs.pop_back();
        }
    }
    void popFront()
    {
        if (m_Fronts.empty()) {
            Vec<T> as = m_backs;
            m_backs.clear(), m_Backs.clear();
            const int f = ((int)as.size() + 1) / 2;
            for (int i : irange(f - 1, 0, -1)) {
                m_fronts.push_back(as[i]);
            }
            for (int i : irange(f, (int)as.size())) {
                m_backs.push_back(as[i]);
            }
            calc();
        } else {
            m_fronts.pop_back(), m_Fronts.pop_back();
        }
    }
    T foldAll() const
    {
        return m_fronts.empty()
                   ? m_Backs.back()
                   : (m_backs.empty()
                          ? m_Fronts.back()
                          : m_merge(m_Fronts.back(), m_Backs.back()));
    }
    friend Ostream& operator<<(Ostream& os, const SlidingWindowAggregation& sw)
    {
        Vec<T> as = sw.fs;
        reverseAll(as);
        as += sw.bs;
        os << "vs = [";
        for (const T& a : as) {
            os << a << ",";
        }
        return os << "]";
    }
    int size() const
    {
        return (int)m_fronts.size() + (int)m_backs.size();
    }
    bool empty() const
    {
        return m_fronts.empty() and m_backs.empty();
    }

private:
    void calc()
    {
        if (not m_fronts.empty()) {
            m_Fronts.push_back(m_fronts[0]);
            for (int i : irange(1, m_fronts.size())) {
                m_Fronts.push_back(m_merge(m_fronts[i], m_Fronts.back()));
            }
        }
        if (not m_backs.empty()) {
            m_Backs.push_back(m_backs[0]);
            for (int i : irange(1, m_backs.size())) {
                m_Backs.push_back(m_merge(m_Backs.back(), m_backs[i]));
            }
        }
    }
    Vec<T> m_fronts, m_backs;
    Vec<T> m_Fronts, m_Backs;
    SemiGroup m_merge;
};
