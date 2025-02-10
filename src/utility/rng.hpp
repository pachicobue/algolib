#pragma once
#include <random>
#include "../internal.hpp"
/**
 * @brief 乱数生成ヘルパー
 *
 * @tparam Engine 乱数生成器
 */
template <typename Engine> class RNG {
public:
    using result_type = typename Engine::result_type;
    using U = result_type;
    /**
     * @brief 生成される値の最小値
     *
     * @return T 最小値
     */
    static constexpr auto min() -> U {
        return Engine::min();
    }
    /**
     * @brief 生成される値の最大値
     *
     * @return T 最大値
     */
    static constexpr auto max() -> U {
        return Engine::max();
    }
    /**
     * @brief コンストラクタ
     */
    RNG()
        : RNG(std::random_device{}()) {
    }
    /**
     * @brief コンストラクタ
     *
     * @param seed シード
     */
    RNG(U seed)
        : m_rng(seed) {
    }
    /**
     * @brief 乱数生成
     *
     * @return T 乱数
     */
    auto operator()() -> U {
        return m_rng();
    }
    /**
     * @brief 乱数生成 (範囲指定)
     *
     * @tparam T 生成したい乱数値型 (整数のみ)
     * @param min 乱数の最小値
     * @param max 乱数の最大値
     * @return T 乱数
     */
    template <typename T>
    requires std::is_integral_v<T>
    auto val(T min, T max) -> T {
        return std::uniform_int_distribution<T>(min, max)(m_rng);
    }
    /**
     * @brief 乱数列生成 (範囲指定)
     *
     * @tparam T 生成したい乱数値型 (整数のみ)
     * @param N 乱数列長
     * @param min 乱数の最小値
     * @param max 乱数の最大値
     * @return Vec<T> 乱数列
     */
    template <typename T> auto vec(int N, T min, T max) -> Vec<T> {
        return genVec<T>(N, [&]() {
            return val<T>(min, max);
        });
    }
private:
    Engine m_rng;
};
inline RNG<std::mt19937> rng;
inline RNG<std::mt19937_64> rng64;
