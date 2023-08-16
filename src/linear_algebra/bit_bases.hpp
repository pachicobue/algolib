#pragma once
#include "../common.hpp"
/**
 * @brief F_2上D次元ベクトル集合の基底管理
 * 
 * @tparam D 次元
 */
template<int D> class BitBases
{
    using T = BSet<D>;
public:
    /**
     * @brief コンストラクタ
     */
    BitBases() { fillAll(m_vis, -1); }
    /**
     * @brief 元vを追加する
     * 
     * @param v 
     * @return true Rankが増えた
     * @return false Rankが変わらず(vがもともと線形従属)
     */
    bool add(const T& v)
    {
        auto reduced = v;
        T mask       = 0;
        auto less    = [&](const T& v1, const T& v2) -> bool {
            const int i = (v1 ^ v2)._Find_first();
            return v2[i];
        };
        for (int i : rep(m_reduced_bases.size())) {
            if (less(reduced ^ m_reduced_bases[i], reduced)) {
                reduced ^= m_reduced_bases[i];
                mask ^= m_masks[i];
            }
        }
        if (reduced.count()) {
            const int vi = m_reduced_bases.size();
            mask.set(vi);
            m_orig_bases.push_back(v);
            m_reduced_bases.push_back(reduced);
            m_masks.push_back(mask);
            for (int j : irange(D - 1, -1, -1)) {
                if (reduced[j]) {
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
     * @return const Vec<T>& 基底をなす元の数列
     */
    const Vec<T>& origBases() const { return m_orig_bases; }
    /**
     * @brief 基底を掃き出した数列
     * 
     * @return const Vec<T>& 基底を掃き出した数列
     */
    const Vec<T>& reducedBases() const { return m_reduced_bases; }
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
    Opt<T> decomp(T v) const
    {
        T mask = 0;
        for (int j : per(D)) {
            if (v[j]) {
                if (m_vis[j] == -1) { return std::nullopt; }
                const int vi = m_vis[j];
                v ^= m_reduced_bases[vi];
                mask ^= m_masks[vi];
            }
        }
        assert(v.count() == 0);
        return mask;
    }
private:
    Vec<T> m_orig_bases;     // 元の入力による基底
    Vec<T> m_reduced_bases;  // 縮約された基底
    Vec<T> m_masks;          // m_reduced[i]をm_origで作るための係数
    Arr<int, D> m_vis;
};
