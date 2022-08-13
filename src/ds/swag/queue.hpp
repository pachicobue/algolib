#pragma once
#include "../../common.hpp"
template<typename SemiGroup>
class SwagQueue
{
    using T = typename SemiGroup::T;

public:
    SwagQueue() {}
    void pushBack(const T& x)
    {
        m_backs.push_back(x);
        m_Backs.push_back(m_Backs.empty() ? x : m_merge(m_Backs.back(), x));
    }
    void popFront()
    {
        if (m_Fronts.empty()) {
            std::swap(m_fronts, m_backs), reverseAll(m_fronts), m_fronts.pop_back();
            m_backs.clear(), m_Backs.clear();
            calc();
        } else {
            m_fronts.pop_back(), m_Fronts.pop_back();
        }
    }
    T foldAll() const
    {
        return m_fronts.empty()
                   ? m_Backs.back()
                   : (m_backs.empty() ? m_Fronts.back() : m_merge(m_Fronts.back(), m_Backs.back()));
    }
    bool empty() const { return m_backs.empty() and m_fronts.empty(); }

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
    static inline SemiGroup m_merge;
};
