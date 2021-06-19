#pragma once
#include "../misc/common.hpp"
template<typename It>
Vec<int> suffixArray(It first, It last, int vsup = 256)
{
    const int N = last - first;
    Vec<int> vs(N);
    std::copy(first, last, vs.begin());
    for (auto& v : vs) {
        assert(0 <= v and v < vsup);
        v++;
    }
    vs.push_back(0);
    Vec<bool> is_l(N + 1, false);
    Vec<bool> is_lms(N + 1, false);
}

// template<typename It>
// Vec<int> suffixArray(It first, It last, int bucket_size = (1UL << 8))
// {
//     bucket_size++;
//     const int sz = (int)std::distance(first, last);
//     Vec<bool> isL(sz + 1, false), isLMS(sz + 1, false);
//     Vec<int> spos(bucket_size, 0), lpos(bucket_size, 0);
//     Vec<int> S(sz + 1, 0);
//     Vec<int> nextLMS(sz + 1, sz + 1);
//     Vec<int> LMS;
//     Vec<Vec<int>> sBucket(bucket_size), lBucket(bucket_size);
//     for (int i : rep(sz)) {
//         S[i] = *std::next(first, i) + 1;
//     }
//     sBucket[0].push_back(sz + 1);
//     for (int j = 1, pos = sz; j <= sz; j++) {
//         int i = sz - j;
//         isL[i] = S[i] > S[i + 1] or (S[i] == S[i + 1] and isL[i + 1]),
//         (isL[i] ? lBucket[S[i]] : sBucket[S[i]]).push_back(sz + 1);
//         nextLMS[i] = pos;
//         if (isL[i] and not isL[i + 1]) {
//             LMS.push_back(i + 1);
//             isLMS[i + 1] = true;
//             sBucket[S[i + 1]][spos[S[i + 1]]++] = i + 1;
//             pos = i + 1;
//         }
//     }
//     auto induce = [&]() {
//         auto insert = [&](const int i, const bool isl) {
//             if (i == 0 or isl != isL[i - 1]) { return; }
//             if (isL[i - 1]) {
//                 lBucket[S[i - 1]][lpos[S[i - 1]]++] = i - 1;
//             } else {
//                 sBucket[S[i - 1]][spos[S[i - 1]]++] = i - 1;
//             }
//         };
//         for (int k : rep(bucket_size)) {
//             for (int i : rep(lpos[k])) {
//                 insert(lBucket[k][i], true);
//             }
//             for (int i : irange(1, spos[k] + 1)) {
//                 insert(sBucket[k][spos[k] - i], true);
//             }
//         }
//         fillAll(spos, 0);
//         for (int i : irange(1, bucket_size + 1)) {
//             const int k = bucket_size - i;
//             for (int i : rep(spos[k])) {
//                 insert(sBucket[k][i], false);
//             }
//             for (int i : irange(1, lpos[k] + 1)) {
//                 insert(lBucket[k][lpos[k] - i], false);
//             }
//         }
//     };
//     induce();
//     Vec<int> lms;
//     for (int k : rep(bucket_size)) {
//         for (auto it = lBucket[k].begin(); it < lBucket[k].end(); it++) {
//             if (isLMS[*it]) { lms.push_back(*it); }
//         }
//         for (auto it = sBucket[k].rbegin(); it < sBucket[k].rend(); it++) {
//             if (isLMS[*it]) { lms.push_back(*it); }
//         }
//     }
//     bool distinct = true;
//     int number = 1;
//     Vec<int> ord((sz + 1) / 2 + 1, 0);
//     ord[(sz + 1) / 2] = 1;
//     for (int i : irange(1, lms.size())) {
//         const int l1 = lms[i - 1], r1 = nextLMS[l1];
//         const int l2 = lms[i], r2 = nextLMS[l2];
//         if (r1 - l1 == r2 - l2
//             and Vec<int>(S.begin() + l1, S.begin() + r1 + 1)
//                     == Vec<int>(S.begin() + l2, S.begin() + r2 + 1)) {
//             distinct = false;
//         } else {
//             number++;
//         }
//         ord[l2 / 2] = number;
//     }
//     Vec<int> sub;
//     for (const auto o : ord) {
//         if (o > 0) { sub.push_back(o); }
//     }
//     if (not distinct) {
//         const auto sorted = suffixArray(sub.begin(), sub.end(), number + 1);
//         for (int k : rep(bucket_size)) {
//             spos[k] = lpos[k] = 0;
//         }
//         for (int j : irange(1, lms.size() + 1)) {
//             const int i = lms.size() - j;
//             const auto ind = LMS[lms.size() - 1 - sorted[i]];
//             sBucket[S[ind]][spos[S[ind]]++] = ind;
//         }
//     } else {
//         for (int k : rep(bucket_size)) {
//             spos[k] = lpos[k] = 0;
//         }
//         for (auto it = lms.rbegin(); it < lms.rend(); it++) {
//             sBucket[S[*it]][spos[S[*it]]++] = *it;
//         }
//     }
//     induce();
//     Vec<int> ans;
//     for (int k : irange(1, bucket_size)) {
//         for (auto it = lBucket[k].begin(); it < lBucket[k].end(); it++) {
//             ans.push_back(*it);
//         }
//         for (auto it = sBucket[k].rbegin(); it < sBucket[k].rend(); it++) {
//             ans.push_back(*it);
//         }
//     }
//     return ans;
// }
