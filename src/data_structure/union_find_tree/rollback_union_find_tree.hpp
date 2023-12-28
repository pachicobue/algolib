#pragma once
#include "../../common.hpp"
/**
 * @brief Undo可能 UnionFind木
 */
class RollbackUnionFindTree
{
    static constexpr auto NOP1 = [](int) {};
    static constexpr auto NOP2 = [](int, int) {};
public:
    /**
     * @brief コンストラクタ
     * 
     * @param N 要素数
     */
    RollbackUnionFindTree(int N) : m_V{N}, m_infos(m_V, -1), m_diffs{} {}
    /**
     * @brief iを含む成分の代表元
     * 
     * @param i 
     * @return int 代表元
     */
    int find(int i) const
    {
        if (m_infos[i] < 0) {
            return i;
        } else {
            return find(m_infos[i]);
        }
    }
    /**
     * @brief SiとSjを併合する (付加情報を管理するケース)
     * 
     * @param i 
     * @param j 
     * @param snap snap(i): Siの状態を保存する操作 (undo関数の restore と対になる)
     * @param merge merge(i,j): SiをSjに併合する際の操作 (向きがあるので注意)
     * @param add add(i): Siの「スコア」を加算する
     * @param del del(i): Siの「スコア」を減算する
     * @return true 意味のある併合が発生
     * @return false 元々同じ成分だった
     */
    bool unite(int i, int j, auto snap, auto merge, auto add, auto del)
    {
        i = find(i), j = find(j);
        m_diffs.push_back({i, m_infos[i]}), m_diffs.push_back({j, m_infos[j]});
        snap(i), snap(j);
        if (size(i) > size(j)) { std::ranges::swap(i, j); }
        del(i);
        if (i != j) {
            del(j);
            m_infos[j] += m_infos[i];
            m_infos[i] = j;
        }
        merge(i, j);
        add(j);
        return (i != j);
    }
    /**
     * @brief iの成分 と jの成分 を併合する
     * 
     * @param i 
     * @param j 
     * @return true 意味のある併合が発生
     * @return false 元々同じ成分だった
     */
    bool unite(int i, int j) { return unite(i, j, NOP1, NOP2, NOP1, NOP1); }
    /**
     * @brief 最後のuniteをundoする (付加情報を管理するケース)
     * 
     * @param restore restore(i): Siを保存した履歴情報に戻す (snapと対)
     */
    void undo(auto restore)
    {
        m_infos[m_diffs.back().first] = m_diffs.back().second;
        restore(m_diffs.back().first), m_diffs.pop_back();
        m_infos[m_diffs.back().first] = m_diffs.back().second;
        restore(m_diffs.back().first), m_diffs.pop_back();
    }
    /**
     * @brief 最後のuniteをundoする
     */
    void undo() { undo(NOP1); }
    /**
     * @brief iとjが同じ成分かどうか
     * 
     * @param i 
     * @param j 
     * @return true 同じ成分
     * @return false 異なる成分
     */
    bool same(int i, int j) const { return find(i) == find(j); }
    /**
     * @brief iを含む成分のサイズ
     * 
     * @param i 
     * @return int サイズ
     */
    int size(int i) const { return -m_infos[find(i)]; }
    /**
     * @brief 各成分の頂点集合
     * 
     * @return Vec<Vec<int>> 頂点番号列
     */
    Vec<Vec<int>> groups() const
    {
        Vec<Vec<int>> iss(m_V);
        for (const int i : rep(m_V)) { iss[find(i)].push_back(i); }
        return iss;
    }
private:
    int m_V;
    Vec<int> m_infos;
    Vec<Pair<int, int>> m_diffs;
};
