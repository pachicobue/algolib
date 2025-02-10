#pragma once
/**
 * @brief ローカル環境かどうか
 */
#ifdef HOGEPACHI
constexpr bool LOCAL = true;
#else
constexpr bool LOCAL = false;
#endif
/**
 * @brief ジャッジとローカルで別の値を返す
 *
 * @param oj ジャッジでの返り値
 * @param local ローカルでの返り値
 * @return T 返り値
 */
template <typename T> constexpr auto OjLocal(T oj, T local) -> T {
    return LOCAL ? local : oj;
}
