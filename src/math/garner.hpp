#pragma once
#include "../misc/common.hpp"
#include "modint64.hpp"

template<typename mint, typename mint1, typename mint2>
mint restore_mod(const mint1& x1, const mint2& x2)
{
    constexpr u32 m1 = mint1::mod();
    constexpr mint2 m1_inv = mint2(m1).inv();
    const mint1 y0 = x1;
    const mint2 y1 = (x2 - mint2(y0.val())) * m1_inv;
    return mint(y0.val()) + mint(y1.val()) * m1;
}

template<typename mint, typename mint1, typename mint2, typename mint3>
mint restore_mod(const mint1& x1, const mint2& x2, const mint3& x3)
{
    constexpr u32 m1 = mint1::mod();
    constexpr u32 m2 = mint2::mod();
    constexpr mint2 m1_inv = mint2(m1).inv();
    constexpr mint3 m1m2_inv = (mint3(m1) * mint3(m2)).inv();
    const mint1 y0 = x1;
    const mint2 y1 = (x2 - mint2(y0.val())) * m1_inv;
    const mint3 y2 = (x3 - mint3(y0.val()) - mint3(y1.val()) * m1) * m1m2_inv;
    return mint(y0.val()) + mint(y1.val()) * m1 + mint(y2.val()) * m1 * m2;
}

template<typename mint1, typename mint2>
i64 restore_i64(const mint1& x1, const mint2& x2)
{
    constexpr u64 MAX = 1_u64 << 63;
    constexpr u64 M = -95_u64;  // M = 2^64-95
    using mint = modint64<M, 0, 0>;

    const u64 x = restore_mod<mint>(x1, x2).val();
    if (x < MAX) {
        return x;
    } else {
        return -(i64)(M - x);
    }
}

template<typename mint1, typename mint2, typename mint3>
i64 restore_i64(const mint1& x1, const mint2& x2, const mint3& x3)
{
    constexpr u64 MAX = 1_u64 << 63;
    constexpr u64 M = -95_u64;  // M = 2^64-95
    using mint = modint64<M, 0, 0>;

    const u64 x = restore_mod<mint>(x1, x2, x3).val();
    if (x < MAX) {
        return x;
    } else {
        return -(i64)(M - x);
    }
}
