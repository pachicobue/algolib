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
  code: "#pragma once\n#include \"fps.hpp\"\ntemplate<typename mint>\nmint div_nth(fps<mint>\
    \ f, fps<mint> g, ll N)\n{\n    if (f.size() == 0) { return 0; }\n    const int\
    \ n = g.size();\n    int mi      = 0;\n    mint a;\n    for (int i = 0; i < n;\
    \ i++) {\n        if (g[i]() != 0) {\n            mi = i, a = g[i];\n        \
    \    break;\n        }\n    }\n    g >>= mi;\n    const mint ia = a.inv();\n \
    \   for (auto& c : f) { c *= ia; }\n    for (auto& c : g) { c *= ia; }\n    fps\
    \ p = f.quot(g);\n    f -= g * p, N += mi;\n    if (N < 0) { return 0; }\n   \
    \ const mint offset = p.at(N);\n    for (; N > 0; N >>= 1) {\n        fps mg =\
    \ g;\n        for (int i = 1; i < n; i += 2) { mg[i] = -mg[i]; }\n        const\
    \ auto fmg = f * mg;\n        const auto gmg = g * mg;\n        f.clear(), g.clear();\n\
    \        for (int i = 0; i < gmg.size(); i += 2) { g[i >> 1] = gmg[i]; }\n   \
    \     if (N % 2 == 0) {\n            for (int i = 0; i < fmg.size(); i += 2) {\
    \ f[i >> 1] = fmg[i]; }\n        } else {\n            for (int i = 1; i < fmg.size();\
    \ i += 2) { f[i >> 1] = fmg[i]; }\n        }\n    }\n    return offset + f.at(0);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/fps_div_nth.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/fps_div_nth.hpp
layout: document
redirect_from:
- /library/src/math/fps_div_nth.hpp
- /library/src/math/fps_div_nth.hpp.html
title: src/math/fps_div_nth.hpp
---
