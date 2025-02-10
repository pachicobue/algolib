#pragma once
#include <cassert>
#include "macro.hpp"
#include "type.hpp"
/**
 * @brief 等差数列
 */
class irange {
private:
    struct itr {
        constexpr itr(i64 start, i64 end, i64 step)
            : m_cnt{start}, m_step{step}, m_end{end} {
        }
        constexpr auto operator!=(const itr&) const -> bool {
            return (m_step > 0 ? m_cnt < m_end : m_end < m_cnt);
        } // endとの比較のみなので手抜き
        constexpr auto operator*() const -> i64 {
            return m_cnt;
        }
        constexpr auto operator++() -> itr& {
            return m_cnt += m_step, *this;
        }
        i64 m_cnt, m_step, m_end;
    };
    i64 m_start, m_end, m_step;
public:
    /**
     * @brief 等差数列
     *
     * @param start 初項
     * @param end
     * @param step 公差
     * @return [start,end) または (end,start] に含まれる等差数列 {start+step*i | i=0,1,...}
     */
    constexpr irange(i64 start, i64 end, i64 step = 1)
        : m_start{start}, m_end{end}, m_step{step} {
        assert(step != 0);
    }
    /**
     * @brief begin
     * @attention range-based forからのみ呼び出される想定
     *
     * @return itr begin
     */
    constexpr auto begin() const -> itr {
        return itr{m_start, m_end, m_step};
    }
    /**
     * @brief end
     * @attention range-based forからのみ呼び出される想定
     *
     * @return itr end
     */
    constexpr auto end() const -> itr {
        return itr{m_start, m_end, m_step};
    }
};
constexpr auto rep(i64 end) -> irange {
    return irange(0, end, 1);
}
constexpr auto per(i64 rend) -> irange {
    return irange(rend - 1, -1, -1);
}
#define LOOP(n) for (auto _ UNUSED : rep(n))
