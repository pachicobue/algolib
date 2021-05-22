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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../misc/types.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"factor_table.hpp\"\nstd::vector<int> moebius_table(const\
    \ int sup)\n{\n    const auto f_table = factor_table(sup);\n    auto moebius \
    \      = [&](int n) {\n        int ans = 1;\n        for (int prev = 1; n > 1;\
    \ prev = f_table[n], n /= prev, ans = -ans) {\n            if (prev == f_table[n])\
    \ { return 0; }\n        }\n        return ans;\n    };\n    std::vector<int>\
    \ ans(sup, 0);\n    for (int i = 1; i < sup; i++) { ans[i] = moebius(i); }\n \
    \   return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/moebius_table.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/moebius_table.hpp
layout: document
redirect_from:
- /library/src/math/moebius_table.hpp
- /library/src/math/moebius_table.hpp.html
title: src/math/moebius_table.hpp
---
