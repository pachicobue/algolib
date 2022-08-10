#pragma once
#include "../common.hpp"
template<typename K, typename V, int LG = 20>
class IntDict
{
public:
    IntDict() = default;
    V& operator[](K k)
    {
        const auto i = index(k);
        if (not m_used.test(i)) {
            m_used.set(i), m_keys[i] = k;
            m_vals[i] = V{};
        }
        return m_vals[i];
    }
    const V& at(K k) const
    {
        return m_vals[index(k)];
    }
    void erase(K k)
    {
        m_used.reset(index(k));
    }
    bool contains(K k) const
    {
        const auto i = index(k);
        return m_used.test(i) and m_keys[i] == k;
    }

private:
    u32 index(K k) const
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
    Arr<V, N> m_vals;
};
