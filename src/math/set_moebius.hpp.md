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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../misc/bit_ops.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <vector>\n#include \"../misc/bit_ops.hpp\"\ntemplate<typename\
    \ T>\nstd::vector<T> set_moebius(const std::vector<T>& xs, const bool subset)\n\
    {\n    const int N = ceil2(xs.size());\n    std::vector<T> ys(N);\n    for (int\
    \ i = 0; i < (int)xs.size(); i++) { ys[i] = xs[i]; }\n    for (int i = 1; i <\
    \ N; i <<= 1) {\n        for (int j = 0; j < N; j++) {\n            if ((j & i)\
    \ == 0) { (subset ? ys[j | i] : ys[j]) -= (subset ? ys[j] : ys[j | i]); }\n  \
    \      }\n    }\n    return ys;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/set_moebius.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/set_moebius.hpp
layout: document
redirect_from:
- /library/src/math/set_moebius.hpp
- /library/src/math/set_moebius.hpp.html
title: src/math/set_moebius.hpp
---
