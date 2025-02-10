#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <compare>
#include "../internal.hpp"
/**
 * @brief Vec<u64> ベースの bitset
 * @attention 実行時にサイズが決まる以外は普通のbitsetと同じ(resizeとかは非サポート)
 * @attention operatorは同じbit長のbitset同士のみサポート
 */
class DynamicBitset {
    using T = u64;
    static constexpr int B = sizeof(T) * 8;
public:
    /**
     * @brief コンストラクタ
     */
    DynamicBitset() {
    }
    /**
     * @brief コンストラクタ
     *
     * @param N bit長
     */
    DynamicBitset(int N)
        : m_n{N}, m_bn{(int)ceilDiv(N, B)}, m_blocks(m_bn, 0) {
    }
    /**
     * @brief コンストラクタ
     *
     * @param S 0/1文字列
     */
    DynamicBitset(const Str& S)
        : m_n{(int)S.size()}, m_bn{(int)ceilDiv(m_n, B)}, m_blocks(m_bn, 0) {
        assert(std::ranges::all_of(S, [](char c) {
            return c == '0' or c == '1';
        }));
        for (int i : rep(m_bn)) {
            const int r = m_n - i * B, l = std::max(0, r - B);
            T x = 0;
            for (int j : irange(l, r)) {
                x |= (T)(S[j] - '0') << (r - j - 1);
            }
            m_blocks[i] = x;
        }
    }
    /**
     * @brief bitset同士のAND
     *
     * @param bs1
     * @param bs2
     * @return DynamicBitset& self
     */
    friend auto operator&=(DynamicBitset& bs1, const DynamicBitset& bs2) -> DynamicBitset& {
        assert(bs1.size() == bs2.size());
        for (int b : rep(bs1.m_bn)) {
            bs1.m_blocks[b] &= bs2.m_blocks[b];
        }
        return bs1;
    }
    /**
     * @brief bitset同士のOR
     *
     * @param bs1
     * @param bs2
     * @return DynamicBitset& self
     */
    friend auto operator|=(DynamicBitset& bs1, const DynamicBitset& bs2) -> DynamicBitset& {
        assert(bs1.size() == bs2.size());
        for (int b : rep(bs1.m_bn)) {
            bs1.m_blocks[b] |= bs2.m_blocks[b];
        }
        return bs1;
    }
    /**
     * @brief bitset同士のXOR
     *
     * @param bs1
     * @param bs2
     * @return DynamicBitset& self
     */
    friend auto operator^=(DynamicBitset& bs1, const DynamicBitset& bs2) -> DynamicBitset& {
        assert(bs1.size() == bs2.size());
        for (int b : rep(bs1.m_bn)) {
            bs1.m_blocks[b] ^= bs2.m_blocks[b];
        }
        return bs1;
    }
    /**
     * @brief bitsetの左Shift
     * @attention bit長は変わらない
     *
     * @param bs
     * @param s シフト幅 (非負)
     * @return DynamicBitset& self
     */
    friend auto operator<<=(DynamicBitset& bs, int s) -> DynamicBitset& {
        assert(s >= 0);
        if (s >= bs.size()) {
            return bs.resetAll();
        }
        if (s == 0) {
            return bs;
        }
        const auto [sb, sw] = I2B(s);
        for (int b : per(bs.m_bn)) {
            const T m0 = (b < sb ? T{0} : bs.m_blocks[b - sb]);
            const T m1 = (b <= sb ? T{0} : bs.m_blocks[b - sb - 1]);
            bs.m_blocks[b] = (m0 << sw) | (sw == 0 ? T{0} : (m1 >> (B - sw)));
        }
        return bs.trunk(), bs;
    }
    /**
     * @brief bitsetの右Shift
     * @attention bit長は変わらない
     *
     * @param bs
     * @param s シフト幅 (非負)
     * @return DynamicBitset& self
     */
    friend auto operator>>=(DynamicBitset& bs, int s) -> DynamicBitset& {
        assert(s >= 0);
        if (s >= bs.size()) {
            return bs.resetAll();
        }
        if (s == 0) {
            return bs;
        }
        const auto [sb, sw] = I2B(s);
        for (int b : rep(bs.m_bn)) {
            const T m0 = (b + sb >= bs.m_bn ? T{0} : bs.m_blocks[b + sb]);
            const T m1 = (b + sb + 1 >= bs.m_bn ? T{0} : bs.m_blocks[b + sb + 1]);
            bs.m_blocks[b] = (m0 >> sw) | (sw == 0 ? T{0} : (m1 << (B - sw)));
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
    friend auto operator&(const DynamicBitset& bs1, const DynamicBitset& bs2) -> DynamicBitset {
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
    friend auto operator|(const DynamicBitset& bs1, const DynamicBitset& bs2) -> DynamicBitset {
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
    friend auto operator^(const DynamicBitset& bs1, const DynamicBitset& bs2) -> DynamicBitset {
        auto ans = bs1;
        return ans ^= bs2;
    }
    /**
     * @brief bitsetの左Shift
     * @attention bit長は変わらない
     *
     * @param bs
     * @param s シフト幅 (非負)
     * @return DynamicBitset Shift結果
     */
    friend auto operator<<(const DynamicBitset& bs, int s) -> DynamicBitset {
        auto ans = bs;
        return ans <<= s;
    }
    /**
     * @brief bitsetの右Shift
     * @attention bit長は変わらない
     *
     * @param bs
     * @param s シフト幅 (非負)
     * @return DynamicBitset Shift結果
     */
    friend auto operator>>(const DynamicBitset& bs, int s) -> DynamicBitset {
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
    friend bool operator==(const DynamicBitset& bs1, const DynamicBitset& bs2) {
        return bs1.m_blocks == bs2.m_blocks;
    }
    /**
     * @brief bitset同士の一貫比較
     *
     * @param bs1
     * @param bs2
     * @return 一貫比較結果
     */
    friend auto operator<=>(const DynamicBitset& bs1, const DynamicBitset& bs2) {
        assert(bs1.size() == bs2.size());
        for (int i : per(bs1.m_bn)) {
            if (bs1.m_blocks[i] != bs2.m_blocks[i]) {
                return bs1.m_blocks[i] <=> bs2.m_blocks[i];
            }
        }
        return std::strong_ordering::equivalent;
    }
    /**
     * @brief bitset全体のNOT
     *
     * @param bs
     * @return DynamicBitset NOT結果
     */
    friend auto operator~(const DynamicBitset& bs) -> DynamicBitset {
        auto ans = bs;
        for (int i : rep(bs.m_bn)) {
            ans.m_blocks[i] = ~ans.m_blocks[i];
        }
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
    auto test(int i) const -> bool {
        assert(0 <= i and i < m_n);
        const auto [b, w] = I2B(i);
        return isBitOn(m_blocks[b], w);
    }
    /**
     * @brief i bit目を指定の値にする
     *
     * @param i bit位置
     * @param b 0/1
     * @return DynamicBitset& self
     */
    auto set(int i, bool b) -> DynamicBitset& {
        return (b ? set(i) : reset(i));
    }
    /**
     * @brief i bit目を立てる
     *
     * @param i bit位置
     * @return DynamicBitset& self
     */
    auto set(int i) -> DynamicBitset& {
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
    auto reset(int i) -> DynamicBitset& {
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
    auto flip(int i) -> DynamicBitset& {
        assert(0 <= i and i < m_n);
        const auto [b, w] = I2B(i);
        m_blocks[b] ^= (1_i64 << w);
        return *this;
    }
    /**
     * @brief 立っている最初のbit位置
     * @attention 存在しない場合は size() が返る
     *
     * @return int bit位置
     */
    auto findFirst() const -> int {
        for (int b : rep(m_bn)) {
            if (m_blocks[b] == 0) {
                continue;
            }
            const int w = order2(m_blocks[b]);
            const int i = B2I(b, w);
            return std::ranges::min(i, size());
        }
        return size();
    }
    /**
     * @brief i bit目より後ろで立っている最初のbit位置
     * @attention 存在しない場合は size() が返る
     *
     * @param pi 基準位置
     * @return int bit位置
     */
    auto findNext(int pi) const -> int {
        assert(pi < m_n);
        if (pi < 0) {
            return findFirst();
        }
        pi++;
        if (pi == m_n) {
            return size();
        }
        const auto [pb, pw] = I2B(pi);
        for (int b : irange(pb, m_bn)) {
            T x = m_blocks[b];
            if (b == pb) {
                x &= ~bitMask(0, pw);
            }
            if (x == 0) {
                continue;
            }
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
    auto setAll() -> DynamicBitset& {
        mdSeqFill(m_blocks, LIMMAX<T>), trunk();
        return *this;
    }
    /**
     * @brief 全bitを下げる
     *
     * @return DynamicBitset& self
     */
    auto resetAll() -> DynamicBitset& {
        mdSeqFill(m_blocks, 0);
        return *this;
    }
    /**
     * @brief str
     *
     * @return bit列を表す0/1文字列
     */
    auto str() const -> Str {
        Str S(size(), '0');
        for (int i : rep(size())) {
            const auto [b, w] = I2B(i);
            if (isBitOn(m_blocks[b], w)) {
                S[i] = '1';
            }
        }
        return seqReverse(S), S;
    }
    /**
     * @brief 立っているbit数取得
     *
     * @return int 立っているbit数
     */
    auto count() const -> int {
        int ans = 0;
        for (int b : rep(m_bn)) {
            ans += std::popcount(m_blocks[b]);
        }
        return ans;
    }
    /**
     * @brief bit長
     *
     * @return int bit長
     */
    auto size() const -> int {
        return m_n;
    }
#ifdef HOGEPACHI
    friend auto operator<<(Ostream& os, const DynamicBitset& bs) -> Ostream& {
        return os << bs.str();
    }
#endif
private:
    static constexpr auto I2B(int i) -> Pair<int, int> {
        return {i / B, i % B};
    }
    static constexpr auto B2I(int b, int w) -> int {
        return b * B + w;
    }
    auto trunk() -> void {
        m_blocks.back() &= bitMask(m_n % B);
    }
    int m_n;
    int m_bn;
    Vec<T> m_blocks;
};
