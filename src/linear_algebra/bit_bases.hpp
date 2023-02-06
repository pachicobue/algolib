#pragma once
#include "../common.hpp"
template<int D>
class BitBases
{
    using T = BSet<D>;

public:
    BitBases() { fillAll(m_vis, -1); }
    bool add(const T& v_)
    {
        auto v = v_;
        T mask = 0;
        auto less = [&](const T& v1, const T& v2) -> bool {
            const int i = (v1 ^ v2)._Find_first();
            return v2[i];
        };
        for (int i : rep(m_reduced_bases.size())) {
            if (less(v ^ m_reduced_bases[i], v)) {
                v ^= m_reduced_bases[i];
                mask ^= m_masks[i];
            }
        }
        if (v.count()) {
            const int vi = m_reduced_bases.size();
            mask.set(vi);
            m_orig_bases.push_back(v_);
            m_reduced_bases.push_back(v);
            m_masks.push_back(mask);
            for (int j : irange(D - 1, -1, -1)) {
                if (v[j]) {
                    m_vis[j] = vi;
                    break;
                }
            }
            return true;
        }
        return false;
    }
    const Vec<T>& origBases() const { return m_orig_bases; }
    const Vec<T>& reducedBases() const { return m_reduced_bases; }
    int rank() const { return m_reduced_bases.size(); }
    Pair<bool, T> decomp(T v) const
    {
        T mask = 0;
        for (int j : per(D)) {
            if (v[j]) {
                if (m_vis[j] == -1) { return {false, T{}}; }
                const int vi = m_vis[j];
                v ^= m_reduced_bases[vi];
                mask ^= m_masks[vi];
            }
        }
        assert(v.count() == 0);
        return {true, mask};
    }

private:
    Vec<T> m_orig_bases;     // 元の入力による基底
    Vec<T> m_reduced_bases;  // 縮約された基底
    Vec<T> m_masks;          // m_reduced[i]をm_origで作るための係数
    Arr<int, D> m_vis;
};
