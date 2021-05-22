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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../misc/types.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"prime_powsum.hpp\"\ntemplate<typename T, typename\
    \ F>\nclass multiplicative_sum : public prime_powsum<T>\n{\n    using prime_powsum<T>::id;\n\
    \    using prime_powsum<T>::m_ps;\n    using prime_powsum<T>::m_ns;\n    using\
    \ prime_powsum<T>::m_hss;\n\npublic:\n    static constexpr u32 MAXD = prime_powsum<T>::MAXD;\n\
    \    multiplicative_sum(const u64 N, F f, const std::array<T, MAXD + 1>& coeffs)\
    \ : prime_powsum<T>{N}, m_buf(m_ns.size(), 0), m_f{f}\n    {\n        for (u32\
    \ i = 0; i < m_buf.size(); i++) {\n            for (u32 d = 0; d <= MAXD; d++)\
    \ { m_buf[i] += coeffs[d] * m_hss[d][i]; }\n        }\n    }\n    T get(const\
    \ u64 n) const\n    {\n        T ans = m_buf[id(n)] + 1;\n        for (u32 i =\
    \ 0; i < m_ps.size(); i++) { ans += dfs(i, 1, m_ps[i], n / m_ps[i], 1); }\n  \
    \      return ans;\n    }\n\nprivate:\n    T dfs(const u32 i, const u32 c, const\
    \ u64 v, const u64 lim, T fv) const\n    {\n        T ans = fv * m_f(m_ps[i] *\
    \ v, m_ps[i], c + 1);\n        if (lim >= m_ps[i] * m_ps[i]) { ans += dfs(i, c\
    \ + 1, m_ps[i] * v, lim / m_ps[i], fv); }\n        fv *= m_f(v, m_ps[i], c);\n\
    \        ans += fv * (m_buf[id(lim)] - m_buf[id(m_ps[i])]);\n        for (u32\
    \ j = i + 1; j < m_ps.size() and m_ps[j] * m_ps[j] <= lim; j++) { ans += dfs(j,\
    \ 1, m_ps[j], lim / m_ps[j], fv); }\n        return ans;\n    }\n    std::vector<T>\
    \ m_buf;\n    F m_f;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/multiplicative_sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/multiplicative_sum.hpp
layout: document
redirect_from:
- /library/src/math/multiplicative_sum.hpp
- /library/src/math/multiplicative_sum.hpp.html
title: src/math/multiplicative_sum.hpp
---
