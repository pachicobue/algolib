#pragma once
#include "../misc/common.hpp"
#include "factor_table.hpp"
Vec<int> primes(int sup)
{
    const auto ftable = factorTable(sup);
    Vec<int> ps;
    for (int p = 2; p < sup; p++) {
        if (ftable[p] == p) { ps.push_back(p); }
    }
    return ps;
}
