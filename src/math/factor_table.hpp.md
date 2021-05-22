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
  code: "#pragma once\n#include <numeric>\n#include <vector>\n#include \"../misc/types.hpp\"\
    \nstd::vector<u32> factor_table(const u32 sup)\n{\n    std::vector<u32> fact(sup);\n\
    \    std::iota(fact.begin(), fact.end(), 0);\n    for (u32 i = 2; i < sup; i++)\
    \ {\n        if (fact[i] != i) { continue; }\n        for (u32 j = i + i; j <\
    \ sup; j += i) { fact[j] = i; }\n    }\n    return fact;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/factor_table.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/factor_table.hpp
layout: document
redirect_from:
- /library/src/math/factor_table.hpp
- /library/src/math/factor_table.hpp.html
title: src/math/factor_table.hpp
---
