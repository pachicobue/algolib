#pragma once
#include <cassert>
#include "../internal.hpp"
#include "pollard_rho.hpp"
/**
 * @brief 原始根
 *
 * @param P Mod (素数)
 * @return u64 最小の原始根
 */
constexpr auto primitiveRoot(u64 P) -> u64 {
    assert(P >= 2);

    u64 Q = P - 1, ps[60];
    int pn = 0;
    for (u64 p = 2; p * p <= P - 1; p++) {
        if (Q % p == 0) {
            ps[pn++] = p;
            while (Q % p == 0) {
                Q /= p;
            }
        }
    }
    if (Q > 1) {
        ps[pn++] = Q;
    }
    for (u64 r = 1; r < P; r++) {
        bool ok = true;
        for (int pi : rep(pn)) {
            const u64 p = ps[pi];
            const u64 Q = powerMod(r, (P - 1) / p, P);
            if (Q == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return r;
        }
    }
    return 0;
}
/**
 * @brief 原始根
 *
 * @param P Mod (素数)
 * @return u64 最小の原始根
 */
inline auto primitiveRootFast(u64 P) -> u64 {
    assert(P >= 2);
    Vec<u64> ps;
    for (const auto& e : primeFactors(P - 1)) {
        ps.push_back(e.first);
    }
    for (u64 r = 1; r < P; r++) {
        bool ok = true;
        for (const u64 p : ps) {
            const u64 Q = powerMod(r, (P - 1) / p, P);
            if (Q == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return r;
        }
    }
    return 0;
}
