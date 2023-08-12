#pragma once
#include "../common.hpp"
#include "../graph/strongly_connected_components.hpp"
#include "../utility/nd_vec.hpp"
#include "../utility/dynamic_bitset.hpp"

/**
 * @brief 2-SAT ソルバー
 * @attention 変数X_i の指定は 1-indexed (i=1,2,...,N)
 *            項X_i は i で、項(\lnot X_i) は -i で指定
 */
class TwoSat
{
public:
    /**
     * @brief コンストラクタ
     * 
     * @param N 変数の数
     */
    TwoSat(int N) : m_X{N}, m_V{N * 2}, m_g{m_V} {}
    /**
     * @brief 節 (x \lor y) を追加
     *
     * @param x 項1
     * @param y 項2
     */
    void addClause(int x, int y)
    {
        assert(x != 0 and std::abs(x) <= m_X);
        assert(y != 0 and std::abs(y) <= m_X);
        m_clauses.push_back({x, y});
        m_g.addEdge(X2V(-y), X2V(x));
        m_g.addEdge(X2V(-x), X2V(y));
    }
    /**
     * @brief 2-SATの解を一つ返す
     * 
     * @return Opt<Vec<bool>> 解 (解なしの場合は std::nullopt)
     */
    Opt<Vec<bool>> findSolution() const
    {
        Vec<bool> ts(m_X + 1);
        const StronglyConnectedComponents scc{m_g};
        for (int x : irange(1, m_X + 1)) {
            const int v = X2V(x), nv = X2V(-x);
            if (scc[v] == scc[nv]) { return std::nullopt; }
            ts[x] = (scc[v] > scc[nv]);
        }
        return ts;
    }
    /**
     * @brief 2-SATの解を列挙する
     * 
     * @param K 列挙の打ち切り個数
     * @return Vec<Vec<bool>> 解の列
     */
    Vec<Vec<bool>> enumSolutions(int K = -1) const
    {
        const StronglyConnectedComponents scc{m_g};
        const int C       = scc.cnum();
        const auto groups = scc.groups();
        Vec<int> antis(C);
        for (int c : rep(C)) {
            const int u  = groups[c].back();
            const int nu = (u < m_X ? u + m_X : u - m_X);
            antis[c]     = scc[nu];
            if (antis[c] == c) { return {}; }
        }
        auto belows = ndVec({C}, DynamicBitset{C});
        for (int c : per(C)) {
            belows[c].set(c);
            for (int u : groups[c]) {
                for (int v : m_g[u]) { belows[c] |= belows[scc[v]]; }
            }
        }

        Vec<Vec<bool>> sols;
        Fix([&](auto self, int c, const DynamicBitset& T) -> void {
            if ((int)sols.size() == K) { return; }
            if (c == C) {
                Vec<bool> sol(m_X + 1);
                for (int c : rep(C)) {
                    for (int u : groups[c]) {
                        const int x = V2X(u);
                        if (x > 0) { sol[x] = T.test(c); }
                    }
                }
                sols.push_back(sol);
                return;
            }
            const int nc = antis[c];
            if (T.test(c) or T.test(nc)) {
                self(c + 1, T);
            } else {
                for (int b : rep(2)) {
                    const int c0 = (b == 0 ? c : nc);
                    const int c1 = (b == 0 ? nc : c);
                    if (belows[c1].test(c0)) { continue; }
                    const auto nT = T | belows[c1];
                    self(c + 1, nT);
                }
            }
        })(0, DynamicBitset{C});
        return sols;
    }
private:
    int X2V(int x) const { return (x > 0 ? x - 1 : -x - 1 + m_X); }
    int V2X(int v) const { return v < m_X ? v + 1 : -(v - m_X + 1); }
    int m_X, m_V;
    Graph<int> m_g;
    Vec<Pair<int, int>> m_clauses;
};
