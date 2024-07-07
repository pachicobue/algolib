#pragma once
#include <cassert>
#include "../../internal.hpp"
/**
 * @brief Trie木
 * @attention 文字列に限らず使える (各要素が 0~SIGMA-1 である数列ならOK)
 *
 * @tparam SIGMA 文字種
 */
template <int SIGMA> class Trie {
public:
    static constexpr int NIL = -1;
    struct Node {
        Node() : Node{false, 0} {}
        Node(bool isKey, int depth) : isKey{isKey}, depth{depth} { mdSeqFill(sons, NIL); }
        bool isKey;
        int depth;
        Arr<int, SIGMA> sons;
    };
    /**
     * @brief コンストラクタ
     */
    Trie() : m_nodes{Node{}} {}
    /**
     * @brief 文字列追加
     *
     * @param vs キー
     */
    template <typename Vs> auto addKey(const Vs& vs) -> void {
        int index = 0;
        for (int d : rep(std::size(vs))) {
            const auto v = vs[d];
            assert(v < SIGMA);
            if (m_nodes[index].sons[v] == NIL) { m_nodes[index].sons[v] = alloc(false, d + 1); }
            index = m_nodes[index].sons[v];
        }
        m_nodes[index].isKey = true;
    }
    /**
     * @brief ノード参照
     *
     * @param i ノードindex (indexはDFSで求まる)
     * @return Node& ノードの参照
     */
    auto operator[](int i) -> Node& { return m_nodes[i]; }
    /**
     * @brief ノード参照
     *
     * @param i ノードindex (indexはDFSで求まる)
     * @return Node& ノードの参照
     */
    auto operator[](int i) const -> const Node& { return m_nodes[i]; }
    /**
     * @brief ノード数
     *
     * @return int ノード数
     */
    auto size() const -> int { return (int)m_nodes.size(); }
private:
    auto alloc(bool isKey, int depth) -> int {
        m_nodes.push_back(Node{isKey, depth});
        return (int)m_nodes.size() - 1;
    }
    Vec<Node> m_nodes;
};
