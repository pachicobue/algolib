#pragma once
#include "../common.hpp"
/**
 * @brief Garner algorithm
 * @attention staticクラス
 */
class Garner final
{
public:
    explicit Garner() = delete;
    ~Garner()         = delete;
    /**
     * @brief 以下を満たす 最小の非負整数xを mod M で求める
     *        1. x = x1 mod m1
     *        2. x = x2 mod m2
     * @attention m1,m2は互いに素にすること
     *
     * @param x1 
     * @param x2 
     * @return mint 最小のx
     */
    template<typename mint, typename mint1, typename mint2> static constexpr mint restoreMod(const mint1& x1, const mint2& x2)
    {
        const u64 m1        = mint1::mod();
        const auto [y0, y1] = coeff(x1, x2);
        return mint(y0) + mint(y1) * m1;
    }
    /**
     * @brief 以下を満たす 最小の非負整数xを mod M で求める
     *        1. x = x1 mod m1
     *        2. x = x2 mod m2
     *        3. x = x3 mod m3
     * @attention m1,m2,m3は互いに素にすること
     * 
     * @param x1 
     * @param x2 
     * @param x3
     * @return mint 最小のx
     */
    template<typename mint, typename mint1, typename mint2, typename mint3>
    static constexpr mint restoreMod(const mint1& x1, const mint2& x2, const mint3& x3)
    {
        const u64 m1 = mint1::mod(), m2 = mint2::mod();
        const auto [y0, y1, y2] = coeff(x1, x2, x3);
        return mint(y0) + mint(y1) * m1 + mint(y2) * m1 * m2;
    }
    /**
     * @brief 以下を満たす 絶対値最小のxを求める
     *        1. x = x1 mod m1
     *        2. x = x2 mod m2
     * @attention m1,m2は互いに素にすること
     * @attention 答えがi64に収まるようにすること
     * 
     * @param x1 
     * @param x2 
     * @return i64 絶対値最小のx
     */
    template<typename mint1, typename mint2> static constexpr i64 restoreInt(const mint1& x1, const mint2& x2)
    {
        const u64 m1 = mint1::mod(), m2 = mint2::mod();
        const auto [y0, y1] = coeff(x1, x2);
        const i128 M        = (i128)m1 * m2;
        const i128 X        = i128(y0) + i128(y1) * m1;
        return (i64)(M / 2 >= X ? X : X - M);
    }
    /**
     * @brief 以下を満たす 絶対値最小のxを求める
     *        1. x = x1 mod m1
     *        2. x = x2 mod m2
     *        3. x = x3 mod m3
     * @attention m1,m2,m3は互いに素にすること
     * @attention m1*m2*m3 <= 2^127-1 とすること
     * @attention 答えがi64に収まるようにすること
     * 
     * @param x1 
     * @param x2 
     * @param x3 
     * @return i64 絶対値最小のx
     */
    template<typename mint1, typename mint2, typename mint3>
    static constexpr i64 restoreInt(const mint1& x1, const mint2& x2, const mint3& x3)
    {
        const u64 m1 = mint1::mod(), m2 = mint2::mod(), m3 = mint3::mod();
        const auto [y0, y1, y2] = coeff(x1, x2, x3);
        const i128 M            = (i128)m1 * m2 * m3;
        const i128 X            = i128(y0) + i128(y1) * m1 + i128(y2) * m1 * m2;
        return (i64)(M / 2 >= X ? X : X - M);
    }
private:
    template<typename mint1, typename mint2> static constexpr Pair<i64, i64> coeff(const mint1& x1, const mint2& x2)
    {
        const u64 m1       = mint1::mod();
        const mint2 m1_inv = mint2(m1).inv();
        const i64 y0       = x1.val();
        const i64 y1       = ((x2 - mint2(y0)) * m1_inv).val();
        return {y0, y1};
    }
    template<typename mint1, typename mint2, typename mint3>
    static constexpr Tup<i64, i64, i64> coeff(const mint1& x1, const mint2& x2, const mint3& x3)
    {
        const u64 m1 = mint1::mod(), m2 = mint2::mod();
        const mint2 m1_inv   = mint2(m1).inv();
        const mint3 m1m2_inv = (mint3(m1) * mint3(m2)).inv();
        const i64 y0         = x1.val();
        const i64 y1         = ((x2 - mint2(y0)) * m1_inv).val();
        const i64 y2         = ((x3 - mint3(y0) - mint3(y1) * m1) * m1m2_inv).val();
        return {y0, y1, y2};
    }
};
