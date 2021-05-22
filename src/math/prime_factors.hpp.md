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
  code: "#pragma once\n#include <map>\n#include <numeric>\n#include \"../misc/random.hpp\"\
    \n#include \"../misc/types.hpp\"\n#include \"is_prime.hpp\"\n\ntemplate<typename\
    \ mint>\nu64 pollard_rho(const u64 n)\n{\n    if (n % 2 == 0) { return 2; }\n\
    \    if (is_prime(n)) { return n; }\n    mint c;\n    auto f = [&](const mint\
    \ x) { return x * x + c; };\n    while (true) {\n        mint x, y, ys, q = 1;\n\
    \        y = rng.val<u64>(0, n - 2) + 2, c = rng.val<u64>(0, n - 2) + 2;\n   \
    \     u64 d            = 1;\n        constexpr u32 dk = 128;\n        for (u32\
    \ r = 1; d == 1; r <<= 1) {\n            x = y;\n            for (u32 i = 0; i\
    \ < r; i++) { y = f(y); }\n            for (u32 k = 0; k < r and d == 1; k +=\
    \ dk) {\n                ys = y;\n                for (u32 i = 0; i < dk and i\
    \ < r - k; i++) { q *= x - (y = f(y)); }\n                d = std::gcd((u64)q.get(),\
    \ n);\n            }\n        }\n        if (d == n) {\n            do {\n   \
    \             d = std::gcd(u64((x - (ys = f(ys))).get()), n);\n            } while\
    \ (d == 1);\n        }\n        if (d != n) { return d; }\n    }\n    return n;\n\
    }\n\nstd::map<u64, int> prime_factors(const u64 n)\n{\n    static moddinfo info;\n\
    \    static moddinfo64 info64;\n    using mint   = moddint<info>;\n    using mint64\
    \ = moddint64<info64>;\n    std::map<u64, int> ans;\n    auto fac = [&](auto self,\
    \ ull x) -> void {\n        while ((x & 1) == 0) { x >>= 1, ans[2]++; }\n    \
    \    if (x == 1) { return; }\n        u64 p;\n        if (x < (1ULL << 30)) {\n\
    \            info.set_mod(x);\n            p = pollard_rho<mint>(x);\n       \
    \ } else {\n            info64.set_mod(x);\n            p = pollard_rho<mint64>(x);\n\
    \        }\n        if (p == x) { return ans[p]++, void(0); }\n        self(self,\
    \ p), self(self, x / p);\n    };\n    return fac(fac, n), ans;\n}\n\nstd::vector<u64>\
    \ divisors(const u64 n)\n{\n    const auto fs = prime_factors(n);\n    std::vector<u64>\
    \ ds{1};\n    for (const auto& [p, e] : fs) {\n        u64 pe       = p;\n   \
    \     const u32 dn = ds.size();\n        for (i32 i = 0; i < e; i++, pe *= p)\
    \ {\n            for (u32 j = 0; j < dn; j++) { ds.push_back(ds[j] * pe); }\n\
    \        }\n    }\n    return ds;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/prime_factors.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/prime_factors.hpp
layout: document
redirect_from:
- /library/src/math/prime_factors.hpp
- /library/src/math/prime_factors.hpp.html
title: src/math/prime_factors.hpp
---
