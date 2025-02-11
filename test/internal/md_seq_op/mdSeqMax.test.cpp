// verification-helper: UNITTEST
#include <cassert>
#include "internal/chminmax.hpp"
#include "internal/constant.hpp"
#include "internal/irange.hpp"
#include "internal/md_seq_op.hpp"
#include "internal/type.hpp"
#include "utility/rng.hpp"
template <typename Vssss> void lessTest() {
    Vssss xssss{
        {         {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}, {{11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}}},
        {{{21, 22, 23, 24, 25}, {26, 27, 28, 29, 30}}, {{31, 32, 33, 34, 35}, {36, 37, 38, 39, 40}}},
        {{{41, 42, 43, 44, 45}, {46, 47, 48, 49, 50}}, {{51, 52, 53, 54, 55}, {56, 57, 58, 59, 60}}}
    };
    int M = -INF<int>;
    for (int i : rep(3)) {
        for (int j : rep(2)) {
            for (int k : rep(2)) {
                for (int l : rep(5)) {
                    xssss[i][j][k][l] = rng.val<int>(-100, 100);
                    chmax(M, xssss[i][j][k][l]);
                }
            }
        }
    }
    assert(mdSeqMax(xssss) == M);
}
template <typename Vssss> void greaterTest() {
    Vssss xssss{
        {         {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}, {{11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}}},
        {{{21, 22, 23, 24, 25}, {26, 27, 28, 29, 30}}, {{31, 32, 33, 34, 35}, {36, 37, 38, 39, 40}}},
        {{{41, 42, 43, 44, 45}, {46, 47, 48, 49, 50}}, {{51, 52, 53, 54, 55}, {56, 57, 58, 59, 60}}}
    };
    int M = INF<int>;
    for (int i : rep(3)) {
        for (int j : rep(2)) {
            for (int k : rep(2)) {
                for (int l : rep(5)) {
                    xssss[i][j][k][l] = rng.val<int>(-100, 100);
                    chmin(M, xssss[i][j][k][l]);
                }
            }
        }
    }
    assert(mdSeqMax(xssss, Gt<int>{}) == M);
}
int main() {
    lessTest<int[3][2][2][5]>();
    lessTest<Vec<Vec<Vec<Vec<int>>>>>();
    lessTest<Deq<Deq<Deq<Deq<int>>>>>();

    greaterTest<int[3][2][2][5]>();
    greaterTest<Vec<Vec<Vec<Vec<int>>>>>();
    greaterTest<Deq<Deq<Deq<Deq<int>>>>>();
    return 0;
}
