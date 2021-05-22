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
  code: "#pragma once\n#include \"../misc/types.hpp\"\n#include \"prime_enumerate.hpp\"\
    \ntemplate<typename T>\nstd::vector<T> divisors_zeta(const std::vector<T>& xs,\
    \ const bool subset)\n{\n    const int N = (int)xs.size();\n    auto ys     =\
    \ xs;\n    for (const i32 p : prime_enumerate(N)) {\n        if (subset) {\n \
    \           for (i32 i = 1; i * p < N; i++) { ys[i * p] += ys[i]; }\n        }\
    \ else {\n            for (i32 i = (N - 1) / p; i >= 1; i--) { ys[i] += ys[i *\
    \ p]; }\n        }\n    }\n    return ys;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/divisors_zeta.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/divisors_zeta.hpp
layout: document
redirect_from:
- /library/src/math/divisors_zeta.hpp
- /library/src/math/divisors_zeta.hpp.html
title: src/math/divisors_zeta.hpp
---
