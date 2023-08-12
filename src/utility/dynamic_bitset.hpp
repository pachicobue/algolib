#pragma once
#include "../common.hpp"
/**
 * @brief Vec<u64> ベースの bitset
 * @attention resize などは無いので可変長ではない
 */
class DynamicBitset
{
    using T                = u64;
    static constexpr int B = sizeof(T) * 8;
public:
    /**
     * @brief コンストラクタ
     */
    DynamicBitset() {}
    /**
     * @brief コンストラクタ
     * 
     * @param N bit長
     */
    DynamicBitset(int N) : m_n{N}, m_bn{(int)ceilDiv(N, B)}, m_blocks(m_bn, 0) {}
    /**
     * @brief bitset同士のAND
     * 
     * @param bs1 
     * @param bs2 
     * @return DynamicBitset& self
     */
    friend DynamicBitset& operator&=(DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        assert(bs1.size() == bs2.size());
        for (int b : rep(bs1.m_bn)) { bs1.m_blocks[b] &= bs2.m_blocks[b]; }
        return bs1;
    }
    /**
     * @brief bitset同士のOR
     * 
     * @param bs1 
     * @param bs2 
     * @return DynamicBitset& self
     */
    friend DynamicBitset& operator|=(DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        assert(bs1.size() == bs2.size());
        for (int b : rep(bs1.m_bn)) { bs1.m_blocks[b] |= bs2.m_blocks[b]; }
        return bs1;
    }
    /**
     * @brief bitset同士のXOR
     * 
     * @param bs1 
     * @param bs2 
     * @return DynamicBitset& self
     */
    friend DynamicBitset& operator^=(DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        assert(bs1.size() == bs2.size());
        for (int b : rep(bs1.m_bn)) { bs1.m_blocks[b] ^= bs2.m_blocks[b]; }
        return bs1;
    }
    /**
     * @brief bitsetの左Shift
     * 
     * @param bs 
     * @param s シフト幅 (非負)
     * @return DynamicBitset& self
     */
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
            const T m0     = (b < sb ? T{0} : bs.m_blocks[b - sb]);
            const T m1     = (b <= sb ? T{0} : bs.m_blocks[b - sb - 1]);
            bs.m_blocks[b] = (m0 << sw) | (m1 >> (B - sw));
        }
        bs.trunk();
        return bs;
    }
    /**
     * @brief bitsetの右Shift
     * 
     * @param bs
     * @param s シフト幅 (非負)
     * @return DynamicBitset& self
     */
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
            const T m0     = (b + sb >= bs.m_bn ? T{0} : bs.m_blocks[b + sb]);
            const T m1     = (b + sb + 1 >= bs.m_bn ? T{0} : bs.m_blocks[b + sb + 1]);
            bs.m_blocks[b] = (m0 >> sw) | (m1 << (B - sw));
        }
        return bs;
    }
    /**
     * @brief bitset同士のAND
     * 
     * @param bs1 
     * @param bs2 
     * @return DynamicBitset AND結果
     */
    friend DynamicBitset operator&(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        auto ans = bs1;
        return ans &= bs2;
    }
    /**
     * @brief bitset同士のOR
     * 
     * @param bs1 
     * @param bs2 
     * @return DynamicBitset OR結果
     */
    friend DynamicBitset operator|(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        auto ans = bs1;
        return ans |= bs2;
    }
    /**
     * @brief bitset同士のXOR
     * 
     * @param bs1 
     * @param bs2 
     * @return DynamicBitset XOR結果
     */
    friend DynamicBitset operator^(const DynamicBitset& bs1, const DynamicBitset& bs2)
    {
        auto ans = bs1;
        return ans ^= bs2;
    }
    /**
     * @brief bitsetの左Shift
     * 
     * @param bs
     * @param s シフト幅 (非負)
     * @return DynamicBitset Shift結果
     */
    friend DynamicBitset operator<<(const DynamicBitset& bs, int s)
    {
        auto ans = bs;
        return ans <<= s;
    }
    /**
     * @brief bitsetの右Shift
     * 
     * @param bs
     * @param s シフト幅 (非負)
     * @return DynamicBitset Shift結果
     */
    friend DynamicBitset operator>>(const DynamicBitset& bs, int s)
    {
        auto ans = bs;
        return ans >>= s;
    }
    /**
     * @brief bitset同士の等号比較
     * 
     * @param bs1 
     * @param bs2 
     * @return true 等しい
     * @return false 等しくない
     */
    friend bool operator==(const DynamicBitset& bs1, const DynamicBitset& bs2) { return bs1.m_blocks == bs2.m_blocks; }
    /**
     * @brief bitset同士の一貫比較
     * 
     * @param bs1
     * @param bs2
     * @return 一貫比較結果
     */
    friend auto operator<=>(const DynamicBitset& bs1, const DynamicBitset& bs2) { return bs1.m_blocks <=> bs2.m_blocks; }
    /**
     * @brief bitset全体のNOT
     * 
     * @param bs 
     * @return DynamicBitset NOT結果
     */
    friend DynamicBitset operator~(const DynamicBitset& bs)
    {
        auto ans = bs;
        for (int i : rep(bs.m_bn)) { ans.m_blocks[i] = ~ans.m_blocks[i]; }
        ans.trunk();
        return ans;
    }
    /**
     * @brief i bit目の取得
     * 
     * @param i bit位置
     * @return true i bit目がON
     * @return false i bit目がOFF
     */
    bool test(int i) const
    {
        assert(0 <= i and i < m_n);
        const auto [b, w] = I2B(i);
        return isBitOn(m_blocks[b], w);
    }
    /**
     * @brief i bit目を立てる
     * 
     * @param i bit位置
     * @return DynamicBitset& self
     */
    DynamicBitset& set(int i)
    {
        assert(0 <= i and i < m_n);
        const auto [b, w] = I2B(i);
        m_blocks[b] |= (1_i64 << w);
        return *this;
    }
    /**
     * @brief i bit目を下げる
     * 
     * @param i bit位置
     * @return DynamicBitset& self
     */
    DynamicBitset& reset(int i)
    {
        assert(0 <= i and i < m_n);
        const auto [b, w] = I2B(i);
        m_blocks[b] &= ~(1_i64 << w);
        return *this;
    }
    /**
     * @brief i bit目を反転する
     * 
     * @param i bit位置
     * @return DynamicBitset& self
     */
    DynamicBitset& flip(int i)
    {
        assert(0 <= i and i < m_n);
        const auto [b, w] = I2B(i);
        m_blocks[b] ^= (1_i64 << w);
        return *this;
    }
    /**
     * @brief 立っている最初のbit位置
     * 
     * @return int bit位置
     */
    int findFirst() const
    {
        for (int b : rep(m_bn)) {
            if (m_blocks[b] == 0) { continue; }
            const int w = order2(m_blocks[b]);
            const int i = B2I(b, w);
            return std::ranges::min(i, size());
        }
        return size();
    }
    /**
     * @brief i bit目より後ろで立っている最初のbit位置
     * 
     * @param pi 基準位置
     * @return int bit位置
     */
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
            const int w = order2(x);
            const int i = B2I(b, w);
            return std::ranges::min(i, size());
        }
        return size();
    }
    /**
     * @brief 全bitを立てる
     * 
     * @return DynamicBitset& self
     */
    DynamicBitset& setAll()
    {
        fillAll(m_blocks, LIMMAX<T>), trunk();
        return *this;
    }
    /**
     * @brief 全bitを下げる
     * 
     * @return DynamicBitset& self
     */
    DynamicBitset& resetAll()
    {
        fillAll(m_blocks, 0);
        return *this;
    }
    /**
     * @brief 立っているbit数取得
     * 
     * @return int 立っているbit数
     */
    int count() const
    {
        int ans = 0;
        for (int b : rep(m_bn)) { ans += std::popcount(m_blocks[b]); }
        return ans;
    }
    /**
     * @brief bit長
     * 
     * @return int bit長
     */
    int size() const { return m_n; }
#ifdef HOGEPACHI
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
#endif
private:
    static constexpr Pair<int, int> I2B(int i) { return {i / B, i % B}; }
    static constexpr int B2I(int b, int w) { return b * B + w; }
    void trunk() { m_blocks.back() &= ~bitMask(m_n % B); }
    int m_n;
    int m_bn;
    Vec<T> m_blocks;
};
