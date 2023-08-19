#pragma once
#include "../common.hpp"
/**
 * @brief [N]->[N] 関数のダブリング
 *
 * @tparam Monoid モノイド
 */
template<typename Monoid> class Doubling
{
    using T = typename Monoid::T;
public:
    /**
     * @brief コンストラクタ
     * 
     * @param f [N]->[N]+{-1,N} の関数(-1,N は無効値。f(-1)=-1,f(N)=N として扱う)
     * @param w v->f(v)の辺に対する重み関数(w(-1)=0, w(N)=0 として扱う)
     *          以下 v->...->f^k(v) の 重み和を dist(v,f^(v)) と書く
     */
    Doubling(const Vec<int>& f, const Vec<T>& w) : m_N{(int)f.size()}
    {
        assert(f.size() == w.size());
        assert(std::ranges::all_of(f, [&](int x) { return -1 <= x and x <= m_N; }));
        Vec<int> nexts{0};
        seqConcat(nexts, f), nexts.push_back(m_N);
        Vec<T> ws{Monoid::e()};
        m_nextss.push_back(nexts), m_wss.push_back(ws);
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
            const auto& pws    = m_wss.back();
            Vec<int> nnexts(m_N + 2);
            Vec<T> nws(m_N + 2);
            for (int i : rep(m_N + 2)) { nnexts[i] = pnexts[pnexts[i]], nws[i] = pws[i] + pws[pnexts[i]]; }
            m_nextss.push_back(nnexts), m_wss.push_back(nws);
        }
    }
    /**
     * @brief {f^K(x),dist(x,f^K(x))}
     * 
     * @param x
     * @param K
     * @return Pair<int,T> {f^K(x), dist(x,f^K(x))}
     */
    Pair<int, T> kthNext(int x, i64 K)
    {
        assert(0 <= x and x < m_N);
        assert(K >= 0);
        x++;
        resize(K);
        T D = Monoid::e();
        for (int d : rep(m_nextss.size())) {
            if (isBitOn(K, d)) { D = Monoid::merge(D, m_wss[d][x]), x = m_nextss[d][x]; }
        }
        return {x - 1, D};
    }
    /**
     * @brief pred(f^k(x), dist(x,f^k(x))) == True となる最小の k
     * 
     * @param x 
     * @param Ksup 0<=k<=Kmax で探す
     * @param pred 判定関数 (x=-1,Nも来るので注意)
     * @return i64 最小の k (Trueになる k が存在しない場合は Kmax+1)
     */
    i64 distance(int x, const i64 Kmax, auto pred) const
    {
        assert(0 <= x and x < m_N);
        assert(0 <= Kmax);
        x++;
        resize(Kmax);
        T D = Monoid::e();
        if (pred(x - 1, D)) { return 0; }
        const int lg = (int)m_nextss.size();
        i64 ans      = 0;
        for (int d : per(lg)) {
            const int np = m_nextss[d][x];
            const T nD   = Monoid::merge(D, m_wss[d][x]);
            if (ans + (1_i64 << d) <= Kmax and not pred(np - 1, nD)) {
                x = np, D = nD;
                ans += (1_i64 << d);
            }
        }
        return ans + 1;
    }
private:
    int m_N;
    Vec<Vec<int>> m_nextss;  // m_nextss[i][x] = xの2^i手先
    Vec<Vec<int>> m_wss;     // m_wss[i][x] = xの2^i手先までの重み
};
