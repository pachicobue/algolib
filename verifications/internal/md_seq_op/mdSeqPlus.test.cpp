// verification-helper: UNITTEST
#include "internal/irange.hpp"
#include "internal/md_seq_op.hpp"
#include "utility/md_vec.hpp"
#include "utility/rng.hpp"
template<typename Vssss> void test()
{
    Vssss xssss{
        {{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}},          {{11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}}},
        {{{21, 22, 23, 24, 25}, {26, 27, 28, 29, 30}}, {{31, 32, 33, 34, 35}, {36, 37, 38, 39, 40}}},
        {{{41, 42, 43, 44, 45}, {46, 47, 48, 49, 50}}, {{51, 52, 53, 54, 55}, {56, 57, 58, 59, 60}}}
    };
    Vssss pxssss{
        {{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}},          {{11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}}},
        {{{21, 22, 23, 24, 25}, {26, 27, 28, 29, 30}}, {{31, 32, 33, 34, 35}, {36, 37, 38, 39, 40}}},
        {{{41, 42, 43, 44, 45}, {46, 47, 48, 49, 50}}, {{51, 52, 53, 54, 55}, {56, 57, 58, 59, 60}}}
    };
    for (int i : rep(3)) {
        for (int j : rep(2)) {
            for (int k : rep(2)) {
                for (int l : rep(5)) { pxssss[i][j][k][l] = xssss[i][j][k][l] = rng.val<int>(-100, 100); }
            }
        }
    }
    const int X = 1909;
    mdSeqPlus(xssss, X);
    for (int i : rep(3)) {
        for (int j : rep(2)) {
            for (int k : rep(2)) {
                for (int l : rep(5)) { assert(xssss[i][j][k][l] == pxssss[i][j][k][l] + X); }
            }
        }
    }
}
int main()
{
    test<int[3][2][2][5]>();
    test<Vec<Vec<Vec<Vec<int>>>>>();
    test<Deq<Deq<Deq<Deq<int>>>>>();
    return 0;
}
