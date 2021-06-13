#pragma once
#include "matrix.hpp"
template<typename T>
Mat<T> gaussJordan(Mat<T> mat)
{
    const int row = mat.row(), column = mat.column();
    int r = 0;
    for (int c : rep(column)) {
        if (r == row) { break; }
        int piv = r;
        for (; piv < row and mat[piv][c] == T{}; piv++) {}
        if (piv == row) { continue; }
        for (int j : irange(c + 1, column)) {
            mat[piv][j] /= mat[piv][c];
        }
        std::swap(mat[piv], mat[r]);
        mat[r][c] = T{1};
        for (int j : rep(row)) {
            if (j == r) { continue; }
            for (int k : irange(c + 1, column)) {
                mat[j][k] -= mat[r][k] * mat[j][c];
            }
            mat[j][c] = 0;
        }
        r++;
    }
    return mat;
}
