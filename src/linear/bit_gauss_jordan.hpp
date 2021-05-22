#pragma once
#include "../misc/common.hpp"
#include "bit_matrix.hpp"
template<int column>
BitMat<column> gaussJordan(BitMat<column> mat)
{
    const int row = mat.row();
    int r         = 0;
    for (int c : per(column)) {
        if (r == row) { break; }
        int piv = r;
        for (; piv < row and not mat[piv][c]; piv++) {}
        if (piv == row) { continue; }
        std::swap(mat[piv], mat[r]);
        for (int j : rep(row)) {
            if (j == r) { continue; }
            if (mat[j][c]) { mat[j] ^= mat[r]; }
        }
        r++;
    }
    return mat;
}
