#pragma once
#include "../common.hpp"
class Garner
{
public:
    template<typename mint, typename mint1, typename mint2>
    static mint restore_mod(const mint1& x1, const mint2& x2)
    {
        constexpr auto m1 = mint1::mod();
        const auto [y0, y1] = coeff(x1, x2);
        return mint(y0.val()) + mint(y1.val()) * m1;
    }
    template<typename mint, typename mint1, typename mint2, typename mint3>
    static mint restore_mod(const mint1& x1, const mint2& x2, const mint3& x3)
    {
        constexpr auto m1 = mint1::mod();
        constexpr auto m2 = mint2::mod();
        const auto [y0, y1, y2] = coeff(x1, x2, x3);
        return mint(y0.val()) + mint(y1.val()) * m1 + mint(y2.val()) * m1 * m2;
    }
    template<typename mint1, typename mint2>
    static i64 restore_i64(const mint1& x1, const mint2& x2)
    {
        constexpr u32 m1 = mint1::mod();
        constexpr u32 m2 = mint2::mod();
        const auto [y0, y1] = coeff(x1, x2);
        constexpr u64 MAX = 1_u64 << 63;
        const i128 M = (i128)m1 * m2;
        i128 S = i128(y0.val()) + i128(y1.val()) * m1;
        if (S >= MAX) { S -= M; }
        return (i64)S;
    }
    template<typename mint1, typename mint2, typename mint3>
    static i64 restore_i64(const mint1& x1, const mint2& x2, const mint3& x3)
    {
        constexpr u32 m1 = mint1::mod();
        constexpr u32 m2 = mint2::mod();
        constexpr u32 m3 = mint3::mod();
        const auto [y0, y1, y2] = coeff(x1, x2, x3);
        constexpr u64 MAX = 1_u64 << 63;
        const i128 M = (i128)m1 * m2 * m3;
        i128 S
            = i128(y0.val()) + i128(y1.val()) * m1 + i128(y2.val()) * m1 * m2;
        if (S >= MAX) { S -= M; }
        return (i64)S;
    }

private:
    template<typename mint1, typename mint2>
    static Pair<mint1, mint2> coeff(const mint1& x1, const mint2& x2)
    {
        constexpr auto m1 = mint1::mod();
        constexpr mint2 m1_inv = mint2(m1).inv();
        const mint1 y0 = x1;
        const mint2 y1 = (x2 - mint2(y0.val())) * m1_inv;
        return {y0, y1};
    }
    template<typename mint1, typename mint2, typename mint3>
    static Tup<mint1, mint2, mint3>
        coeff(const mint1& x1, const mint2& x2, const mint3& x3)
    {
        constexpr auto m1 = mint1::mod();
        constexpr auto m2 = mint2::mod();
        constexpr mint2 m1_inv = mint2(m1).inv();
        constexpr mint3 m1m2_inv = (mint3(m1) * mint3(m2)).inv();
        const mint1 y0 = x1;
        const mint2 y1 = (x2 - mint2(y0.val())) * m1_inv;
        const mint3 y2
            = (x3 - mint3(y0.val()) - mint3(y1.val()) * m1) * m1m2_inv;
        return {y0, y1, y2};
    }
};
