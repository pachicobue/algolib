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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../misc/random.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"prime_factors.hpp\"\ntemplate<typename mint>\nmint\
    \ primitive_root()\n{\n    const auto p = mint::mod;\n    if (p == 2) { return\
    \ 1; }\n    const auto fs = prime_factors(p - 1);\n    for (mint g = 2;; g +=\
    \ 1) {\n        bool ok = true;\n        for (const auto& [p, n] : fs) {\n   \
    \         const auto per = (p - 1) / p;\n            if (g.pow(per)() == 1) {\n\
    \                ok = false;\n                break;\n            }\n        }\n\
    \        if (ok) { return g; }\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/primitive_root.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/primitive_root.hpp
layout: document
redirect_from:
- /library/src/math/primitive_root.hpp
- /library/src/math/primitive_root.hpp.html
title: src/math/primitive_root.hpp
---
