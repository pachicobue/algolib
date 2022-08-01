#pragma once
#include "type_alias.hpp"
#include "container_util.hpp"
#include "xoshiro.hpp"
template<typename Rng>
class RNG
{
public:
    using result_type = typename Rng::result_type;
    using T = result_type;
    static constexpr T min()
    {
        return Rng::min();
    }
    static constexpr T max()
    {
        return Rng::max();
    }
    RNG() : RNG(std::random_device{}()) {}
    RNG(T seed) : m_rng(seed) {}
    T operator()()
    {
        return m_rng();
    }
    template<typename T>
    T val(T min, T max)
    {
        return std::uniform_int_distribution<T>(min, max)(m_rng);
    }
    template<typename T>
    Pair<T, T> pair(T min, T max)
    {
        return std::minmax({val<T>(min, max), val<T>(min, max)});
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
    Rng m_rng;
};
RNG<std::mt19937> rng;
RNG<std::mt19937_64> rng64;
RNG<Xoshiro32> rng_xo;
RNG<Xoshiro64> rng_xo64;
