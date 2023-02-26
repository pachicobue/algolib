#pragma once
#include "../../common.hpp"
class BitVector
{
    static constexpr int B = 64;
    static int rank(u64 v, int i)
    {
        if (i == 0) { return 0; }
        return popCount(v << (B - i));
    }
    struct Block
    {
        u64 bits = 0;
        int rank = 0;  // ブロック先頭までに1が何個あるか
    };

public:
    BitVector(int n) : m_size{n}, m_bn{n / B + 1}, m_blocks(m_bn) {}
    void set(int i)
    {
        assert(0 <= i and i < m_size);
        m_blocks[i / B].bits |= (1_u64 << (i % B));
        m_calced = false;
    }
    int rank0(int i) { return i - rank1(i); }
    int rank1(int i)
    {
        assert(0 <= i and i <= m_size);
        calc();
        return m_blocks[i / B].rank + rank(m_blocks[i / B].bits, i % B);
    }
    int zero()
    {
        calc();
        return m_zero;
    }
    int one() { return m_size - zero(); }

private:
    void calc()
    {
        if (not m_calced) {
            m_zero = m_size;
            for (int i : irange(1, m_bn)) {
                const int p = popCount(m_blocks[i - 1].bits);
                m_blocks[i].rank += m_blocks[i - 1].rank + p;
                m_zero -= p;
            }
            m_zero -= popCount(m_blocks[m_bn - 1].bits);
            m_calced = true;
        }
    }
    int m_size;
    int m_bn;
    Vec<Block> m_blocks;
    bool m_calced = false;
    int m_zero = 0;
};
