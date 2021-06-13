#pragma once
#include "type_alias.hpp"
#include "constants.hpp"
#pragma COMMENT("[REFS] Xoshiro: https://prng.di.unimi.it")
namespace xoshiro_impl {
u64 x;
u64 next()
{
    uint64_t z = (x += 0x9e3779b97f4a7c15);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
    z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
    return z ^ (z >> 31);
}
}  // namespace xoshiro_impl
class Xoshiro32
{
public:
    using result_type = u32;
    using T = result_type;
    Xoshiro32(T seed = 0)
    {
        xoshiro_impl::x = seed;
        s[0] = xoshiro_impl::next();
        s[1] = xoshiro_impl::next();
        s[2] = xoshiro_impl::next();
        s[3] = xoshiro_impl::next();
    }
    static constexpr T min()
    {
        return LIMMIN<T>;
    }
    static constexpr T max()
    {
        return LIMMAX<T>;
    }
    T operator()()
    {
        return next();
    }

private:
    static constexpr T rotl(const T x, int k)
    {
        return (x << k) | (x >> (32 - k));
    }
    T next()
    {
        const T ans = rotl(s[1] * 5, 7) * 9;
        const T t = s[1] << 9;
        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];
        s[2] ^= t;
        s[3] = rotl(s[3], 11);
        return ans;
    }
    T s[4];
};
class Xoshiro64
{
public:
    using result_type = u64;
    using T = result_type;
    Xoshiro64(T seed = 0)
    {
        xoshiro_impl::x = seed;
        s[0] = xoshiro_impl::next();
        s[1] = xoshiro_impl::next();
        s[2] = xoshiro_impl::next();
        s[3] = xoshiro_impl::next();
    }
    static constexpr T min()
    {
        return LIMMIN<T>;
    }
    static constexpr T max()
    {
        return LIMMAX<T>;
    }
    T operator()()
    {
        return next();
    }

private:
    static constexpr T rotl(const T x, int k)
    {
        return (x << k) | (x >> (64 - k));
    }
    T next()
    {
        const T ans = rotl(s[1] * 5, 7) * 9;
        const T t = s[1] << 17;
        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];
        s[2] ^= t;
        s[3] = rotl(s[3], 45);
        return ans;
    }
    T s[4];
};
