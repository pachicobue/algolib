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
  bundledCode: "#line 2 \"src/math/prime_accum.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <vector>\ntemplate<typename T>\nclass\
    \ prime_count\n{\npublic:\n    prime_count(const T N) : N{N}, SQRT{sqrt(N)}, isp(SQRT\
    \ + 1, true)\n    {\n        assert(N >= 2);\n        init();\n        init_smalls();\n\
    \        init_larges();\n        for (int i = 0; i < pn; i++) {\n            const\
    \ int p = ps[i];\n            for (int j = nn; (j--) > 0;) {\n               \
    \ const T n = ns[j];\n                if (n < (T)p * (T)p) { break; }\n      \
    \          const T pn   = n / (T)p;\n                const int pj = rev(pn);\n\
    \                assert(C_smalls[p - 1] == i);\n                Cs[j] -= Cs[pj]\
    \ - C_smalls[p - 1];\n            }\n        }\n    }\n    T count(const T n)\
    \ const\n    {\n        const int i = rev(n);\n        assert(ns[i] == n);\n \
    \       return Cs[i];\n    }\n\nprivate:\n    static int sqrt(const T n)\n   \
    \ {\n        int ans = std::sqrt(n);\n        for (; (T)(ans + 1) * (T)(ans +\
    \ 1) <= n; ans++) {}\n        return ans;\n    }\n    void init()\n    {\n   \
    \     isp[0] = false, isp[1] = false;\n        for (int p = 2; p <= SQRT; p++)\
    \ {\n            if (not isp[p]) { continue; }\n            ps.push_back(p);\n\
    \            for (int q = p * 2; q <= SQRT; q += p) { isp[q] = false; }\n    \
    \    }\n        for (T p = 1; p * p <= N; p++) { ns.push_back(p), ns.push_back(N\
    \ / p); }\n        std::sort(ns.begin(), ns.end());\n        ns.erase(std::unique(ns.begin(),\
    \ ns.end()), ns.end());\n        pn = ps.size(), nn = ns.size();\n    }\n    void\
    \ init_smalls()\n    {\n        C_smalls.resize(SQRT + 1, 0);\n        for (int\
    \ n = 1; n <= SQRT; n++) {\n            if (not isp[n]) { continue; }\n      \
    \      C_smalls[n] = isp[n] ? (T)1 : (T)0;\n        }\n        for (int n = 1;\
    \ n <= SQRT; n++) { C_smalls[n] += C_smalls[n - 1]; }\n    }\n    void init_larges()\n\
    \    {\n        Cs.resize(nn, 0);\n        for (int i = 0; i < nn; i++) { Cs[i]\
    \ = (T)ns[i] - (T)1; }\n    }\n    int rev(const T n) const { return n <= SQRT\
    \ ? (int)(n - 1) : nn - (int)(N / n); }\n    T N = 0;\n    const int SQRT;\n \
    \   int pn, nn;\n    std::vector<bool> isp;\n    std::vector<int> ps;\n    std::vector<T>\
    \ ns;\n    std::vector<T> Cs;\n    std::vector<T> C_smalls;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <vector>\ntemplate<typename T>\nclass prime_count\n{\npublic:\n    prime_count(const\
    \ T N) : N{N}, SQRT{sqrt(N)}, isp(SQRT + 1, true)\n    {\n        assert(N >=\
    \ 2);\n        init();\n        init_smalls();\n        init_larges();\n     \
    \   for (int i = 0; i < pn; i++) {\n            const int p = ps[i];\n       \
    \     for (int j = nn; (j--) > 0;) {\n                const T n = ns[j];\n   \
    \             if (n < (T)p * (T)p) { break; }\n                const T pn   =\
    \ n / (T)p;\n                const int pj = rev(pn);\n                assert(C_smalls[p\
    \ - 1] == i);\n                Cs[j] -= Cs[pj] - C_smalls[p - 1];\n          \
    \  }\n        }\n    }\n    T count(const T n) const\n    {\n        const int\
    \ i = rev(n);\n        assert(ns[i] == n);\n        return Cs[i];\n    }\n\nprivate:\n\
    \    static int sqrt(const T n)\n    {\n        int ans = std::sqrt(n);\n    \
    \    for (; (T)(ans + 1) * (T)(ans + 1) <= n; ans++) {}\n        return ans;\n\
    \    }\n    void init()\n    {\n        isp[0] = false, isp[1] = false;\n    \
    \    for (int p = 2; p <= SQRT; p++) {\n            if (not isp[p]) { continue;\
    \ }\n            ps.push_back(p);\n            for (int q = p * 2; q <= SQRT;\
    \ q += p) { isp[q] = false; }\n        }\n        for (T p = 1; p * p <= N; p++)\
    \ { ns.push_back(p), ns.push_back(N / p); }\n        std::sort(ns.begin(), ns.end());\n\
    \        ns.erase(std::unique(ns.begin(), ns.end()), ns.end());\n        pn =\
    \ ps.size(), nn = ns.size();\n    }\n    void init_smalls()\n    {\n        C_smalls.resize(SQRT\
    \ + 1, 0);\n        for (int n = 1; n <= SQRT; n++) {\n            if (not isp[n])\
    \ { continue; }\n            C_smalls[n] = isp[n] ? (T)1 : (T)0;\n        }\n\
    \        for (int n = 1; n <= SQRT; n++) { C_smalls[n] += C_smalls[n - 1]; }\n\
    \    }\n    void init_larges()\n    {\n        Cs.resize(nn, 0);\n        for\
    \ (int i = 0; i < nn; i++) { Cs[i] = (T)ns[i] - (T)1; }\n    }\n    int rev(const\
    \ T n) const { return n <= SQRT ? (int)(n - 1) : nn - (int)(N / n); }\n    T N\
    \ = 0;\n    const int SQRT;\n    int pn, nn;\n    std::vector<bool> isp;\n   \
    \ std::vector<int> ps;\n    std::vector<T> ns;\n    std::vector<T> Cs;\n    std::vector<T>\
    \ C_smalls;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/prime_accum.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/prime_accum.hpp
layout: document
redirect_from:
- /library/src/math/prime_accum.hpp
- /library/src/math/prime_accum.hpp.html
title: src/math/prime_accum.hpp
---
