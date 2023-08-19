#pragma once
#include "../common.hpp"
/**
 * @brief 座標圧縮
 * 
 * @tparam T 圧縮前の型
 */
template<typename T> class Zipper
{
public:
    /**
     * @brief コンストラクタ
     */
    Zipper() {}
    /**
     * @brief コンストラクタ
     * 
     * @param Xs 座標列
     */
    Zipper(const Vec<T>& Xs) : m_vs{Xs}, m_calced(false) {}
    /**
     * @brief 圧縮前の値
     * 
     * @param x 圧縮後の値
     * @return T 圧縮前の値
     */
    T unzip(int x)
    {
        calc();
        assert(0 <= x and x < size());
        return m_vs[x];
    }
    /**
     * @brief 圧縮後の値
     * @attention 圧縮列に含まれる値を指定すること
     * 
     * @param X 圧縮前の値
     * @return int 圧縮後の値
     */
    int zip(T X)
    {
        calc();
        assert(sortedFind(m_vs, X) < (int)m_vs.size());
        return sortedLbInd(m_vs, X);
    }
    /**
     * @brief 値を追加で圧縮
     * 
     * @param X 値
     */
    void add(T X) { m_vs.push_back(X), m_calced = false; }
    /**
     * @brief 値列を追加で圧縮
     * 
     * @param Xs 値列
     */
    void add(const Vec<T>& Xs)
    {
        for (const auto& v : Xs) { m_vs.push_back(v); }
        m_calced = false;
    }
    /**
     * @brief 圧縮後の数列長
     * 
     * @return int 数列長
     */
    int size()
    {
        calc();
        return m_vs.size();
    }
#ifdef HOGEPACHI
    friend Ostream& operator<<(Ostream& os, const Zipper& zipper_)
    {
        auto zipper = zipper_;
        zipper.calc();
        return os << zipper.m_vs << "\n";
    }
#endif
private:
    void calc()
    {
        if (not m_calced) {
            seqSort(m_vs);
            m_vs.erase(std::unique(m_vs.begin(), m_vs.end()), m_vs.end());
            m_calced = true;
        }
    }
    Vec<T> m_vs;
    bool m_calced = true;
};
