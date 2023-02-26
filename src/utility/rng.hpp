#pragma once
#include "../common.hpp"
template<typename Engine>
class RNG
{
public:
    using result_type = typename Engine::result_type;
    using T = result_type;
    static constexpr T min() { return Engine::min(); }
    static constexpr T max() { return Engine::max(); }
    RNG() : RNG(std::random_device{}()) {}
    RNG(T seed) : m_rng(seed) {}
    T operator()() { return m_rng(); }
    template<typename T>
    T val(T min, T max)
    {
        return std::uniform_int_distribution<T>(min, max)(m_rng);
    }
    template<typename T, typename... Args>
    auto tup(T min, T max, const Args&... offsets)
    {
        return Tup<T, Args...>{val<T>(min, max), val<Args>(offsets)...};
    }
    template<typename T>
    Vec<T> vec(int n, T min, T max)
    {
        return genVec<T>(n, [&]() { return val<T>(min, max); });
    }
    template<typename T>
    Vec<Vec<T>> vvec(int n, int m, T min, T max)
    {
        return genVec<Vec<T>>(n, [&]() { return vec(m, min, max); });
    }

private:
    Engine m_rng;
};
inline RNG<std::mt19937> rng;
inline RNG<std::mt19937_64> rng64;
