#pragma once
#include <cassert>
#include <concepts>
#include <optional>
#include <type_traits>
#include "../internal.hpp"
/**
 * @brief Li-Chao Tree
 *
 * @tparam T 直線の傾き,切片型
 */
template <typename T = i64> class LiChaoTree {
    using L = Pair<T, T>;
    static constexpr int NIL = -1;
    static constexpr auto Null = std::nullopt;
    struct Node {
        Opt<L> line = Null;
        Arr<int, 2> sons{NIL, NIL};
    };
    static auto comp(const Opt<L>& l1, const Opt<L>& l2, i64 x) -> bool // l1(x) < l2(x)
    {
        if (l1 == Null or l2 == Null) {
            return l2 == Null;
        }
        const auto& [a1, b1] = l1.value();
        const auto& [a2, b2] = l2.value();
        if constexpr (std::is_integral_v<T>) {
            if (a1 == a2) {
                return b1 <= b2;
            } else if (a1 > a2) {
                return x <= floorDiv(b2 - b1, a1 - a2);
            } else {
                return floorDiv(b1 - b2, a2 - a1) < x;
            }
        } else {
            return a1 * T{x} + b1 < a2 * T{x} + b2;
        }
    }
public:
    /**
     * @brief コンストラクタ
     * @attention クエリ x は xmin <= x < xsup を満たす必要あり
     *
     * @param xmin
     * @param xsup
     */
    LiChaoTree(i64 xmin, i64 xsup)
        : m_xmin{xmin}, m_xsup{xsup}, m_nodes{Node{}} {
        assert(m_xmin < m_xsup);
    }
    /**
     * @brief [x_min,x_sup) 全体に跨る直線を追加
     *
     * @param line 直線
     */
    auto addLine(const L& line) -> void {
        add(line, 0, m_xmin, m_xsup);
    }
    /**
     * @brief [x_left, x_right) 上に跨る線分を追加
     *
     * @param line 線分
     * @param x_left
     * @param x_right
     */
    auto addSeg(const L& line, i64 x_left, i64 x_right) -> void {
        if (x_left >= x_right) {
            return;
        }
        assert(m_xmin <= x_left and x_right <= m_xsup);
        Fix([&](auto self, int index, i64 lx, i64 rx) -> void {
            if (x_right <= lx or rx <= x_left) {
                return;
            }
            if (x_left <= lx and rx <= x_right) {
                add(line, index, lx, rx);
            } else {
                ensureSub(index);
                const auto nindexs = m_nodes[index].sons;
                const i64 nxs[3] = {lx, (lx + rx) / 2, rx};
                for (int c : rep(2)) {
                    self(nindexs[c], nxs[c], nxs[c + 1]);
                }
            }
        })(0, m_xmin, m_xsup);
    }
    /**
     * @brief 座標 x で最小値を取るような直線取得
     *
     * @param x 座標
     * @return Opt<L> 最小値を取る直線 (x 上に直線が無ければ Null)
     */
    auto minLine(i64 x) const -> Opt<L> {
        i64 lx = m_xmin, rx = m_xsup;
        Opt<L> Ans = Null;
        for (int index = 0; index != NIL;) {
            const auto& pl = m_nodes[index].line;
            if (pl != Null) {
                chmin(Ans, pl, [&](auto l1, auto l2) {
                    return comp(l1, l2, x);
                });
            }
            const i64 mx = (lx + rx) / 2;
            const auto& nindexs = m_nodes[index].sons;
            const i64 nxs[3] = {lx, mx, rx};
            const int c = (x < mx ? 0 : 1);
            index = nindexs[c], lx = nxs[c], rx = nxs[c + 1];
        }
        return Ans;
    }
private:
    auto add(Opt<L> l, int index, i64 lx, i64 rx) -> void {
        assert(l != Null);
        assert(index != NIL);
        while (true) {
            if (rx - lx == 1) {
                chmin(m_nodes[index].line, l, [&](auto l1, auto l2) {
                    return comp(l1, l2, lx);
                });
                break;
            }
            const auto& pl = m_nodes[index].line;
            const i64 mx = (lx + rx) / 2;
            const bool lunder = comp(l, pl, lx), munder = comp(l, pl, mx), runder = comp(l, pl, rx);
            if (munder) {
                std::ranges::swap(l, m_nodes[index].line);
            }
            if (lunder == runder) {
                break;
            }
            ensureSub(index);
            const auto& nindexs = m_nodes[index].sons;
            const i64 nxs[3] = {lx, mx, rx};
            const int c = (lunder == munder ? 1 : 0);
            index = nindexs[c], lx = nxs[c], rx = nxs[c + 1];
        }
    }
    auto alloc() -> int {
        m_nodes.push_back(Node{});
        return (int)m_nodes.size() - 1;
    }
    auto ensureSub(int index) -> void {
        for (int c : rep(2)) {
            if (m_nodes[index].sons[c] == NIL) {
                m_nodes[index].sons[c] = alloc();
            }
        }
    }
    i64 m_xmin, m_xsup;
    Vec<Node> m_nodes;
};
