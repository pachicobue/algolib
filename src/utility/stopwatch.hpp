#pragma once
#include <chrono>
#include "../internal.hpp"
/**
 * @brief 時間計測クラス
 */
class StopWatch {
    using SysClock = std::chrono::system_clock;
    using Tp = SysClock::time_point;
public:
    /**
     * @brief コンストラクタ
     */
    StopWatch() : m_start{SysClock::now()}, m_rap{m_start} {}
    /**
     * @brief Rapを実行
     *
     * @tparam D 精度
     * @return D::rep 前Rapからの経過時間
     */
    template <typename D = std::chrono::milliseconds> auto rap() {
        const auto now = SysClock::now();
        const auto ans = std::chrono::duration_cast<D>(now - m_rap).count();
        m_rap = now;
        return ans;
    }
    /**
     * @brief 前Rap からの経過時間
     *
     * @tparam D 精度
     * @return D::rep 経過時間
     */
    template <typename D = std::chrono::milliseconds> auto get() const {
        const auto now = SysClock::now();
        return std::chrono::duration_cast<D>(now - m_rap).count();
    }
    /**
     * @brief コンストラクトからのトータル経過時間
     *
     * @tparam D 精度
     * @return D::rep トータル経過時間
     */
    template <typename D = std::chrono::milliseconds> auto total() const {
        const auto now = SysClock::now();
        return std::chrono::duration_cast<D>(now - m_start).count();
    }
private:
    Tp m_start, m_rap;
};
