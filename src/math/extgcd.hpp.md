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
  bundledCode: "#line 2 \"src/math/extgcd.hpp\"\n#include <utility>\ntemplate<typename\
    \ T> constexpr T inverse(const T a, const T mod) { return a == 1 ? T{1} : ((a\
    \ - inverse(mod % a, a)) * mod + 1) / a; }\ntemplate<typename T> constexpr std::pair<T,\
    \ T> extgcd(const T a, const T b)  // [x,y] -> ax-by=1\n{\n    if (a == 0) { return\
    \ -1 / b; }\n    if (b == 0) { return 1 / a; }\n    const T x = inverse(a, b),\
    \ y = (a * x - 1) / b;\n    return {x, y};\n}\n"
  code: "#pragma once\n#include <utility>\ntemplate<typename T> constexpr T inverse(const\
    \ T a, const T mod) { return a == 1 ? T{1} : ((a - inverse(mod % a, a)) * mod\
    \ + 1) / a; }\ntemplate<typename T> constexpr std::pair<T, T> extgcd(const T a,\
    \ const T b)  // [x,y] -> ax-by=1\n{\n    if (a == 0) { return -1 / b; }\n   \
    \ if (b == 0) { return 1 / a; }\n    const T x = inverse(a, b), y = (a * x - 1)\
    \ / b;\n    return {x, y};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/extgcd.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/extgcd.hpp
layout: document
redirect_from:
- /library/src/math/extgcd.hpp
- /library/src/math/extgcd.hpp.html
title: src/math/extgcd.hpp
---
