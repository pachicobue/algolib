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
  bundledCode: "#line 2 \"src/string/mp.hpp\"\n#include <string>\n#include <vector>\n\
    template<typename InIt>\nstd::vector<int> mp(const InIt first, const InIt last)\n\
    {\n    const int sz = std::distance(first, last);\n    std::vector<int> A(sz +\
    \ 1, -1);\n    for (int i = 0, j = -1; i < sz; i++) {\n        while (j != -1\
    \ and *(std::next(first, i)) != *(std::next(first, j))) { j = A[j]; }\n      \
    \  j = (j == -1 ? 0 : j + 1), A[i + 1] = j;\n    }\n    return A;\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\ntemplate<typename InIt>\n\
    std::vector<int> mp(const InIt first, const InIt last)\n{\n    const int sz =\
    \ std::distance(first, last);\n    std::vector<int> A(sz + 1, -1);\n    for (int\
    \ i = 0, j = -1; i < sz; i++) {\n        while (j != -1 and *(std::next(first,\
    \ i)) != *(std::next(first, j))) { j = A[j]; }\n        j = (j == -1 ? 0 : j +\
    \ 1), A[i + 1] = j;\n    }\n    return A;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/mp.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/mp.hpp
layout: document
redirect_from:
- /library/src/string/mp.hpp
- /library/src/string/mp.hpp.html
title: src/string/mp.hpp
---
