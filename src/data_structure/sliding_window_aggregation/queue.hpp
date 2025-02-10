#pragma once
#include <cassert>
#include <concepts>
#include "../../internal.hpp"
/**
 * @brief Swag Queue
 *
 * @tparam T 値型
 * @tparam e 値の単位元
 * @tparam merge 値のマージ
 */
template <std::semiregular T, auto e, auto merge>
requires requires(const T& x, const T& y) {
    {
        e()
    } -> std::convertible_to<T>;
    {
        merge(x, y)
    } -> std::convertible_to<T>;
}
class SwagQueue {
public:
    /**
     * @brief コンストラクタ
     */
    SwagQueue()
        : m_fronts{}, m_backs{}, m_Fronts{e()}, m_Backs{e()} {
    }
    /**
     * @brief pushBack
     *
     * @param x 追加する値
     */
    auto pushBack(const T& x) -> void {
        m_backs.push_back(x);
        m_Backs.push_back(merge(m_Backs.back(), x));
    }
    /**
     * @brief popFront()
     */
    auto popFront() -> void {
        assert(not empty());
        if (m_fronts.empty()) {
            std::ranges::swap(m_fronts, m_backs), seqReverse(m_fronts), m_fronts.pop_back();
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
    auto foldAll() const -> T {
        return merge(m_Fronts.back(), m_Backs.back());
    }
    /**
     * @brief 空かどうか
     *
     * @return true 空
     * @return false 非空
     */
    auto empty() const -> bool {
        return m_backs.empty() and m_fronts.empty();
    }
private:
    auto calc() -> void {
        m_Fronts = {e()};
        for (int i : rep(m_fronts.size())) {
            m_Fronts.push_back(merge(m_fronts[i], m_Fronts.back()));
        }
        m_Backs = {e()};
        for (int i : rep(m_backs.size())) {
            m_Backs.push_back(merge(m_Backs.back(), m_backs[i]));
        }
    }
    Vec<T> m_fronts, m_backs;
    Vec<T> m_Fronts, m_Backs;
};
