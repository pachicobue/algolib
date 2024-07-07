#pragma once
#include <iomanip>
#include <iostream>
#include <utility>
#include "../internal.hpp"
/**
 * @brief 出力補助クラス
 * @note << をサポートしている型T と Vec<T> の出力をサポート
 *       Vec<T> の出力形式は空白区切り
 */
class Printer {
public:
    /**
     * @brief コンストラクタ
     *
     * @param os 出力ストリーム
     */
    Printer(Ostream& os = std::cout) : m_os{os} { m_os << std::fixed << std::setprecision(15); }
    /**
     * @brief 空白区切りで出力 (改行無し)
     *
     * @param args 出力する値たち
     * @return int 0 (return out(...); でmain関数を抜けるのに便利)
     */
    int operator()(const auto&... args) { return dump(args...), 0; }
    /**
     * @brief 空白区切りで出力 (\n 付き)
     *
     * @param args 出力する値たち
     * @return int 0 (return out.ln(...); でmain関数を抜けるのに便利)
     */
    int ln(const auto&... args) { return dump(args...), m_os << '\n', 0; }
    /**
     * @brief 空白区切りで出力 (endl 付き)
     *
     * @param args 出力する値たち
     * @return int 0 (return out.el(...); でmain関数を抜けるのに便利)
     */
    int el(const auto&... args) { return dump(args...), m_os << std::endl, 0; }
private:
    void dump(const auto& v) { m_os << v; }
    int dump(const auto& v, const auto&... args) { return dump(v), m_os << ' ', dump(args...), 0; }
    template <typename... Args> void dump(const Vec<Args...>& vs) {
        for (Str delim = ""; const auto& v : vs) { m_os << std::exchange(delim, " "), dump(v); }
    }

    Ostream& m_os;
};
inline Printer out;
