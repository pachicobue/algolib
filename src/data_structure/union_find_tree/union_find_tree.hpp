#pragma once
#include "../../common.hpp"
/**
 * @brief UnionFind木
 */
class UnionFindTree
{
    static constexpr auto NOP1 = [](int) {};
    static constexpr auto NOP2 = [](int, int) {};
public:
    /**
     * @brief コンストラクタ
     * 
     * @param N 要素数
     */
    UnionFindTree(int N) : m_V{N}, m_infos(m_V, -1) {}
    /**
     * @brief iを含む成分の代表元
     * 
     * @param i 
     * @return int 代表元
     */
    int find(int i)
    {
        if (m_infos[i] < 0) {
            return i;
        } else {
            return m_infos[i] = find(m_infos[i]);
        }
    }
    /**
     * @brief SiとSjを併合する (付加情報を管理するケース)
     * 
     * @param i 
     * @param j 
     * @param merge merge(i,j): SiをSjに併合する際の操作 (向きがあるので注意)
     * @param add add(i): Siの「スコア」を加算する
     * @param del del(i): Siの「スコア」を減算する
     * @return true 意味のある併合が発生
     * @return false 元々同じ成分だった
     */
    bool unite(int i, int j, auto merge, auto add, auto del)
    {
        i = find(i), j = find(j);
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
    bool unite(int i, int j) { return unite(i, j, NOP2, NOP1, NOP1); }
    /**
     * @brief iとjが同じ成分かどうか
     * 
     * @param i 
     * @param j 
     * @return true 同じ成分
     * @return false 異なる成分
     */
    bool same(int i, int j) { return find(i) == find(j); }
    /**
     * @brief iを含む成分のサイズ
     * 
     * @param i 
     * @return int サイズ
     */
    int size(int i) { return -m_infos[find(i)]; }
    /**
     * @brief 各成分の頂点集合
     * 
     * @return Vec<Vec<int>> 頂点番号列
     */
    Vec<Vec<int>> groups()
    {
        Vec<Vec<int>> iss(m_V);
        for (const int i : rep(m_V)) { iss[find(i)].push_back(i); }
        return iss;
    }
private:
    int m_V;
    Vec<int> m_infos;
};
