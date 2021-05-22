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
  code: "#pragma once\n#include \"set_hadamard.hpp\"\ntemplate<typename T>\nstd::vector<T>\
    \ xor_convolute(std::vector<T> f, std::vector<T> g)\n{\n    const int N = ceil2(std::max(f.size(),\
    \ g.size()));\n    f.resize(N), g.resize(N);\n    auto F = set_hadamard(f, false),\
    \ G = set_hadamard(g, false);\n    for (int i = 0; i < N; i++) { F[i] *= G[i];\
    \ }\n    return set_hadamard(F, true);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/xor_convolution.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/xor_convolution.hpp
layout: document
redirect_from:
- /library/src/math/xor_convolution.hpp
- /library/src/math/xor_convolution.hpp.html
title: src/math/xor_convolution.hpp
---
