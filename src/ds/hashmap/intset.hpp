#pragma once
#include "../../common.hpp"

template<typename K>
class IntSet
{
public:
    IntSet(int cap = 4)
        : m_lg{ceillog(cap)}, m_cap{1 << m_lg}, m_size{0}, m_keys(m_cap, K{}), m_shifts(m_cap, -1)
    {}
    bool insert(K k)
    {
        int i = find(k);
        if (i != -1) { return false; }
        alloc(k), expand();
        return true;
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
        IntSet newSet(new_cap);
        for (int i : rep(m_cap)) {
            if (m_shifts[i] != -1) { newSet.insert(m_keys[i]); }
        }
        std::swap(newSet, *this);
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
    void alloc(K k)
    {
        m_size++;
        for (int ind = hash(k), s = 0;; (ind += 1) &= (m_cap - 1)) {
            if (m_shifts[ind] == -1) {
                m_keys[ind] = k, m_shifts[ind] = s;
                return;
            }
            if (m_shifts[ind] < s) { std::swap(m_keys[ind], k), std::swap(m_shifts[ind], s); }
            s++;
        }
    }
    int m_lg, m_cap;
    int m_size;
    Vec<K> m_keys;
    Vec<int> m_shifts;
};
