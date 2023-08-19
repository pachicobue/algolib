#pragma once
#include "../../common.hpp"
/**
 * @brief Binary Trie
 * 
 * @tparam D ビット幅
 */
template<int D>
    requires(D < 32)
class BinaryTrie
{
public:
    static constexpr int NIL = -1;
    struct Node
    {
        Node() : Node{0} {}
        Node(int sub) : sub{sub} { mdSeqFill(sons, NIL); }
        int sub;
        Arr<int, 2> sons;
    };
    /**
     * @brief コンストラクタ
     */
    BinaryTrie() : m_xor{}, m_nodes{Node{}} {}
    /**
     * @brief 値追加
     * 
     * @param X キー
     */
    void addKey(i64 X)
    {
        assert(0 <= X and X < (1_i64 << D));
        int index = 0;
        for (int d : per(D)) {
            m_nodes[index].sub++;
            const int v = isBitOn(X ^ m_xor, d);
            if (m_nodes[index].sons[v] == NIL) { m_nodes[index].sons[v] = alloc(0); }
            index = m_nodes[index].sons[v];
        }
        m_nodes[index].sub++;
    }
    /**
     * @brief 値削除
     * 
     * @param X キー
     */
    void delKey(i64 X)
    {
        assert(0 <= X and X < (1_i64 << D));
        int index = 0;
        for (int d : per(D)) {
            m_nodes[index].sub--;
            const int v = isBitOn(X ^ m_xor, d);
            assert(m_nodes[index].sons[v] != NIL);
            index = m_nodes[index].sons[v];
        }
        m_nodes[index].sub--;
    }
    /**
     * @brief 全体にxor適用する
     * 
     * @param X 適用するxor値
     */
    void operateXor(i64 X)
    {
        assert(0 <= X);
        m_xor ^= X;
    }
    /**
     * @brief 最小値
     * 
     * @return i64 最小値
     */
    i64 mdSeqMin() const { return minMax(false); }
    /**
     * @brief 最大値
     * 
     * @return i64 最大値
     */
    i64 mdSeqMax() const { return minMax(true); }
    /**
     * @brief 一括削除
     */
    void clear()
    {
        m_nodes = {Node{}};
        m_nodes.shrink_to_fit();
        m_xor = 0;
    }
    /**
     * @brief 要素数
     * 
     * @return int 要素数
     */
    int size() const { return m_nodes[0].sub; }
    /**
     * @brief 空かどうか
     * 
     * @return true 空
     * @return false 空ではない
     */
    bool empty() const { return size() == 0; }
private:
    int alloc(bool sub)
    {
        m_nodes.push_back(Node{sub});
        return (int)m_nodes.size() - 1;
    }
    i64 minMax(bool calcMax) const
    {
        assert(not empty());
        i64 X     = 0;
        int index = 0;
        for (int d : per(D)) {
            const int mv = isBitOn(m_xor, d) ^ calcMax;
            if (m_nodes[index].sons[mv] != NIL and m_nodes[m_nodes[index].sons[mv]].sub > 0) {
                index = m_nodes[index].sons[mv];
                X ^= (i64)mv << d;
            } else {
                index = m_nodes[index].sons[1 - mv];
                X ^= (i64)(1 - mv) << d;
            }
        }
        return X ^ m_xor;
    }
    i64 m_xor;
    Vec<Node> m_nodes;
};
