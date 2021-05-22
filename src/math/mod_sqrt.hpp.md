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
  code: "#pragma once\n#include \"../misc/types.hpp\"\n\ntemplate<typename mint>\n\
    mint modsqrt(const mint& A)\n{\n    const ull P = mint::mod;\n    if (A == 0)\
    \ { return 0; }\n    if (P == 2) { return 1; }\n    const ull h = (P - 1) >> 1;\n\
    \    if (A.pow(h)() != 1) { return 0; }\n\n    ull q = P - 1, Q = 0;\n    while\
    \ ((q & 1) == 0) { q >>= 1, Q++; }\n\n    mint Eraser = 1;\n    for (mint Z =\
    \ 2;; Z += 1) {\n        if (Z.pow(h) != 1) {\n            Eraser = Z.pow(q);\n\
    \            break;\n        }\n    }\n    mint Error = A.pow(q), X = A.pow((q\
    \ + 1) / 2);\n    while (Error() != 1) {\n        ull l       = 0;\n        mint\
    \ pError = Error;\n        for (ull i = 0; i < Q; i++, pError *= pError) {\n \
    \           if (pError() == 1) {\n                l = Q - i;\n               \
    \ break;\n            }\n        }\n        mint pEraser = Eraser;\n        for\
    \ (ull i = 0; i < l - 1; i++, pEraser *= pEraser) {}\n        X *= pEraser, Error\
    \ *= (pEraser * pEraser);\n    }\n    return X;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/mod_sqrt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/mod_sqrt.hpp
layout: document
redirect_from:
- /library/src/math/mod_sqrt.hpp
- /library/src/math/mod_sqrt.hpp.html
title: src/math/mod_sqrt.hpp
---
