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
  bundledCode: "#line 2 \"src/math/seg_sieve.hpp\"\n#include <numeric>\n#include <vector>\n\
    template<typename T>\nstd::vector<bool> seg_sieve(const T l, const T r, const\
    \ std::vector<T>& ps)\n{\n    std::vector<bool> ans(r - l);\n    std::iota(ans.begin(),\
    \ ans.end(), l);\n    if (l <= 0 and 0 < r) { ans[0 - l] = false; }\n    if (l\
    \ <= 1 and 1 < r) { ans[1 - l] = false; }\n    for (const T p : ps) {\n      \
    \  const T mq = std::max((l + p - 1) / p * p, p + p);\n        for (T q = mq;\
    \ q < r; q += p) { ans[q - l] = false; }\n    }\n    for (T p = l; p < r; p++)\
    \ {\n        if (not ans[p - l]) { continue; }\n        for (T q = p + p; q <\
    \ r; q += p) { ans[q - l] = false; }\n    }\n    return ans;\n}\ntemplate<typename\
    \ T>\nstd::vector<bool> seg_sieve(const T l, const T r)\n{\n    T sqrt = 1;\n\
    \    for (; (sqrt + 1) * (sqrt + 1) <= r; sqrt++) {}\n    std::vector<bool> isp(sqrt\
    \ + 1, true);\n    isp[0] = isp[1] = false;\n    std::vector<T> ps;\n    for (T\
    \ p = 2; p <= sqrt; p++) {\n        if (not isp[p]) { continue; }\n        ps.push_back(p);\n\
    \        for (T q = p + p; q <= sqrt; q += p) { isp[q] = false; }\n    }\n   \
    \ return seg_sieve(l, r, ps);\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\ntemplate<typename T>\n\
    std::vector<bool> seg_sieve(const T l, const T r, const std::vector<T>& ps)\n\
    {\n    std::vector<bool> ans(r - l);\n    std::iota(ans.begin(), ans.end(), l);\n\
    \    if (l <= 0 and 0 < r) { ans[0 - l] = false; }\n    if (l <= 1 and 1 < r)\
    \ { ans[1 - l] = false; }\n    for (const T p : ps) {\n        const T mq = std::max((l\
    \ + p - 1) / p * p, p + p);\n        for (T q = mq; q < r; q += p) { ans[q - l]\
    \ = false; }\n    }\n    for (T p = l; p < r; p++) {\n        if (not ans[p -\
    \ l]) { continue; }\n        for (T q = p + p; q < r; q += p) { ans[q - l] = false;\
    \ }\n    }\n    return ans;\n}\ntemplate<typename T>\nstd::vector<bool> seg_sieve(const\
    \ T l, const T r)\n{\n    T sqrt = 1;\n    for (; (sqrt + 1) * (sqrt + 1) <= r;\
    \ sqrt++) {}\n    std::vector<bool> isp(sqrt + 1, true);\n    isp[0] = isp[1]\
    \ = false;\n    std::vector<T> ps;\n    for (T p = 2; p <= sqrt; p++) {\n    \
    \    if (not isp[p]) { continue; }\n        ps.push_back(p);\n        for (T q\
    \ = p + p; q <= sqrt; q += p) { isp[q] = false; }\n    }\n    return seg_sieve(l,\
    \ r, ps);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/seg_sieve.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/seg_sieve.hpp
layout: document
redirect_from:
- /library/src/math/seg_sieve.hpp
- /library/src/math/seg_sieve.hpp.html
title: src/math/seg_sieve.hpp
---
