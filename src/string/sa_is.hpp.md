---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/sa_is.hpp\"\n#include <string>\n#include <vector>\n\
    template<typename InIt>\nstd::vector<int> sa_is(const InIt first, const InIt last,\
    \ int bucket_size = (1UL << 8))\n{\n    bucket_size++;\n    const int sz = (int)std::distance(first,\
    \ last);\n    std::vector<bool> isL(sz + 1, false), isLMS(sz + 1, false);\n  \
    \  std::vector<int> spos(bucket_size, 0), lpos(bucket_size, 0), S(sz + 1, 0),\
    \ nextLMS(sz + 1, sz + 1), LMS;\n    std::vector<std::vector<int>> sBucket(bucket_size),\
    \ lBucket(bucket_size);\n    for (int i = 0; i < sz; i++) { S[i] = *std::next(first,\
    \ i) + 1; }\n    sBucket[0].push_back(sz + 1);\n    for (int j = 1, pos = sz;\
    \ j <= sz; j++) {\n        int i      = sz - j;\n        isL[i]     = S[i] > S[i\
    \ + 1] or (S[i] == S[i + 1] and isL[i + 1]), (isL[i] ? lBucket[S[i]].push_back(sz\
    \ + 1) : sBucket[S[i]].push_back(sz + 1));\n        nextLMS[i] = pos;\n      \
    \  if (isL[i] and not isL[i + 1]) { LMS.push_back(i + 1), isLMS[i + 1] = true,\
    \ sBucket[S[i + 1]][spos[S[i + 1]]++] = i + 1, pos = i + 1; }\n    }\n    auto\
    \ induce = [&]() {\n        auto insert = [&](const int i, const bool isl) {\n\
    \            if (i == 0 or isl != isL[i - 1]) { return; }\n            if (isL[i\
    \ - 1]) {\n                lBucket[S[i - 1]][lpos[S[i - 1]]++] = i - 1;\n    \
    \        } else {\n                sBucket[S[i - 1]][spos[S[i - 1]]++] = i - 1;\n\
    \            }\n        };\n        for (int k = 0; k < bucket_size; k++) {\n\
    \            for (int i = 0; i < lpos[k]; i++) { insert(lBucket[k][i], true);\
    \ }\n            for (int i = 1; i <= spos[k]; i++) { insert(sBucket[k][spos[k]\
    \ - i], true); }\n        }\n        std::fill(spos.begin() + 1, spos.end(), 0);\n\
    \        for (int i = 1; i <= bucket_size; i++) {\n            const int k = bucket_size\
    \ - i;\n            for (int i = 0; i < spos[k]; i++) { insert(sBucket[k][i],\
    \ false); }\n            for (int i = 1; i <= lpos[k]; i++) { insert(lBucket[k][lpos[k]\
    \ - i], false); }\n        }\n    };\n    induce();\n    std::vector<int> lms;\n\
    \    for (int k = 0; k < bucket_size; k++) {\n        for (auto it = lBucket[k].begin();\
    \ it < lBucket[k].end(); it++) {\n            if (isLMS[*it]) { lms.push_back(*it);\
    \ }\n        }\n        for (auto it = sBucket[k].rbegin(); it < sBucket[k].rend();\
    \ it++) {\n            if (isLMS[*it]) { lms.push_back(*it); }\n        }\n  \
    \  }\n    bool distinct = true;\n    int number    = 1;\n    std::vector<int>\
    \ ord((sz + 1) / 2 + 1, 0);\n    ord[(sz + 1) / 2] = 1;\n    for (int i = 1; i\
    \ < lms.size(); i++) {\n        const int l1 = lms[i - 1], r1 = nextLMS[l1], l2\
    \ = lms[i], r2 = nextLMS[l2];\n        if (r1 - l1 == r2 - l2 and std::vector<int>(S.begin()\
    \ + l1, S.begin() + r1 + 1) == std::vector<int>(S.begin() + l2, S.begin() + r2\
    \ + 1)) {\n            distinct = false;\n        } else {\n            number++;\n\
    \        }\n        ord[l2 / 2] = number;\n    }\n    std::vector<int> sub;\n\
    \    for (const auto o : ord) {\n        if (o > 0) { sub.push_back(o); }\n  \
    \  }\n    if (not distinct) {\n        const auto sorted = sa_is(sub.begin(),\
    \ sub.end(), number + 1);\n        for (int k = 0; k < bucket_size; k++) { spos[k]\
    \ = lpos[k] = 0; }\n        for (int j = 1; j <= lms.size(); j++) {\n        \
    \    const int i                     = lms.size() - j;\n            const auto\
    \ ind                  = LMS[lms.size() - 1 - sorted[i]];\n            sBucket[S[ind]][spos[S[ind]]++]\
    \ = ind;\n        }\n    } else {\n        for (int k = 0; k < bucket_size; k++)\
    \ { spos[k] = lpos[k] = 0; }\n        for (auto it = lms.rbegin(); it < lms.rend();\
    \ it++) { sBucket[S[*it]][spos[S[*it]]++] = *it; }\n    }\n    induce();\n   \
    \ std::vector<int> ans;\n    for (int k = 1; k < bucket_size; k++) {\n       \
    \ for (auto it = lBucket[k].begin(); it < lBucket[k].end(); it++) { ans.push_back(*it);\
    \ }\n        for (auto it = sBucket[k].rbegin(); it < sBucket[k].rend(); it++)\
    \ { ans.push_back(*it); }\n    }\n    return ans;\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\ntemplate<typename InIt>\n\
    std::vector<int> sa_is(const InIt first, const InIt last, int bucket_size = (1UL\
    \ << 8))\n{\n    bucket_size++;\n    const int sz = (int)std::distance(first,\
    \ last);\n    std::vector<bool> isL(sz + 1, false), isLMS(sz + 1, false);\n  \
    \  std::vector<int> spos(bucket_size, 0), lpos(bucket_size, 0), S(sz + 1, 0),\
    \ nextLMS(sz + 1, sz + 1), LMS;\n    std::vector<std::vector<int>> sBucket(bucket_size),\
    \ lBucket(bucket_size);\n    for (int i = 0; i < sz; i++) { S[i] = *std::next(first,\
    \ i) + 1; }\n    sBucket[0].push_back(sz + 1);\n    for (int j = 1, pos = sz;\
    \ j <= sz; j++) {\n        int i      = sz - j;\n        isL[i]     = S[i] > S[i\
    \ + 1] or (S[i] == S[i + 1] and isL[i + 1]), (isL[i] ? lBucket[S[i]].push_back(sz\
    \ + 1) : sBucket[S[i]].push_back(sz + 1));\n        nextLMS[i] = pos;\n      \
    \  if (isL[i] and not isL[i + 1]) { LMS.push_back(i + 1), isLMS[i + 1] = true,\
    \ sBucket[S[i + 1]][spos[S[i + 1]]++] = i + 1, pos = i + 1; }\n    }\n    auto\
    \ induce = [&]() {\n        auto insert = [&](const int i, const bool isl) {\n\
    \            if (i == 0 or isl != isL[i - 1]) { return; }\n            if (isL[i\
    \ - 1]) {\n                lBucket[S[i - 1]][lpos[S[i - 1]]++] = i - 1;\n    \
    \        } else {\n                sBucket[S[i - 1]][spos[S[i - 1]]++] = i - 1;\n\
    \            }\n        };\n        for (int k = 0; k < bucket_size; k++) {\n\
    \            for (int i = 0; i < lpos[k]; i++) { insert(lBucket[k][i], true);\
    \ }\n            for (int i = 1; i <= spos[k]; i++) { insert(sBucket[k][spos[k]\
    \ - i], true); }\n        }\n        std::fill(spos.begin() + 1, spos.end(), 0);\n\
    \        for (int i = 1; i <= bucket_size; i++) {\n            const int k = bucket_size\
    \ - i;\n            for (int i = 0; i < spos[k]; i++) { insert(sBucket[k][i],\
    \ false); }\n            for (int i = 1; i <= lpos[k]; i++) { insert(lBucket[k][lpos[k]\
    \ - i], false); }\n        }\n    };\n    induce();\n    std::vector<int> lms;\n\
    \    for (int k = 0; k < bucket_size; k++) {\n        for (auto it = lBucket[k].begin();\
    \ it < lBucket[k].end(); it++) {\n            if (isLMS[*it]) { lms.push_back(*it);\
    \ }\n        }\n        for (auto it = sBucket[k].rbegin(); it < sBucket[k].rend();\
    \ it++) {\n            if (isLMS[*it]) { lms.push_back(*it); }\n        }\n  \
    \  }\n    bool distinct = true;\n    int number    = 1;\n    std::vector<int>\
    \ ord((sz + 1) / 2 + 1, 0);\n    ord[(sz + 1) / 2] = 1;\n    for (int i = 1; i\
    \ < lms.size(); i++) {\n        const int l1 = lms[i - 1], r1 = nextLMS[l1], l2\
    \ = lms[i], r2 = nextLMS[l2];\n        if (r1 - l1 == r2 - l2 and std::vector<int>(S.begin()\
    \ + l1, S.begin() + r1 + 1) == std::vector<int>(S.begin() + l2, S.begin() + r2\
    \ + 1)) {\n            distinct = false;\n        } else {\n            number++;\n\
    \        }\n        ord[l2 / 2] = number;\n    }\n    std::vector<int> sub;\n\
    \    for (const auto o : ord) {\n        if (o > 0) { sub.push_back(o); }\n  \
    \  }\n    if (not distinct) {\n        const auto sorted = sa_is(sub.begin(),\
    \ sub.end(), number + 1);\n        for (int k = 0; k < bucket_size; k++) { spos[k]\
    \ = lpos[k] = 0; }\n        for (int j = 1; j <= lms.size(); j++) {\n        \
    \    const int i                     = lms.size() - j;\n            const auto\
    \ ind                  = LMS[lms.size() - 1 - sorted[i]];\n            sBucket[S[ind]][spos[S[ind]]++]\
    \ = ind;\n        }\n    } else {\n        for (int k = 0; k < bucket_size; k++)\
    \ { spos[k] = lpos[k] = 0; }\n        for (auto it = lms.rbegin(); it < lms.rend();\
    \ it++) { sBucket[S[*it]][spos[S[*it]]++] = *it; }\n    }\n    induce();\n   \
    \ std::vector<int> ans;\n    for (int k = 1; k < bucket_size; k++) {\n       \
    \ for (auto it = lBucket[k].begin(); it < lBucket[k].end(); it++) { ans.push_back(*it);\
    \ }\n        for (auto it = sBucket[k].rbegin(); it < sBucket[k].rend(); it++)\
    \ { ans.push_back(*it); }\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/sa_is.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/sa_is.hpp
layout: document
redirect_from:
- /library/src/string/sa_is.hpp
- /library/src/string/sa_is.hpp.html
title: src/string/sa_is.hpp
---
