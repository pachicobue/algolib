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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../misc/bit_ops.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <numeric>\n#include \"fps.hpp\"\ntemplate<typename\
    \ mint>\nfps<mint> lagrange_interpolate(const std::vector<mint> ys)\n{\n    const\
    \ int N = ys.size();\n    std::vector<mint> fs(N + 1);\n    std::iota(fs.begin(),\
    \ fs.end(), 0);\n    for (int i = 2; i <= N; i++) { fs[i] = fs[i - 1] * i; }\n\
    \n    std::vector<mint> as(N + 1);\n    for (int i = 0; i <= N; i++) {\n     \
    \   mint res = fs[i];\n        for (int j = 0; j < i; j++) { res -= as[i] * mint::fact(i)\
    \ * mint::ifact(i - j); }\n        as[i] = res * mint::ifact(i);\n    }\n    fps<mint>\
    \ ans, g{1};\n    for (int i = 0; i <= N; i++) {\n        ans += as[i] * g;\n\
    \        g *= fps<mint>{1, -i};\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/src/math/lagrange_interpolation.hpp
- /library/src/math/lagrange_interpolation.hpp.html
title: src/math/lagrange_interpolation.hpp
---
