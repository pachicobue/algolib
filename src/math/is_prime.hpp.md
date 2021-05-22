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
  code: "#pragma once\n#include <vector>\n#include \"../misc/types.hpp\"\n#include\
    \ \"moddint.hpp\"\n#include \"moddint64.hpp\"\n\ntemplate<typename mint>\ninline\
    \ bool miller_rabin(const u64 n, const std::vector<u64>& as)\n{\n    auto d =\
    \ n - 1;\n    for (; (d & 1) == 0; d >>= 1) {}\n    for (const u64 a : as) {\n\
    \        if (n <= a) { break; }\n        auto s = d;\n        mint x = mint(a).pow(s);\n\
    \        while (x.get() != 1 and x.get() != n - 1 and s != n - 1) { x *= x, s\
    \ <<= 1; }\n        if (x.get() != n - 1 and s % 2 == 0) { return false; }\n \
    \   }\n    return true;\n}\ninline bool is_prime(const u64 n)\n{\n    static moddinfo\
    \ info;\n    static moddinfo64 info64;\n    using mint   = moddint<info>;\n  \
    \  using mint64 = moddint64<info64>;\n    if (n == 1) { return false; }\n    if\
    \ ((n & 1) == 0) { return n == 2; }\n    if (n < (1ULL << 30)) {\n        info.set_mod(n);\n\
    \        return miller_rabin<mint>(n, {2, 7, 61});\n    } else {\n        info64.set_mod(n);\n\
    \        return miller_rabin<mint64>(n, {2, 325, 9375, 28178, 450775, 9780504});\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/is_prime.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/is_prime.hpp
layout: document
redirect_from:
- /library/src/math/is_prime.hpp
- /library/src/math/is_prime.hpp.html
title: src/math/is_prime.hpp
---
