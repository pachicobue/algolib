#pragma once
#include "../misc/common.hpp"
#include "factor_table.hpp"
Vec<u32> primes(u32 sup)
{
    const auto ftable = factorTable(sup);
    Vec<u32> ps;
    for (u32 p = 2; p < sup; p++) {
        if (ftable[p] == p) { ps.push_back(p); }
    }
    return ps;
}
