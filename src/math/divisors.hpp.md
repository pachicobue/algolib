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
  bundledCode: "#line 2 \"src/math/divisors.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\ntemplate<typename T>\nstd::vector<T> divisors(const T n)\n{\n    std::vector<T>\
    \ head, tail;\n    for (T i = 1; i * i <= n; i++) {\n        if (n % i == 0) {\n\
    \            head.push_back(i);\n            if (i * i != n) { tail.push_back(n\
    \ / i); }\n        }\n    }\n    std::copy(tail.begin(), tail.end(), head.end());\n\
    \    return head;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\ntemplate<typename\
    \ T>\nstd::vector<T> divisors(const T n)\n{\n    std::vector<T> head, tail;\n\
    \    for (T i = 1; i * i <= n; i++) {\n        if (n % i == 0) {\n           \
    \ head.push_back(i);\n            if (i * i != n) { tail.push_back(n / i); }\n\
    \        }\n    }\n    std::copy(tail.begin(), tail.end(), head.end());\n    return\
    \ head;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/divisors.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/divisors.hpp
layout: document
redirect_from:
- /library/src/math/divisors.hpp
- /library/src/math/divisors.hpp.html
title: src/math/divisors.hpp
---
