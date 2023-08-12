#pragma once
#include "../common.hpp"
#include "../data_structure/trie/trie.hpp"

template<int SIGMA> class AhoCorasick : public Trie<SIGMA>
{
public:
    using Trie<SIGMA>::NIL;

    AhoCorasick() : Trie<SIGMA>{}, m_link{NIL}, m_dirty{false} {}
    using Trie<SIGMA>::operator[];
    using Trie<SIGMA>::size;
    template<typename Vs> void addKey(const Vs& vs)
    {
        m_dirty = true;
        Trie<SIGMA>::addKey(vs);
    }
    template<typename V> int nextNode(int index, V v)
    {
        if (m_dirty) { build(); }
        return nextUnsafe(index, v);
    }
    int suffixLink(int index)
    {
        if (m_dirty) { build(); }
        return m_link[index];
    }
private:
    template<typename V> int nextUnsafe(int index, V v) const
    {
        while (index != NIL) {
            if ((*this)[index].sons[v] != NIL) {
                return (*this)[index].sons[v];
            } else {
                index = m_link[index];
            }
        }
        return 0;
    }

    void build()
    {
        m_link.resize(size(), NIL);
        Queue<int> Q;
        Q.push(0);
        while (not Q.empty()) {
            const int index = Q.front();
            Q.pop();
            for (int v : rep(SIGMA)) {
                const int nindex = (*this)[index].sons[v];
                if (nindex == NIL) { continue; }
                m_link[nindex] = nextUnsafe(m_link[index], v);
                Q.push(nindex);
            }
        }
        m_dirty = false;
    }

    Vec<int> m_link;
    bool m_dirty;
};
