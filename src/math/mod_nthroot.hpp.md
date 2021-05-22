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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data_structure/hashmap.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <cmath>\n\n#include \"../data_structure/hashmap.hpp\"\
    \n#include \"../misc/types.hpp\"\n#include \"extgcd.hpp\"\n#include \"prime_factors.hpp\"\
    \n\ntemplate<typename mint>\nmint mod_nthroot(mint A, ull k)\n{\n    const ull\
    \ P = mint::mod;\n    if (A == 0) { return 0; }\n    if (k == 0) { return A; }\n\
    \    const ull g = std::gcd(P - 1, k);\n    if (A.pow((P - 1) / g)() != 1) { return\
    \ 0; }\n    A = A.pow(inverse<ULL>(k / g, (P - 1) / g));\n\n    if (g == 1) {\
    \ return A; }\n    const auto fs = prime_factors(g);\n    for (const auto& [p,\
    \ e] : fs) {\n        ull pe = 1;\n        for (int i = 0; i < e; i++) { pe *=\
    \ p; }\n        ull q = P - 1, Q = 0;\n        while (q % p == 0) { q /= p, Q++;\
    \ }\n        const ull y = pe - inverse<ULL>(q, pe), z = ((ULL)y * q + 1) / (ULL)pe;\n\
    \        mint X = A.pow(z);\n        if ((int)Q == e) {\n            A = X;\n\
    \            continue;\n        }\n\n        mint Eraser = 1;\n        const ull\
    \ h = (P - 1) / p;\n        for (mint Z = 2;; Z += 1) {\n            if (Z.pow(h)\
    \ != 1) {\n                Eraser = Z.pow(q);\n                break;\n      \
    \      }\n        }\n        mint Error = A.pow((ULL)y * q);\n\n        mint pEraser\
    \ = Eraser;\n        for (ull i = 0; i < Q - 1; i++) { pEraser = pEraser.pow(p);\
    \ }\n        const mint ipEraser = pEraser.inv();\n\n        hashmap<ull, ull>\
    \ memo;\n        {\n            const ull M = std::max(1ULL, (ull)(std::sqrt(p)\
    \ * std::sqrt(Q - e))), B = std::max(1ULL, ((ull)p - 1) / M);\n            const\
    \ mint ppEraser = pEraser.pow(B);\n            mint prod           = 1;\n    \
    \        for (ull i = 0; i < p; i += B, prod *= ppEraser) { memo[prod()] = i;\
    \ }\n        }\n\n        while (Error() != 1) {\n            ull l       = 0;\n\
    \            mint pError = Error;\n            for (ull i = 0; i < Q; i++) {\n\
    \                const auto npError = pError.pow(p);\n                if (npError\
    \ == 1) {\n                    l = Q - (i + 1);\n                    break;\n\
    \                }\n                pError = npError;\n            }\n\n     \
    \       ull c = -1;\n            {\n                mint small = pError.inv();\n\
    \                for (ull j = 0;; j++, small *= ipEraser) {\n                \
    \    if (memo.count(small())) {\n                        const ull i = memo[small()];\n\
    \                        c           = i + j;\n                        break;\n\
    \                    }\n                }\n            }\n            auto pEraser2\
    \ = Eraser.pow(c);\n            for (ull i = 0; i < l - e; i++) { pEraser2 = pEraser2.pow(p);\
    \ }\n            X *= pEraser2, Error *= pEraser2.pow(pe);\n        }\n      \
    \  A = X;\n    }\n    return A;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/mod_nthroot.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/mod_nthroot.hpp
layout: document
redirect_from:
- /library/src/math/mod_nthroot.hpp
- /library/src/math/mod_nthroot.hpp.html
title: src/math/mod_nthroot.hpp
---
