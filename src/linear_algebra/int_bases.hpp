#pragma once
#include "../common.hpp"
/**
 * @brief F_2上64次元ベクトル集合の基底管理
 */
class IntBases
{
    static constexpr int D = sizeof(u64) * 8;
public:
    /**
     * @brief コンストラクタ
     */
    IntBases() { mdSeqFill(m_vis, -1); }
    /**
     * @brief 元vを追加する
     * 
     * @param v 
     * @return true Rankが増えた
     * @return false Rankが変わらず(vがもともと線形従属)
     */
    bool add(u64 v)
    {
        auto reduced_v = v;
        u64 mask       = 0;
        for (int i : rep(m_reduced_bases.size())) {
            if (chmin(reduced_v, reduced_v ^ m_reduced_bases[i])) { mask ^= m_masks[i]; }
        }
        if (reduced_v) {
            const int vi = m_reduced_bases.size();
            mask ^= (1_u64 << vi);
            m_orig_bases.push_back(v), m_reduced_bases.push_back(reduced_v);
            m_masks.push_back(mask);
            for (int j : per(D)) {
                if (isBitOn(reduced_v, j)) {
                    m_vis[j] = vi;
                    break;
                }
            }
            return true;
        }
        return false;
    }
    /**
     * @brief 基底をなす元の数列
     * @attention decomp結果と組み合わせる想定
     * 
     * @return const Vec<u64>& 基底をなす元の数列
     */
    const Vec<u64>& origBases() const { return m_orig_bases; }
    /**
     * @brief 基底を掃き出した数列
     * 
     * @return const Vec<u64>& 基底を掃き出した数列
     */
    const Vec<u64>& reducedBases() const { return m_reduced_bases; }
    /**
     * @brief 階数
     * 
     * @return int 階数
     */
    int rank() const { return m_reduced_bases.size(); }
    /**
     * @brief 元vを基底の線形結合で表す
     * 
     * @param v 
     * @return Opt<T> 線形結合の係数 (vがspanに含まれてない場合は nullopt)
     */
    Opt<u64> decomp(u64 v) const
    {
        u64 mask = 0;
        for (int j : irange(D - 1, -1, -1)) {
            if (isBitOn(v, j)) {
                if (m_vis[j] == -1) { return std::nullopt; }
                const int vi = m_vis[j];
                v ^= m_reduced_bases[vi];
                mask ^= m_masks[vi];
            }
        }
        assert(v == 0);
        return mask;
    }
private:
    Vec<u64> m_orig_bases;     // 元の入力による基底
    Vec<u64> m_reduced_bases;  // 縮約された基底
    Vec<u64> m_masks;          // m_reduced[i]をm_origで作るための係数
    Arr<int, D> m_vis;
};
