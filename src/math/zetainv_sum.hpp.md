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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../misc/types.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <vector>\n#include \"../misc/types.hpp\"\ntemplate<typename T, typename\
    \ V>\nclass zetainv_sum\n{\npublic:\n    template<typename F, typename SumAccum>\n\
    \    zetainv_sum(const T N, F f, SumAccum sum_accum, int M = 0) : N{N}, SQRT{sqrt(N)},\
    \ MEMO{memo(N, M)}\n    {\n        init();\n        init_smalls(f), init_larges();\n\
    \        for (int i = 1; i < nn; i++) {\n            const int num = ns[i];\n\
    \            if (num <= MEMO) { continue; }\n            int n = 0;\n        \
    \    for (; n * n < N; n++) {}\n            V sum = sum_accum(N);\n          \
    \  for (int j = 2; j <= n; j++) { sum -= Vs[rev(N / (T)j)]; }\n            for\
    \ (int k = 1; k <= n; k++) {\n                const int j = rev(k);\n        \
    \        const int L = std::max(N / (k + 1), n), R = N / k;\n                if\
    \ (L < R) { sum -= (V)(R - L) * Vs[j]; }\n            }\n            Vs[i] = sum;\n\
    \        }\n    }\n    V operator()(const T n) const\n    {\n        const int\
    \ i = rev(n);\n        assert(ns[i] == n);\n        return Vs[i];\n    }\n\nprivate:\n\
    \    static int sqrt(const T n)\n    {\n        int ans = (int)std::sqrt(n);\n\
    \        for (; (T)(ans + 1) * (T)(ans + 1) <= n; ans++) {}\n        return ans;\n\
    \    }\n    static int memo(const T n, const int m)\n    {\n        if (m != 0)\
    \ { return m; }\n        int ans = (int)std::pow(n, double(2) / 3);\n        for\
    \ (; (T)ans * (T)ans * (T)ans < n * n; ans++) {}\n        return ans;\n    }\n\
    \    void init()\n    {\n        for (T p = 1; p * p <= N; p++) { ns.push_back(p),\
    \ ns.push_back(N / p); }\n        std::sort(ns.begin(), ns.end());\n        ns.erase(std::unique(ns.begin(),\
    \ ns.end()), ns.end());\n        nn = ns.size();\n    }\n    template<typename\
    \ F>\n    void init_smalls(const F& f)\n    {\n        V_smalls.resize(MEMO +\
    \ 1);\n        for (int i = 0; i <= MEMO; i++) { V_smalls[i] = f(i); }\n     \
    \   for (int i = 1; i <= MEMO; i++) { V_smalls[i] += V_smalls[i - 1]; }\n    }\n\
    \    void init_larges()\n    {\n        Vs.resize(nn, 0);\n        Vs[0] = V_smalls[1];\n\
    \        for (int i = 1; i < nn; i++) {\n            if (ns[i] > MEMO) { break;\
    \ }\n            Vs[i] = V_smalls[ns[i]];\n        }\n    }\n    int rev(const\
    \ T n) const { return n <= SQRT ? (int)(n - 1) : nn - (int)(N / n); }\n    T N\
    \ = 0;\n    const int SQRT, MEMO;\n    int nn;\n    std::vector<T> ns;  // \\\
    lfloor \\frac{N}{i} \\rfloor\n    std::vector<V> Vs;\n    std::vector<V> V_smalls;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/zetainv_sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/zetainv_sum.hpp
layout: document
redirect_from:
- /library/src/math/zetainv_sum.hpp
- /library/src/math/zetainv_sum.hpp.html
title: src/math/zetainv_sum.hpp
---
