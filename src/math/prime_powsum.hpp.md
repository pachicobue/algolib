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
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <cmath>\n#include\
    \ <vector>\n#include \"../misc/types.hpp\"\ntemplate<typename T>\nclass prime_powsum\n\
    {\npublic:\n    static constexpr u32 MAXD = 2;\n    prime_powsum(const u64 N)\
    \ : m_N{N}, m_sqrt{(u32)std::sqrt(N)}, m_ns{0}\n    {\n        assert(N >= 2);\n\
    \        for (u64 i = N; i > 0; i = N / (N / i + 1)) { m_ns.push_back(i); }\n\
    \        for (const auto n : m_ns) {\n            const T x = n;\n           \
    \ m_hss[0].push_back(x - 1);\n            m_hss[1].push_back(x * (x + 1) / 2 -\
    \ 1);\n            m_hss[2].push_back(x * (x + 1) * (x * 2 + 1) / 6 - 1);\n  \
    \      }\n        for (u32 x = 2; x <= m_sqrt; x++) {\n            if (m_hss[0][m_ns.size()\
    \ - x] == m_hss[0][m_ns.size() - x + 1]) { continue; }\n            m_ps.push_back(x);\n\
    \            const u64 y = (u64)x * x;\n            for (u32 i = 1; i < m_ns.size();\
    \ i++) {\n                const u64 n = m_ns[i];\n                if (n < y) {\
    \ break; }\n                const u32 j = (i * x <= m_sqrt ? i * x : m_ns.size()\
    \ - n / x);\n                const u32 k = m_ns.size() - x + 1;\n            \
    \    m_hss[0][i] -= (m_hss[0][j] - m_hss[0][k]);\n                m_hss[1][i]\
    \ -= (m_hss[1][j] - m_hss[1][k]) * x;\n                m_hss[2][i] -= (m_hss[2][j]\
    \ - m_hss[2][k]) * x * x;\n            }\n        }\n    }\n    T get(const u32\
    \ d, const u64 n) const\n    {\n        const u32 i = id(n);\n        assert(m_ns[i]\
    \ == n);\n        return m_hss[d][i];\n    }\n\nprotected:\n    u32 id(const u64\
    \ x) const { return x <= m_sqrt ? m_ns.size() - x : m_N / x; }\n\n    u64 m_N;\n\
    \    u32 m_sqrt;\n    std::vector<u64> m_ns, m_ps;\n    std::array<std::vector<T>,\
    \ MAXD + 1> m_hss;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/prime_powsum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/prime_powsum.hpp
layout: document
redirect_from:
- /library/src/math/prime_powsum.hpp
- /library/src/math/prime_powsum.hpp.html
title: src/math/prime_powsum.hpp
---
