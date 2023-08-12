#pragma once
#include "../common.hpp"
/**
 * @brief 二分探索 (離散)
 * @attention check(ng), check(ok) は評価されない
 * 
 * @param ng check(ng)==False が保証される引数
 * @param ok check(ok)==True が保証される引数
 * @param check 判定関数
 * @return i64 check(x)となる x のうち ok から最も遠い値
 */
constexpr i64 binSearch(i64 ng, i64 ok, auto check)
{
    while (ABS(ok - ng) > 1) {
        const i64 mid          = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    return ok;
}
/**
 * @brief 二分探索 (連続)
 * @attention check(ng), check(ok) は呼び出されない(ng,okは無効値でも可)
 * 
 * @param ng check(ng)==False が保証される引数
 * @param ok check(ok)==False が保証される引数
 * @param check 判定関数
 * @param times 反復回数
 * @return f80 check(x)となる x のうち ok から最も遠い値(近似値)
 */
constexpr f80 binSearch(f80 ng, f80 ok, auto check, int times)
{
    LOOP (times) {
        const f80 mid          = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    return ok;
}
