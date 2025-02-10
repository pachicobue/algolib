#pragma once
#include <bit>
#include <cassert>
#include "../../internal.hpp"
/**
 * @brief BitVector
 */
class BitVector {
    static constexpr int B = 64;
    static constexpr auto rank(u64 v, int i) -> int {
        if (i == 0) {
            return 0;
        }
        return std::popcount(v << (B - i));
    }
    struct Block {
        u64 bits = 0;
        int rank = 0; // ブロック先頭までに1が何個あるか
    };
public:
    /**
     * @brief コンストラクタ
     *
     * @param n bit長
     */
    BitVector(int n)
        : m_size{n}, m_bn{n / B + 1}, m_blocks(m_bn) {
    }
    /**
     * @brief i bit目を立てる
     *
     * @param i
     */
    auto set(int i) -> void {
        assert(0 <= i and i < m_size);
        m_blocks[i / B].bits |= (1_u64 << (i % B));
        m_calced = false;
    }
    /**
     * @brief i bit目未満の 0 の個数
     *
     * @param i
     * @return int 0 の個数
     */
    auto rank0(int i) -> int {
        return i - rank1(i);
    }
    /**
     * @brief i bit目未満の 1 の個数
     *
     * @param i
     * @return int 1 の個数
     */
    auto rank1(int i) -> int {
        assert(0 <= i and i <= m_size);
        return calc(), m_blocks[i / B].rank + rank(m_blocks[i / B].bits, i % B);
    }
    /**
     * @brief 0 の個数
     *
     * @return int 0 の個数
     */
    auto zero() -> int {
        return calc(), m_zero;
    }
    /**
     * @brief 1 の個数
     *
     * @return int 1 の個数
     */
    auto one() -> int {
        return m_size - zero();
    }
private:
    auto calc() -> void {
        if (not m_calced) {
            m_zero = m_size;
            for (int i : irange(1, m_bn)) {
                const int p = std::popcount(m_blocks[i - 1].bits);
                m_blocks[i].rank += m_blocks[i - 1].rank + p;
                m_zero -= p;
            }
            m_zero -= std::popcount(m_blocks[m_bn - 1].bits);
            m_calced = true;
        }
    }
    int m_size;
    int m_bn;
    Vec<Block> m_blocks;
    bool m_calced = false;
    int m_zero = 0;
};
