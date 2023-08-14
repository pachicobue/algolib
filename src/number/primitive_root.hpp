#pragma once
#include "../common.hpp"
#include "pollard_rho.hpp"
/**
 * @brief 原始根
 * 
 * @param P Mod (素数)
 * @return u64 最小の原始根
 */
constexpr u64 primitiveRoot(u64 P)
{
    assert(P >= 2);
    Vec<u64> ps;
    for (const auto& e : primeFactors(P - 1)) { ps.push_back(e.first); }
    for (u64 r = 1; r < P; r++) {
        bool ok = true;
        for (u64 p : ps) {
            const u64 Q = powerMod(r, (P - 1) / p, P);
            if (Q == 1) {
                ok = false;
                break;
            }
        }
        if (ok) { return r; }
    }
    return 0;
}
