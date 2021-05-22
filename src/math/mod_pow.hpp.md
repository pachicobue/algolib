---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/garner.hpp
    title: src/math/garner.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/mod_pow.hpp\"\ntemplate<typename T>\nT mod_pow(T\
    \ x, T n, const T mod)\n{\n    T ans = T{1} % mod;\n    for (; n; n >>= 1, (x\
    \ *= x) %= mod) {\n        if (n & 1) { (ans *= x) %= mod; }\n    }\n    return\
    \ ans;\n}\n"
  code: "#pragma once\ntemplate<typename T>\nT mod_pow(T x, T n, const T mod)\n{\n\
    \    T ans = T{1} % mod;\n    for (; n; n >>= 1, (x *= x) %= mod) {\n        if\
    \ (n & 1) { (ans *= x) %= mod; }\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/mod_pow.hpp
  requiredBy:
  - src/math/garner.hpp
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/mod_pow.hpp
layout: document
redirect_from:
- /library/src/math/mod_pow.hpp
- /library/src/math/mod_pow.hpp.html
title: src/math/mod_pow.hpp
---
