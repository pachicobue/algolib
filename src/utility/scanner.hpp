#pragma once
#include "../common.hpp"
/**
 * @brief 入力ヘルパー
 * @note >> をサポートしている型T と Vec<T> と Vec<Vec<T>> の入力をサポート
 */
class Scanner
{
public:
    /**
     * @brief コンストラクタ
     * 
     * @param is 入力ストリーム
     */
    Scanner(Istream& is = std::cin) : m_is{is} { m_is.tie(nullptr)->sync_with_stdio(false); }
    /**
     * @brief 入力
     * 
     * @tparam T 入力したい型
     * @return T 入力値
     */
    template<typename T> T val()
    {
        T v;
        return m_is >> v, v;
    }
    /**
     * @brief 入力 (オフセット指定)
     * 
     * @tparam T 入力したい型
     * @param offset オフセット
     * @return T 入力値 - offset
     */
    template<typename T> T val(T offset) { return val<T>() - offset; }
    /**
     * @brief 入力 (Vec<T>)
     * 
     * @tparam T 入力したい型
     * @param N 入力値列長
     * @return T 入力値列
     */
    template<typename T> Vec<T> vec(int N)
    {
        return genVec<T>(N, [&]() { return val<T>(); });
    }
    /**
     * @brief 入力 (Vec<T>, オフセット指定)
     * 
     * @tparam T 入力したい型
     * @param N 入力値列長
     * @param offset オフセット
     * @return Vec<T> 入力値列 - offset
     */
    template<typename T> Vec<T> vec(int N, T offset)
    {
        return genVec<T>(N, [&]() { return val<T>(offset); });
    }
    /**
     * @brief 入力 (Vec<Vec<T>>)
     * 
     * @tparam T 入力したい型
     * @param N 入力値行列 行数
     * @param M 入力値行列 列数
     * @return Vec<Vec<T>> 入力値行列
     */
    template<typename T> Vec<Vec<T>> vvec(int n, int m)
    {
        return genVec<Vec<T>>(n, [&]() { return vec<T>(m); });
    }
    /**
     * @brief 入力 (Vec<Vec<T>>)
     * 
     * @tparam T 入力したい型
     * @param N 入力値行列 行数
     * @param M 入力値行列 列数
     * @param offset オフセット
     * @return Vec<Vec<T>> 入力値行列 - オフセット
     */
    template<typename T> Vec<Vec<T>> vvec(int n, int m, const T offset)
    {
        return genVec<Vec<T>>(n, [&]() { return vec<T>(m, offset); });
    }
    /**
     * @brief 入力 (Tuple)
     * 
     * @tparam Args 入力したい型
     * @return Tup 入力値のタプル
     */
    template<typename... Args> auto tup() { return Tup<Args...>{val<Args>()...}; }
    /**
     * @brief 入力 (Tuple)
     * 
     * @tparam T 入力したい型
     * @param オフセット
     * @return Tup 入力値のタプル - offset
     */
    template<typename... Args> auto tup(Args... offsets) { return Tup<Args...>{val<Args>(offsets)...}; }
private:
    Istream& m_is;
};
inline Scanner in;
