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
  bundledCode: "#line 2 \"src/string/z_algorithm.hpp\"\n#include <string>\n#include\
    \ <vector>\ntemplate<typename InIt>\nstd::vector<int> z_algorithm(const InIt first,\
    \ const InIt last)\n{\n    const int sz = std::distance(first, last);\n    std::vector<int>\
    \ ans(sz, -1);\n    for (int i = 1, j = 0; i < sz;) {\n        while (i + j <\
    \ sz and *std::next(first, j) == *std::next(first, i + j)) { j++; }\n        ans[i]\
    \ = j;\n        if (j == 0) {\n            ++i;\n            continue;\n     \
    \   }\n        int k = 1;\n        while (i + k < sz and k + ans[k] < j) { ans[i\
    \ + k] = ans[k], k++; }\n        i += k, j -= k;\n    }\n    return ans[0] = sz,\
    \ ans;\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\ntemplate<typename InIt>\n\
    std::vector<int> z_algorithm(const InIt first, const InIt last)\n{\n    const\
    \ int sz = std::distance(first, last);\n    std::vector<int> ans(sz, -1);\n  \
    \  for (int i = 1, j = 0; i < sz;) {\n        while (i + j < sz and *std::next(first,\
    \ j) == *std::next(first, i + j)) { j++; }\n        ans[i] = j;\n        if (j\
    \ == 0) {\n            ++i;\n            continue;\n        }\n        int k =\
    \ 1;\n        while (i + k < sz and k + ans[k] < j) { ans[i + k] = ans[k], k++;\
    \ }\n        i += k, j -= k;\n    }\n    return ans[0] = sz, ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/z_algorithm.hpp
layout: document
redirect_from:
- /library/src/string/z_algorithm.hpp
- /library/src/string/z_algorithm.hpp.html
title: src/string/z_algorithm.hpp
---
