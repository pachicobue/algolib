#pragma once
#include "../common.hpp"

class DynamicBitset
{
    using T = u64;
    static constexpr int B = sizeof(T) * 8;

public:
    DynamicBitset() {}
    DynamicBitset(int N) : m_n{N}, m_bn{ceilDiv(N, B)}, m_blocks(m_bn, 0) {}

    friend DynamicBitset& operator&=(DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        assert(bs1.size() == bs2.size());
        for (int b : rep(bs1.m_bn)) { bs1.m_blocks[b] &= bs2.m_blocks[b]; }
        return bs1;
    }
    friend DynamicBitset& operator|=(DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        assert(bs1.size() == bs2.size());
        for (int b : rep(bs1.m_bn)) { bs1.m_blocks[b] |= bs2.m_blocks[b]; }
        return bs1;
    }
    friend DynamicBitset& operator^=(DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        assert(bs1.size() == bs2.size());
        for (int b : rep(bs1.m_bn)) { bs1.m_blocks[b] ^= bs2.m_blocks[b]; }
        return bs1;
    }
    friend DynamicBitset& operator<<=(DynamicBitset& bs, int s)
    {
        assert(s >= 0);
        if (s >= bs.size()) {
            bs.resetAll();
            return bs;
        }
        if (s == 0) { return bs; }
        const auto [sb, sw] = I2B(s);
        for (int b : per(bs.m_bn)) {
            const T m0 = (b < sb ? T{0} : bs.m_blocks[b - sb]);
            const T m1 = (b <= sb ? T{0} : bs.m_blocks[b - sb - 1]);
            bs.m_blocks[b] = (m0 << sw) | (m1 >> (B - sw));
        }
        bs.trunk();
        return bs;
    }
    friend DynamicBitset& operator>>=(DynamicBitset& bs, int s)
    {
        assert(s >= 0);
        if (s >= bs.size()) {
            bs.resetAll();
            return bs;
        }
        if (s == 0) { return bs; }
        const auto [sb, sw] = I2B(s);
        for (int b : rep(bs.m_bn)) {
            const T m0 = (b + sb >= bs.m_bn ? T{0} : bs.m_blocks[b + sb]);
            const T m1 = (b + sb + 1 >= bs.m_bn ? T{0} : bs.m_blocks[b + sb + 1]);
            bs.m_blocks[b] = (m0 >> sw) | (m1 << (B - sw));
        }
        return bs;
    }
    friend DynamicBitset operator&(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        auto ans = bs1;
        return ans &= bs2;
    }
    friend DynamicBitset operator|(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        auto ans = bs1;
        return ans |= bs2;
    }
    friend DynamicBitset operator^(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        auto ans = bs1;
        return ans ^= bs2;
    }
    friend DynamicBitset operator<<(const DynamicBitset& bs, int s)
    {
        auto ans = bs;
        return ans <<= s;
    }
    friend DynamicBitset operator>>(const DynamicBitset& bs, int s)
    {
        auto ans = bs;
        return ans >>= s;
    }
    friend bool operator==(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        return comp(bs1, bs2) == 0;
    }
    friend bool operator!=(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        return not(bs1 == bs2);
    }
    friend bool operator<(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        return comp(bs1, bs2) == 1;
    }
    friend bool operator>(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        return comp(bs1, bs2) == -1;
    }
    friend bool operator<=(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        return not(bs1 > bs2);
    }
    friend bool operator>=(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        return not(bs1 < bs2);
    }
    friend DynamicBitset operator~(const DynamicBitset& bs)
    {
        auto ans = bs;
        for (int i : rep(bs.m_bn)) { ans.m_blocks[i] = ~ans.m_blocks[i]; }
        ans.trunk();
        return ans;
    }
    friend Ostream& operator<<(Ostream& os, const DynamicBitset& bs)
    {
        Str S(bs.size(), '0');
        for (int i : rep(bs.size())) {
            const auto [b, w] = I2B(i);
            if (isBitOn(bs.m_blocks[b], w)) { S[i] = '1'; }
        }
        reverseAll(S);
        return os << S;
    }

    bool test(int i) const
    {
        assert(0 <= i and i < m_n);
        const auto [b, w] = I2B(i);
        return isBitOn(m_blocks[b], w);
    }
    DynamicBitset& set(int i)
    {
        assert(0 <= i and i < m_n);
        const auto [b, w] = I2B(i);
        m_blocks[b] |= (1_i64 << w);
        return *this;
    }
    DynamicBitset& reset(int i)
    {
        assert(0 <= i and i < m_n);
        const auto [b, w] = I2B(i);
        m_blocks[b] &= ~(1_i64 << w);
        return *this;
    }
    DynamicBitset& flip(int i)
    {
        assert(0 <= i and i < m_n);
        const auto [b, w] = I2B(i);
        m_blocks[b] ^= (1_i64 << w);
        return *this;
    }
    int findFirst() const
    {
        for (int b : rep(m_bn)) {
            if (m_blocks[b] == 0) { continue; }
            const int w = lowBit(m_blocks[b]);
            const int i = B2I(b, w);
            return std::min(i, size());
        }
        return size();
    }
    int findNext(int pi) const
    {
        assert(0 <= pi and pi < m_n);
        pi++;
        if (pi == m_n) { return size(); }
        const auto [pb, pw] = I2B(pi);
        for (int b : irange(pb, m_bn)) {
            T x = m_blocks[b];
            if (b == pb) { x &= ~bitMask(0, pw); }
            if (x == 0) { continue; }
            const int w = lowBit(x);
            const int i = B2I(b, w);
            return std::min(i, size());
        }
        return size();
    }

    DynamicBitset& setAll()
    {
        fillAll(m_blocks, LIMMAX<T>), trunk();
        return *this;
    }
    DynamicBitset& resetAll()
    {
        fillAll(m_blocks, 0);
        return *this;
    }
    int count() const
    {
        int ans = 0;
        for (int b : rep(m_bn)) { ans += popCount(m_blocks[b]); }
        return ans;
    }
    int size() const { return m_n; }

private:
    static constexpr Pair<int, int> I2B(int i) { return {i / B, i % B}; }
    static constexpr int B2I(int b, int w) { return b * B + w; }
    static int comp(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        assert(bs1.size() == bs2.size());
        for (int b : rep(bs1.m_bn)) {
            T x1 = bs1.m_blocks[b];
            T x2 = bs2.m_blocks[b];
            if (x1 != x2) { return (x1 < x2 ? 1 : -1); }
        }
        return 0;
    }
    void trunk() { m_blocks.back() &= ~bitMask(m_n % B); }
    int m_n;
    int m_bn;
    Vec<T> m_blocks;
};
