#pragma once
#include "../common.hpp"
/**
 * @brief グラフ型
 * 
 * @tparam T コスト型
 */
template<typename T = int>
    requires(not std::is_same_v<T, bool>)
class Graph
{
public:
    /**
     * @brief 辺情報
     * @attention eidは g.edge() の引数に使用できる
     */
    struct Edge
    {
        Edge() = default;
        Edge(int e, int t, const T& c) : eid{e}, to{t}, cost{c} {}
        int eid;  // 辺番号
        int to;
        T cost;
        operator int() const { return to; }
    };
    /**
     * @brief コンストラクタ
     * 
     * @param N 頂点数
     */
    Graph(int N) : m_V{N}, m_lists(N), m_edges{} {}
    /**
     * @brief 辺追加 (コスト1)
     * 
     * @param u 
     * @param v 
     * @param bi 無向辺かどうか
     */
    void addEdge(int u, int v, bool bi = false)
        requires std::is_same_v<T, int>
    {
        assert(0 <= u and u < m_V);
        assert(0 <= v and v < m_V);
        m_edges.push_back({u, v, 1});
        m_lists[u].push_back({m_E, v, 1});
        if (bi) { m_lists[v].push_back({m_E, u, 1}); }
        m_E++;
    }
    /**
     * @brief 辺追加 (任意コスト)
     * 
     * @param u 
     * @param v 
     * @param c コスト
     * @param bi 無向辺かどうか
     */
    void addEdge(int u, int v, T c, bool bi = false)
    {
        assert(0 <= u and u < m_V);
        assert(0 <= v and v < m_V);
        m_edges.push_back({u, v, c});
        m_lists[u].push_back({m_E, v, c});
        if (bi) { m_lists[v].push_back({m_E, u, c}); }
        m_E++;
    }
    /**
     * @brief 頂点u につながっている辺列 (const)
     * 
     * @param u 
     * @return const Vec<Edge>& 辺列
     */
    const Vec<Edge>& operator[](int u) const
    {
        assert(0 <= u and u < m_V);
        return m_lists[u];
    }
    /**
     * @brief 頂点u につながっている辺列 (mutable)
     * 
     * @param u 
     * @return const Vec<Edge>& 辺列
     */
    Vec<Edge>& operator[](const int u)
    {
        assert(0 <= u and u < m_V);
        return m_lists[u];
    }
    /**
     * @brief 部分木サイズ列
     * @attention 木 限定
     * 
     * @param R 根
     * @return Vec<int> 部分木サイズ列
     */
    Vec<int> sizes(int R = 0) const
    {
        Vec<int> Ans(V(), 1);
        Fix([&](auto self, int u, int p) -> void {
            for (int v : m_lists[u]) {
                if (v == p) { continue; }
                self(v, u);
                Ans[u] += Ans[v];
            }
        })(R, -1);
        return Ans;
    }
    /**
     * @brief 深さ列
     * @attention 木 限定
     * 
     * @param R 根
     * @return Vec<T> 深さ列
     */
    Vec<T> depths(int R = 0) const
    {
        Vec<T> Ans(V(), 0);
        Fix([&](auto self, int u, int p) -> void {
            for (const auto& [v, c] : m_lists[u] | ToC) {
                if (v == p) { continue; }
                Ans[v] = Ans[u] + c;
                self(v, u);
            }
        })(R, -1);
        return Ans;
    }
    /**
     * @brief 親頂点列
     * @attention 木 限定
     * 
     * @param R 根
     * @return Vec<int> 親頂点列 (根の親は -1 とする)
     */
    Vec<int> parents(int R = 0) const
    {
        Vec<int> Ans(V(), -1);
        Fix([&](auto self, int u, int p) -> void {
            for (int v : m_lists[u]) {
                if (v == p) { continue; }
                Ans[v] = u;
                self(v, u);
            }
        })(R, -1);
        return Ans;
    }
    /**
     * @brief 辺取得
     * 
     * @param eid 辺番号
     * @return const Edge& 辺情報
     */
    const Edge& edge(int eid) const
    {
        assert(0 <= eid and eid < m_E);
        return m_edges[eid];
    }
    /**
     * @brief 頂点数
     * 
     * @return  int 頂点数
     */
    int V() const { return m_V; }
    /**
     * @brief 辺数
     * 
     * @return int 辺数
     */
    int E() const { return m_E; }
    /**
     * @brief 辺列から コスト 情報を削ぐ
     * @attention for(const auto [eid,to]: g[u]|g.ETo()) と使う
     */
    static constexpr auto ETo = std::views::transform([](const Edge& e) { return makePair(e.eid, e.to); });
    /**
     * @brief 辺列から 辺番号 情報を削ぐ
     * @attention for(const auto [to,cost]: g[u]|g.ToC()) と使う
     */
    static constexpr auto ToC = std::views::transform([](const Edge& e) { return makePair(e.to, e.cost); });
private:
    int m_V, m_E;
    Vec<Vec<Edge>> m_lists;
    Vec<Edge> m_edges;
};
