#pragma once
#include "../common.hpp"
/**
 * @brief 傾きやクエリ座標が単調な場合のCHT
 * @attention 以下の単調性を要求する
 *   - 追加される直線の傾きは単調減少
 *   - クエリされる座標は単調増加
 * 
 * @tparam T 傾き/切片/クエリ座標の型
 */
template<typename T> class MonotoneCHT
{
    using L                    = Pair<T, T>;
    static constexpr auto Null = std::nullopt;
    static bool popAble(const L& l1, const L& l2, const L& l3)
    {
        const auto& [a1, b1] = l1;
        const auto& [a2, b2] = l2;
        const auto& [a3, b3] = l3;
        assert(a1 > a2 and a2 > a3);
        if constexpr (std::is_integral_v<T>) {
            return ceilDiv(b2 - b1, a1 - a2) >= ceilDiv(b3 - b2, a2 - a3);
        } else {
            return (a2 - a3) * (b2 - b1) >= (a1 - a2) * (b3 - b2);
        }
    }
    static bool comp(const L& l1, const L& l2, Opt<T> x)
    {
        const auto& [a1, b1] = l1;
        const auto& [a2, b2] = l2;
        assert(a1 > a2);
        if (x == Null) { return true; }
        if constexpr (std::is_integral_v<T>) {
            return x < ceilDiv(b2 - b1, a1 - a2);
        } else {
            return a1 * x.value() + b1 < a2 * x.value() + b2;
        }
    }
public:
    /**
     * @brief コンストラクタ
     */
    MonotoneCHT() : m_prev_x{Null} {}
    /**
     * @brief 直線追加
     * @attention 以前追加した直線の傾き以下である必要あり
     * 
     * @param l 直線
     */
    void addLine(const L& l)
    {
        if (m_lines.empty()) { return m_lines.push_back(l), void(); }
        if (m_lines.back().first == l.first) {
            if (m_lines.back().second <= l.second) { return; }
            m_lines.pop_back();
        }
        while ((int)m_lines.size() >= 2) {
            if (not popAble(m_lines[m_lines.size() - 2], m_lines[m_lines.size() - 1], l)) { break; }
            m_lines.pop_back();
        }
        m_lines.push_back(l);
    }
    /**
     * @brief 座標xで最小値を取る直線を返す
     * @attention 以前クエリした座標以上である必要あり
     * 
     * @param x クエリ座標
     * @return Opt<L> 最小値を取る直線 (存在しなければNull)
     */
    Opt<L> minLine(T x)
    {
        if (m_lines.empty()) { return Null; }
        assert(m_prev_x == Null or m_prev_x.value() <= x);
        m_prev_x = x;
        while (m_lines.size() >= 2) {
            if (comp(m_lines[0], m_lines[1], x)) { break; }
            m_lines.pop_front();
        }
        return m_lines.front();
    }
private:
    Opt<T> m_prev_x;
    Deq<L> m_lines;
};
