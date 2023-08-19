#pragma once
#include "../../common.hpp"
/**
 * @brief Swag Deque
 * 
 * @tparam Monoid 値のモノイド
 */
template<typename Monoid> class SwagDeque
{
    using T = typename Monoid::T;
public:
    /**
     * @brief コンストラクタ
     */
    SwagDeque() : m_fronts{}, m_backs{}, m_Fronts{Monoid::e()}, m_Backs{Monoid::e()} {}
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
     * @brief pushFront
     * 
     * @param x 追加する値
     */
    void pushFront(const T& x)
    {
        m_fronts.push_back(x);
        m_Fronts.push_back(m_merge(x, m_Fronts.back()));
    }
    /**
     * @brief popBack
     */
    void popBack()
    {
        assert(not empty());
        if (m_backs.empty()) {
            auto as = Vec<T>(m_fronts.begin() + 1, m_fronts.end());
            m_fronts.clear(), seqReverse(as);
            const int half = (int)as.size() / 2;
            for (int i : per(half)) { m_fronts.push_back(as[i]); }
            for (int i : irange(half, as.size())) { m_backs.push_back(as[i]); }
            calc();
        } else {
            m_backs.pop_back(), m_Backs.pop_back();
        }
    }
    /**
     * @brief popFront
     */
    void popFront()
    {
        assert(not empty());
        if (m_fronts.empty()) {
            auto as = Vec<T>(m_backs.begin() + 1, m_backs.end());
            m_backs.clear();
            const int half = (int)as.size() / 2;
            for (int i : per(half)) { m_fronts.push_back(as[i]); }
            for (int i : irange(half, as.size())) { m_backs.push_back(as[i]); }
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
