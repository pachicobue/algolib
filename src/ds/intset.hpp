#pragma once
#include "../common.hpp"
template<typename K, int LG = 20>
class IntSet
{
public:
    IntSet() = default;
    void insert(const K& k)
    {
        const auto i = index(k);
        m_used.set(i), m_keys[i] = k;
    }
    void erase(const K& k)
    {
        m_used.reset(index(k));
    }
    bool contains(const K& k) const
    {
        const auto i = index(k);
        return m_used.test(i) and m_keys[i] == k;
    }

private:
    u32 index(const K& k) const
    {
        u32 i = 0;
        for (i = fibHash(k); m_used.test(i) and m_keys[i] != k;
             (i += 1) &= (N - 1)) {}
        return i;
    }
    static constexpr int N = 1 << LG;
    static constexpr u32 fibHash(u64 k)
    {
        constexpr u64 a = 11400714819323198485_u64;
        return (a * k) >> (64 - LG);
    }
    BSet<N> m_used;
    Arr<K, N> m_keys;
};
