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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../misc/random.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <vector>\n#include \"../misc/random.hpp\"\n#include\
    \ \"../misc/types.hpp\"\nclass rolling_hash\n{\npublic:\n    template<typename\
    \ InIt>\n    rolling_hash(const InIt first, const InIt last, const ull base_ \
    \ // = rng64((ull)2, mask61 - 1)\n                 ) : sz(std::distance(first,\
    \ last)), pow(sz + 1, 1), h(sz + 1, 0), base{base_}\n    {\n        for (int i\
    \ = 1; i <= sz; i++) { pow[i] = mod(mul(pow[i - 1], base)), h[i] = mod(mul(h[i\
    \ - 1], base) + *std::next(first, i - 1)); }\n    }\n    ull operator()(const\
    \ int l, const int r) const { return mod(h[r] + offset - mul(h[l], pow[r - l]));\
    \ }\n    template<typename C>\n    void push_back(const C c)\n    {\n        sz++;\n\
    \        pow.push_back(mod(mul(pow.back(), base)));\n        h.push_back(mod(mul(h.back(),\
    \ base) + c));\n    }\n\nprivate:\n    static constexpr ull mask30 = ((ull)1 <<\
    \ 30) - 1;\n    static constexpr ull mask31 = ((ull)1 << 31) - 1;\n    static\
    \ constexpr ull mask61 = ((ull)1 << 61) - 1;\n    static constexpr ull offset\
    \ = mask61 * 7;\n    static constexpr ull mod(const ull x)\n    {\n        const\
    \ ull y = (x >> 61) + (x & mask61);\n        return y >= mask61 ? y - mask61 :\
    \ y;\n    }\n    static constexpr ull mul(const ull x, const ull y)\n    {\n \
    \       const ull xh = x >> 31, xl = x & mask31;\n        const ull yh = y >>\
    \ 31, yl = y & mask31;\n        const ull z  = xl * yh + xh * yl;\n        const\
    \ ull zh = z >> 30, zl = z & mask30;\n        return xh * yh * 2 + zh + (zl <<\
    \ 31) + xl * yl;\n    }\n    int sz;\n    std::vector<ull> pow, h;\n    ull base;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/rolling_hash.hpp
layout: document
redirect_from:
- /library/src/string/rolling_hash.hpp
- /library/src/string/rolling_hash.hpp.html
title: src/string/rolling_hash.hpp
---
