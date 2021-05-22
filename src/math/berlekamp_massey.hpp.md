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
  bundledCode: "#line 2 \"src/math/berlekamp_massey.hpp\"\n#include <algorithm>\n\
    #include <vector>\ntemplate<typename T>\nstd::vector<T> berlekamp_massey(const\
    \ std::vector<T>& A)\n{\n    const int N = (int)A.size();\n    std::vector<T>\
    \ B{1}, C{1};\n    T b = 1;\n    for (int j = 1; j <= N; j++) {\n        int m\
    \ = (int)B.size(), l = (int)C.size();\n        T d = 0;\n        for (int i =\
    \ 0; i < l; i++) { d += A[j - l + i] * C[i]; }\n        B.push_back(0), m++;\n\
    \        if (d == 0) { continue; }\n        const T c = -d / b;\n        if (l\
    \ < m) {\n            auto temp = C;\n            C.insert(C.begin(), m - l, 0);\n\
    \            for (int i = 0; i < m; i++) { C[m - 1 - i] += c * B[m - 1 - i]; }\n\
    \            B = temp, b = d;\n        } else {\n            for (int i = 0; i\
    \ < m; i++) { C[l - 1 - i] += c * B[m - 1 - i]; }\n        }\n    }\n    return\
    \ std::reverse(C.begin(), C.end()), C;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\ntemplate<typename\
    \ T>\nstd::vector<T> berlekamp_massey(const std::vector<T>& A)\n{\n    const int\
    \ N = (int)A.size();\n    std::vector<T> B{1}, C{1};\n    T b = 1;\n    for (int\
    \ j = 1; j <= N; j++) {\n        int m = (int)B.size(), l = (int)C.size();\n \
    \       T d = 0;\n        for (int i = 0; i < l; i++) { d += A[j - l + i] * C[i];\
    \ }\n        B.push_back(0), m++;\n        if (d == 0) { continue; }\n       \
    \ const T c = -d / b;\n        if (l < m) {\n            auto temp = C;\n    \
    \        C.insert(C.begin(), m - l, 0);\n            for (int i = 0; i < m; i++)\
    \ { C[m - 1 - i] += c * B[m - 1 - i]; }\n            B = temp, b = d;\n      \
    \  } else {\n            for (int i = 0; i < m; i++) { C[l - 1 - i] += c * B[m\
    \ - 1 - i]; }\n        }\n    }\n    return std::reverse(C.begin(), C.end()),\
    \ C;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/berlekamp_massey.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/berlekamp_massey.hpp
layout: document
redirect_from:
- /library/src/math/berlekamp_massey.hpp
- /library/src/math/berlekamp_massey.hpp.html
title: src/math/berlekamp_massey.hpp
---
