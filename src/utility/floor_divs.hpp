#pragma once
#include <cassert>
#include <iterator>
#include "../internal.hpp"
/**
 * @brief 商列挙 (floor(X/i) の列挙)
 */
class FloorDivs {
public:
    /**
     * @brief コンストラクタ
     *
     * @param X 分子
     */
    FloorDivs(i64 X)
        : m_numerator{X} {
        assert(X >= 1);
        for (i64 y = 1; y * y <= X; y++) {
            m_quots.push_back(y);
        }
        const i64 Y = m_quots.back();
        for (i64 x = X / (Y + 1); x >= 1; x--) {
            const i64 y = X / x;
            if (m_quots.back() < y) {
                m_quots.push_back(y);
            }
        }
    };
    /**
     * @brief 商の列
     *
     * @return const Vec<i64>& 商の列
     */
    auto divs() const -> const Vec<i64>& {
        return m_quots;
    }
    /**
     * @brief i番目に小さな商
     *
     * @param i
     * @return i64 i番目に小さな商
     */
    auto at(int i) const -> i64 {
        assert(0 <= i and i < std::ssize(m_quots));
        return m_quots[i];
    }
    /**
     * @brief yが何番目に小さい商か
     *
     * @param y 商
     * @return int 何番目か
     */
    auto pos(i64 y) const -> int {
        i64 id = 0;
        if (y * y <= m_numerator) {
            id = y - 1;
        } else {
            id = (i64)m_quots.size() - (m_numerator / y);
        }
        assert(m_quots[id] == y);
        return id;
    }
    /**
     * @brief 商の種類数
     *
     * @return int 種類数
     */
    auto quotNum() const -> int {
        return m_quots.size();
    }
private:
    i64 m_numerator;
    Vec<i64> m_quots;
};
