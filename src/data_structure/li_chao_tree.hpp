#pragma once
#include "../misc/common.hpp"
template<typename T>
class LiChaoTree
{
    using L = Pair<T, T>;
    static constexpr L NIL = {0, INF<T>};
    struct Node
    {
        L line = NIL;
        Arr<int, 2> sons{-1, -1};
    };
    static bool comp(const L& l1, const L& l2, T x)
    {
        if (l1 == NIL or l2 == NIL) { return l2 == NIL; }
        const auto& [a1, b1] = l1;
        const auto& [a2, b2] = l2;
        if (a1 == a2) {
            return b1 <= b2;
        } else if (a1 > a2) {
            return x <= fdiv(b2 - b1, a1 - a2);
        } else {
            return fdiv(b1 - b2, a2 - a1) < x;
        }
    }

public:
    LiChaoTree(T xmin, T xsup) : m_xmin{xmin}, m_xsup{xsup}, m_nodes{Node{}}
    {
        assert(m_xmin < m_xsup);
    }
    void addLine(T a, T b)
    {
        add(L{a, b}, 0, m_xmin, m_xsup);
    }
    void addSeg(T a, T b, T x_left, T x_right)
    {
        if (x_left >= x_right) { return; }
        assert(m_xmin <= x_left and x_right <= m_xsup);
        Fixpoint([&](auto dfs, int i, T lx, T rx) -> void {
            if (x_left <= lx and rx <= x_right) {
                add(L{a, b}, i, lx, rx);
            } else {
                if (rx - lx == 1) { return; }
                auto& [li, ri] = m_nodes[i].sons;
                const T mx = (lx + rx) / 2;
                if (lx < x_right and x_left < mx) {
                    if (li == -1) { li = alloc(); }
                    dfs(li, lx, mx);
                }
                if (mx < x_right and x_left < rx) {
                    if (ri == -1) { ri = alloc(); }
                    dfs(ri, mx, rx);
                }
            }
        })(0, m_xmin, m_xsup);
    }
    Pair<bool, L> minLine(const T x) const
    {
        T lx = m_xmin, rx = m_xsup;
        Pair<bool, L> ans = {false, NIL};
        for (int i = 0; i != -1;) {
            const auto& pl = m_nodes[i].line;
            if ((not ans.first) or comp(pl, ans.second, x)) {
                ans.first = true;
                ans.second = pl;
            }
            const auto& [li, ri] = m_nodes[i].sons;
            const T mx = (lx + rx) / 2;
            if (x < mx) {
                i = li;
                rx = mx;
            } else {
                i = ri;
                lx = mx;
            }
        }
        return ans;
    }

private:
    void add(L l, int i, T lx, T rx)
    {
        for (;;) {
            const auto& pl = m_nodes[i].line;
            const T mx = (lx + rx) / 2;
            const bool lunder = comp(l, pl, lx);
            const bool runder = comp(l, pl, rx);
            const bool munder = comp(l, pl, mx);
            if (munder) { std::swap(l, m_nodes[i].line); }
            if (lunder == runder) { break; }
            int dir = (lunder == munder ? 1 : 0);
            if (rx - lx == 1) { break; }
            int nind = m_nodes[i].sons[dir];
            if (nind == -1) { nind = m_nodes[i].sons[dir] = alloc(); }
            i = nind;
            if (rx - lx == 1) { break; }
            if (lunder == munder) {
                lx = mx;
            } else {
                rx = mx;
            }
        }
    }
    int alloc()
    {
        m_nodes.push_back(Node{});
        return (int)m_nodes.size() - 1;
    }
    T m_xmin, m_xsup;
    Vec<Node> m_nodes;
};
