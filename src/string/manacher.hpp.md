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
  bundledCode: "#line 2 \"src/string/manacher.hpp\"\n#include <string>\n#include <vector>\n\
    template<typename InIt>\nstd::vector<int> manacher(const InIt first, const InIt\
    \ last)\n{\n    const int sz = std::distance(first, last);\n    std::vector<int>\
    \ ans(sz);\n    for (int i = 0, k = 1, j = 0; i < sz; i += k, j -= k, k = 1) {\n\
    \        while (i >= j and i + j < sz and *std::next(first, i - j) == *std::next(first,\
    \ i + j)) { ++j; }\n        ans[i] = j;\n        while (i >= k and i + k < sz\
    \ and k + ans[i - k] < j) { ans[i + k] = ans[i - k], ++k; }\n    }\n    return\
    \ ans;\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\ntemplate<typename InIt>\n\
    std::vector<int> manacher(const InIt first, const InIt last)\n{\n    const int\
    \ sz = std::distance(first, last);\n    std::vector<int> ans(sz);\n    for (int\
    \ i = 0, k = 1, j = 0; i < sz; i += k, j -= k, k = 1) {\n        while (i >= j\
    \ and i + j < sz and *std::next(first, i - j) == *std::next(first, i + j)) { ++j;\
    \ }\n        ans[i] = j;\n        while (i >= k and i + k < sz and k + ans[i -\
    \ k] < j) { ans[i + k] = ans[i - k], ++k; }\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/manacher.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/manacher.hpp
layout: document
redirect_from:
- /library/src/string/manacher.hpp
- /library/src/string/manacher.hpp.html
title: src/string/manacher.hpp
---
