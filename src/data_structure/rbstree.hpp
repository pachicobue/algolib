#pragma once
#include "../misc/common.hpp"
template<typename T>
class RBST
{
    struct Node
    {
        Node(const T& v) : val{v}, sz{1} {}
        T val;
        int sz = 0;
        int pi = -1;
        Arr<int, 2> sons = {-1, -1};
    };
    using P = Pair<int, int>;

public:
    RBST() {}
    const Node& operator[](int r) const
    {
        return m_nodes[r];
    }
    Node& operator[](int r)
    {
        return m_nodes[r];
    }
    int get(int r, int k)
    {
        const auto& [lr, R] = split(r, k);
        const auto& [mr, rr] = split(R, 1);
        return mr;
    }
    int merge(int i, int j)
    {
        if (i == -1 or j == -1) { return i == -1 ? j : i; }
        const auto& [li, ri] = m_nodes[i].sons;
        if (rng_xo.val<int>(0, size(i) + size(j) - 1) < size(i)) {
            const int rr = merge(m_nodes[i].ri, j);
            return m_nodes[i].ri = rr, m_nodes[rr].pi = i, up(i);
        } else {
            const int lr = merge(m_nodes[j].li, i);
            return m_nodes[j].li = lr, m_nodes[lr].pi = j, up(j);
        }
    }
    P split(int i, int k)
    {
        auto& [li, ri] = m_nodes[i].sons;
        if (size(i) == 0) { return {-1, -1}; }
        if (size(li) >= k) {
            const auto& [lli, lri] = split(li, k);
            li = lri;
            m_nodes[lri].pi = i;
            up(i);
            return P{lli, i};
        } else {
            const auto& [rli, rri] = split(ri, k - size(li) - 1);
            ri = rri;
            m_nodes[rri].pi = i;
            up(i);
            return P{i, rri};
        }
    }
    int size(int r) const
    {
        return r == -1 ? 0 : m_nodes[r].sz;
    }
    Vec<Node> subNodes(int i) const
    {
        if (i == -1) { return Vec<Node>{}; }
        const auto& [li, ri] = m_nodes[i].sons;
        return subNodes(li) + Vec<Node>{m_nodes[i]} + subNodes(ri);
    }

private:
    int isRight(int i)
    {
        return m_nodes[i].pi != -1 and m_nodes[m_nodes[i].pi].ri == i;
    }
    int isLeft(int i)
    {
        return m_nodes[i].pi != -1 and m_nodes[m_nodes[i].pi].li == i;
    }
    int up(int i)
    {
        const auto& [li, ri] = m_nodes[i].sons;
        m_nodes[i].sz = size(li) + size(ri) + 1;
        return i;
    }
    int alloc(const T& v)
    {
        m_nodes.push_back(Node(v));
        return m_nodes.size() - 1;
    }
    Vec<Node> m_nodes;
};
