#pragma once
#include "../common.hpp"
#include "../utility/int_nthroot.hpp"
/**
 * @brief Mo's algorithm
 * @attention (0,0) 開始で各 (x,y) を通るように1マスずつ移動していく
 */
class Mo
{
public:
    /**
     * @brief コンストラクタ
     * 
     * @param xs ターミナルのx座標
     * @param ys ターミナルのy座標
     */
    Mo(const Vec<int>& xs, const Vec<int>& ys) : m_xs{xs}, m_ys{ys}, m_is{iotaVec(m_xs.size())}
    {
        assert(xs.size() == ys.size());
        assert(not xs.empty());
        const auto [mx, Mx] = std::ranges::minmax(xs);
        const auto [my, My] = std::ranges::minmax(ys);
        const int L         = std::ranges::max(Mx - mx, My - my);
        const int B         = std::ranges::max(1, L / (int)intSqrt(xs.size()));
        seqSort(m_is, [&](int i, int j) {
            const int bi = xs[i] / B, bj = xs[j] / B;
            return (bi == bj) ? ys[i] < ys[j] : bi < bj;
        });
    }
    /**
     * @brief 全クエリ処理
     * @note なるべく x <= y を保つように動く
     * 
     * @param right (x,y)->(x+1,y) への移動処理
     * @param left  (x,y)->(x-1,y) への移動処理
     * @param down  (x,y)->(x,y+1) への移動処理
     * @param up    (x,y)->(x,y-1) への移動処理
     * @param sol   ターミナル番号 i のクエリ処理
     */
    void solve(auto right, auto left, auto down, auto up, auto sol)
    {
        int x = 0, y = 0;
        for (int ii : rep(m_xs.size())) {
            const int i  = m_is[ii];
            const int nx = m_xs[i], ny = m_ys[i];
            for (; x > nx; x--) { left(x, y); }
            for (; y < ny; y++) { down(x, y); }
            for (; x < nx; x++) { right(x, y); }
            for (; y > ny; y--) { up(x, y); }
            sol(i);
        }
    }
private:
    Vec<int> m_xs, m_ys;
    Vec<int> m_is;
};
