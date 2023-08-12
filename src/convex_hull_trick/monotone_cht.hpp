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
    static bool comp(const L& l1, const L& l2, Opt<T> x)
    {
        const auto& [a1, b1] = l1;
        const auto& [a2, b2] = l2;
        if (a1 == a2) { return b1 < b2; }
        if (x == Null) { return a1 < a2; }
        if constexpr (std::is_integral_v<T>) {
            if (a1 > a2) {
                return x.value() <= floorDiv(b2 - b1, a1 - a2);
            } else {
                return floorDiv(b1 - b2, a2 - a1) < x.value();
            }
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
     * @attention 以前追加した直線の傾き以上である必要あり
     * 
     * @param l 直線
     */
    void addLine(const L& l)
    {
        assert(m_lines.empty() or m_lines.back().first >= l.first);
        while (not m_lines.empty()) {
            if (comp(m_lines.back(), l, m_prev_x)) { break; }
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
