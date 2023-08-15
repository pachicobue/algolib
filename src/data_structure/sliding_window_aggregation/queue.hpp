#pragma once
#include "../../common.hpp"
/**
 * @brief Swag Queue
 * 
 * @tparam Monoid 値のモノイド
 */
template<typename Monoid> class SwagQueue
{
    using T = typename Monoid::T;
public:
    /**
     * @brief コンストラクタ
     */
    SwagQueue() : m_fronts{}, m_backs{}, m_Fronts{Monoid::e()}, m_Backs{Monoid::e()} {}
    /**
     * @brief pushBack
     * 
     * @param x 追加する値
     */
    void pushBack(const T& x)
    {
        m_backs.push_back(x);
        m_Backs.push_back(m_merge(m_Backs.back(), x));
    }
    /**
     * @brief popFront()
     */
    void popFront()
    {
        assert(not empty());
        if (m_fronts.empty()) {
            std::swap(m_fronts, m_backs), reverseAll(m_fronts), m_fronts.pop_back();
            calc();
        } else {
            m_fronts.pop_back(), m_Fronts.pop_back();
        }
    }
    /**
     * @brief 数列全体の総積
     * 
     * @return T 総積
     */
    T foldAll() const { return m_merge(m_Fronts.back(), m_Backs.back()); }
    /**
     * @brief 空かどうか
     * 
     * @return true 空
     * @return false 非空
     */
    bool empty() const { return m_backs.empty() and m_fronts.empty(); }
private:
    void calc()
    {
        m_Fronts = {Monoid::e()};
        for (int i : rep(m_fronts.size())) { m_Fronts.push_back(m_merge(m_fronts[i], m_Fronts.back())); }
        m_Backs = {Monoid::e()};
        for (int i : rep(m_backs.size())) { m_Backs.push_back(m_merge(m_Backs.back(), m_backs[i])); }
    }
    Vec<T> m_fronts, m_backs;
    Vec<T> m_Fronts, m_Backs;
    static inline Monoid m_merge;
};
