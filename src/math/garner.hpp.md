---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/math/mod_pow.hpp
    title: src/math/mod_pow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/garner.hpp\"\n#include <vector>\n#line 2 \"src/math/mod_pow.hpp\"\
    \ntemplate<typename T>\nT mod_pow(T x, T n, const T mod)\n{\n    T ans = T{1}\
    \ % mod;\n    for (; n; n >>= 1, (x *= x) %= mod) {\n        if (n & 1) { (ans\
    \ *= x) %= mod; }\n    }\n    return ans;\n}\n#line 4 \"src/math/garner.hpp\"\n\
    template<typename T>\nstd::vector<T> garner(const std::vector<T>& xs, const std::vector<T>&\
    \ ms)\n{\n    const int N = (int)xs.size();\n    std::vector<T> as(N);\n    for\
    \ (int i = 0; i < N; i++) {\n        const T xi = xs[i], mod = ms[i];\n      \
    \  T p = 1, sum = 0;\n        for (int j = 0; j < i; j++) {\n            const\
    \ T xj = xs[j];\n            (sum += p * as[j] % mod) %= mod;\n            (p\
    \ *= (xi + mod - xj)) %= mod;\n        }\n        const T res = (xi + mod - sum)\
    \ % mod;\n        as[i]       = res * mod_pow(p, mod - 2, mod) % mod;\n    }\n\
    \    return as;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"mod_pow.hpp\"\ntemplate<typename\
    \ T>\nstd::vector<T> garner(const std::vector<T>& xs, const std::vector<T>& ms)\n\
    {\n    const int N = (int)xs.size();\n    std::vector<T> as(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        const T xi = xs[i], mod = ms[i];\n        T p\
    \ = 1, sum = 0;\n        for (int j = 0; j < i; j++) {\n            const T xj\
    \ = xs[j];\n            (sum += p * as[j] % mod) %= mod;\n            (p *= (xi\
    \ + mod - xj)) %= mod;\n        }\n        const T res = (xi + mod - sum) % mod;\n\
    \        as[i]       = res * mod_pow(p, mod - 2, mod) % mod;\n    }\n    return\
    \ as;\n}\n"
  dependsOn:
  - src/math/mod_pow.hpp
  isVerificationFile: false
  path: src/math/garner.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/garner.hpp
layout: document
redirect_from:
- /library/src/math/garner.hpp
- /library/src/math/garner.hpp.html
title: src/math/garner.hpp
---
