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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/misc/common/show.hpp: line 5: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#pragma once\n#include <cassert>\n#include <cmath>\n#include <vector>\n#include\
    \ \"../math/complex.hpp\"\n#include \"../math/modint.hpp\"\n#include \"../misc/bit_ops.hpp\"\
    \n#include \"../misc/constants.hpp\"\ntemplate<typename R>\nclass fft\n{\nprivate:\n\
    \    static constexpr R pi  = pi_v<R>;\n    static constexpr int D = 30;\n   \
    \ static constexpr int B = 14;\n    static void trans(std::vector<complex<R>>&\
    \ as, const int lg, const bool rev)\n    {\n        const int N = as.size();\n\
    \        static std::vector<complex<R>> root[D];\n        if (root[lg].empty())\
    \ {\n            root[lg].resize(N);\n            for (int i = 0; i < N; i++)\
    \ {\n                const R theta = pi * R(2 * i) / R(N);\n                root[lg][i]\
    \   = complex<R>(std::cos(theta), std::sin(theta));\n            }\n        }\n\
    \        std::vector<complex<R>> tmp(N);\n        for (int w = (N >> 1); w > 0;\
    \ w >>= 1) {\n            for (int y = 0; y < (N >> 1); y += w) {\n          \
    \      const complex<R> r = rev ? root[lg][y].conj() : root[lg][y];\n        \
    \        for (int x = 0; x < w; x++) {\n                    const auto u = as[y\
    \ << 1 | x], v = as[y << 1 | x | w] * r;\n                    tmp[y | x] = u +\
    \ v, tmp[y | x | (N >> 1)] = u - v;\n                }\n            }\n      \
    \      std::swap(tmp, as);\n        }\n    }\n\npublic:\n    fft() = delete;\n\
    \    template<typename T, typename V = T>\n    static std::vector<V> convolute(const\
    \ std::vector<T>& as, const std::vector<T>& bs)\n    {\n        const int need\
    \ = as.size() + bs.size() - 1, lg = clog(need), sz = 1UL << lg;\n        std::vector<complex<R>>\
    \ xs(sz), ys(sz);\n        for (int i = 0; i < as.size(); i++) { xs[i] = {(R)as[i],\
    \ (R)0}; }\n        for (int i = 0; i < bs.size(); i++) { ys[i] = {(R)bs[i], (R)0};\
    \ }\n        trans(xs, lg, false), trans(ys, lg, false);\n        for (int i =\
    \ 0; i < sz; i++) { xs[i] *= ys[i]; }\n        trans(xs, lg, true);\n        std::vector<T>\
    \ ans(need);\n        for (int i = 0; i < need; i++) { ans[i] = (T)std::round(xs[i].real\
    \ / (R)sz); }\n        return ans;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/fft.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/fft.hpp
layout: document
redirect_from:
- /library/src/math/fft.hpp
- /library/src/math/fft.hpp.html
title: src/math/fft.hpp
---
