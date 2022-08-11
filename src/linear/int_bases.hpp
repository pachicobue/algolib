#pragma once
#include "../common.hpp"
template<typename T = u64>
class IntBases
{
    static constexpr int D = sizeof(T) * 8;

public:
    IntBases() { std::fill(m_d2vis.begin(), m_d2vis.end(), -1); }
    IntBases(const Vec<T>& vs)
    {
        std::fill(m_d2vis.begin(), m_d2vis.end(), -1);
        for (const T& v : vs) { add(v); }
    }
    bool add(const T& v_)
    {
        auto v = v_;
        T mask = 0;
        for (int i : rep(m_bases.size())) {
            if (chmin(v, v ^ m_bases[i])) { mask ^= m_masks[i]; }
        }
        if (v) {
            const int vi = m_bases.size();
            mask ^= (T{1} << vi);
            m_spans.push_back(v_);
            m_bases.push_back(v);
            m_masks.push_back(mask);
            for (int j : irange(D - 1, -1, -1)) {
                if (btest(v, j)) {
                    m_d2vis[j] = vi;
                    break;
                }
            }
            return true;
        }
        return false;
    }
    const Vec<T>& bases() const { return m_bases; }
    int rank() const { return m_bases.size(); }
    T operator[](int i) const { return m_spans[i]; }
    Pair<bool, T> decomp(T v) const
    {
        T mask = 0;
        for (int j : irange(D - 1, -1, -1)) {
            if (btest(v, j)) {
                if (m_d2vis[j] == -1) { return {false, 0}; }
                const int vi = m_d2vis[j];
                v ^= m_bases[vi];
                mask ^= m_masks[vi];
            }
        }
        assert(v == 0);
        return {true, mask};
    }

private:
    Vec<T> m_spans;  // 元の入力による基底
    Vec<T> m_bases;  // 縮約された基底
    Vec<T> m_masks;  // m_bases[i]がm_spansのうち何番目で出来ているか
    Arr<int, D> m_d2vis;
};
