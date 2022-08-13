#pragma once
#include "../common.hpp"
template<typename T = u64>
class IntBases
{
    static constexpr int D = sizeof(T) * 8;

public:
    IntBases() { fillAll(m_vis, -1); }
    bool add(const T& v)
    {
        auto reduced_v = v;
        T mask = 0;
        for (int i : rep(m_reduced_bases.size())) {
            if (chmin(reduced_v, reduced_v ^ m_reduced_bases[i])) { mask ^= m_masks[i]; }
        }
        if (reduced_v) {
            const int vi = m_reduced_bases.size();
            mask ^= (T{1} << vi);
            m_orig_bases.push_back(v), m_reduced_bases.push_back(reduced_v);
            m_masks.push_back(mask);
            for (int j : per(D)) {
                if (btest(reduced_v, j)) {
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
        for (int j : irange(D - 1, -1, -1)) {
            if (btest(v, j)) {
                if (m_vis[j] == -1) { return {false, 0}; }
                const int vi = m_vis[j];
                v ^= m_reduced_bases[vi];
                mask ^= m_masks[vi];
            }
        }
        assert(v == 0);
        return {true, mask};
    }

private:
    Vec<T> m_orig_bases;     // 元の入力による基底
    Vec<T> m_reduced_bases;  // 縮約された基底
    Vec<T> m_masks;          // m_reduced[i]をm_origで作るための係数
    Arr<int, D> m_vis;
};
