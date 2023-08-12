#pragma once
#include "../common.hpp"
constexpr u64 primitiveRoot(u64 P)
{
    assert(P >= 2);
    Vec<u64> ps;
    {
        u64 Q = P - 1;
        for (u64 p = 2; p * p <= P - 1; p++) {
            if (Q % p == 0) { ps.push_back(p); }
            while (Q % p == 0) { Q /= p; }
        }
        if (Q > 1) { ps.push_back(Q); }
    }
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
