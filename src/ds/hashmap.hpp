#pragma once
#include "../common.hpp"

template<typename K, typename V>
class IntDict
{
public:
    IntDict(int cap = 4)
        : m_lg{ceillog(cap)},
          m_cap{1 << m_lg},
          m_size{0},
          m_keys(m_cap, K{}),
          m_vals(m_cap, V{}),
          m_shifts(m_cap, -1)
    {}
    V& operator[](K k)
    {
        int i = find(k);
        if (i != -1) { return m_vals[i]; }
        allocIndex(k);
        expand();
        return m_vals[find(k)];
    }
    const V& at(K k) const
    {
        int i = find(k);
        assert(i != -1);
        return m_vals[i];
    }
    bool erase(K k)
    {
        int i = find(k);
        if (i != -1) {
            m_size--;
            m_shifts[i] = -1;
            shrink();
            return true;
        }
        return false;
    }
    bool contains(K k) const { return find(k) != -1; }
    int size() const { return m_size; }

private:
    int hash(K k) const
    {
        constexpr u64 a = 11400714819323198485_u64;
        return (a * k) >> (64 - m_lg);
    }
    void rehash(int new_cap)
    {
        SHOW(new_cap);
        IntDict newHash(new_cap);
        for (int i : rep(m_cap)) {
            if (m_shifts[i] != -1) { newHash[m_keys[i]] = m_vals[i]; }
        }
        std::swap(newHash, *this);
    }
    void expand()
    {
        if ((m_size + 1) * 2 > m_cap) { rehash(m_cap * 2); }
    }
    void shrink()
    {
        if (m_size * 10 < m_cap) { rehash(m_cap / 2); }
    }
    int find(K k) const
    {
        for (int ind = hash(k);; (ind += 1) &= (m_cap - 1)) {
            if (m_shifts[ind] == -1) { return -1; }
            if (m_keys[ind] == k) { return ind; }
        }
        return -1;
    }
    int allocIndex(K k)
    {
        m_size++;
        int ans = m_cap;
        V v{};
        for (int ind = hash(k), s = 0;; (ind += 1) &= (m_cap - 1)) {
            if (m_shifts[ind] == -1) {
                chmin(ans, ind);
                m_keys[ind] = k, m_vals[ind] = v;
                m_shifts[ind] = s;
                return ans;
            }
            if (m_shifts[ind] < s) {
                chmin(ans, ind);
                std::swap(m_keys[ind], k), std::swap(m_vals[ind], v);
                std::swap(m_shifts[ind], s);
            }
            s++;
        }
        return -1;
    }
    int m_lg, m_cap;
    int m_size = 0;
    Vec<K> m_keys;
    Vec<V> m_vals;
    Vec<int> m_shifts;
};
