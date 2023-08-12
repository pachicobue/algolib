#pragma once
#include "../common.hpp"
/**
 * @brief [N]->[N] 関数のダブリング
 */
class Doubling
{
public:
    /**
     * @brief コンストラクタ
     * 
     * @param f [N]->[N]+{-1,N} の関数(-1,N は無効値。f(-1)=-1,f(N)=N として扱う)
     */
    Doubling(const Vec<int>& f) : m_N{(int)f.size()}
    {
        assert(std::ranges::all_of(f, [&](int x) { return -1 <= x and x <= m_N; }));
        m_nextss.push_back(f);
    }
    /**
     * @brief ダブリングテーブルを拡張する
     * 
     * @param KMax f^{KMax} が計算できるサイズまで拡張
     */
    void resize(i64 KMax)
    {
        if (KMax <= 1) { return; }
        const int L = ceilLog2(KMax) + 1;
        while (std::ssize(m_nextss) < L) {
            const auto& pnexts = m_nextss.back();
            Vec<int> nnexts(m_N);
            for (int i : rep(m_N)) { nnexts[i] = pnexts[pnexts[i]]; }
            m_nextss.push_back(nnexts);
        }
    }
    /**
     * @brief f^K(x)を求める
     * 
     * @param x
     * @param K
     * @return int f^K(x)
     */
    int kthNext(int x, i64 K)
    {
        assert(K >= 0);
        resize(K);
        for (int d : rep(m_nextss.size())) {
            if (0 <= x and x < m_N) {
                if (isBitOn(K, d)) { x = m_nextss[d][x]; }
            }
        }
        return x;
    }
    /**
     * @brief pred(f^k(x)) == True となる最小の k
     * 
     * @param x 
     * @param pred 判定関数
     * @return i64 最小の k (Trueになる k が存在しない場合は N)
     */
    i64 distance(int x, auto pred) const
    {
        if (pred(x)) { return 0; }
        const int lg = m_nextss.size();
        i64 ans      = 0;
        for (int d : per(lg)) {
            const int np = m_nextss[d][x];
            if (not pred(np)) {
                x = np;
                ans += (1_i64 << d);
            }
        }
        if (pred(m_nextss[0][x])) {
            return ans + 1;
        } else {
            return -1;
        }
    }
private:
    int m_N;
    Vec<Vec<int>> m_nextss;  // m_nextss[i][x] = f^{2^i}(x)
};
