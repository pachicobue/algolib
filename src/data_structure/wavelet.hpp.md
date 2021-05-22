---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/misc/common.hpp
    title: src/misc/common.hpp
  - icon: ':warning:'
    path: src/misc/common/bit_ops.hpp
    title: src/misc/common/bit_ops.hpp
  - icon: ':warning:'
    path: src/misc/common/constants.hpp
    title: src/misc/common/constants.hpp
  - icon: ':warning:'
    path: src/misc/common/fixpoint.hpp
    title: src/misc/common/fixpoint.hpp
  - icon: ':warning:'
    path: src/misc/common/func_alias.hpp
    title: src/misc/common/func_alias.hpp
  - icon: ':warning:'
    path: src/misc/common/nd_vec.hpp
    title: src/misc/common/nd_vec.hpp
  - icon: ':warning:'
    path: src/misc/common/print/int128_t.hpp
    title: src/misc/common/print/int128_t.hpp
  - icon: ':warning:'
    path: src/misc/common/range.hpp
    title: src/misc/common/range.hpp
  - icon: ':warning:'
    path: src/misc/common/rng.hpp
    title: src/misc/common/rng.hpp
  - icon: ':warning:'
    path: src/misc/common/show.hpp
    title: src/misc/common/show.hpp
  - icon: ':warning:'
    path: src/misc/common/type_alias.hpp
    title: src/misc/common/type_alias.hpp
  - icon: ':warning:'
    path: src/misc/common/xoshiro.hpp
    title: src/misc/common/xoshiro.hpp
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
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/misc/common/show.hpp: line 5: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<int lg>\nclass Wavelet\n\
    {\npublic:\n    Wavelet(Vec<u64> vs) : m_size{(int)vs.size()}\n    {\n       \
    \ for (int i : rep(lg)) {\n            m_zns[i] = 0;\n            m_tables[i]\
    \ = FID(m_size);\n        }\n        Vec<u64> z(m_size), o(m_size);\n        int\
    \ zn = 0, on = 0;\n        for (int d : rep(lg)) {\n            zn = 0, on = 0;\n\
    \            for (int i : rep(m_size)) {\n                const bool b = btest(vs[i],\
    \ lg - d - 1);\n                m_tables[d].set(i, b);\n                (b ? o[on++]\
    \ : z[zn++]) = vs[i];\n            }\n            m_tables[d].build();\n     \
    \       m_zns[d] = zn;\n            std::swap(vs, z);\n            for (int i\
    \ : rep(on)) {\n                vs[zn + i] = o[i];\n            }\n        }\n\
    \    }\n    int lessThan(int l, int r, u64 v) const\n    {\n        assert(l <=\
    \ r);\n        int ans = 0;\n        for (int i : rep(lg)) {\n            const\
    \ int zl = m_tables[i].zero(l), zr = m_tables[i].zero(r);\n            const int\
    \ z = m_zns[i];\n            if (btest(v, lg - i - 1)) {\n                ans\
    \ += zr - zl;\n                l += z - zl, r += z - zr;\n            } else {\n\
    \                l = zl, r = zr;\n            }\n        }\n        return ans;\n\
    \    }\n    int rangeFreq(int l, int r, u64 vmin, u64 vsup) const\n    {\n   \
    \     return lessThan(l, r, vsup) - lessThan(l, r, vmin);\n    }\n    u64 quantile(int\
    \ l, int r, int n) const\n    {\n        assert(l <= r), assert(r - l > n);\n\
    \        u64 ans = 0;\n        for (int i : rep(lg)) {\n            const int\
    \ zl = m_tables[i].zero(l), zr = m_tables[i].zero(r);\n            const int z\
    \ = m_zns[i];\n            if (n >= zr - zl) {\n                ans += u64(1)\
    \ << (lg - i - 1);\n                l += z - zl, r += z - zr, n -= (zr - zl);\n\
    \            } else {\n                l = zl, r = zr;\n            }\n      \
    \  }\n        return ans;\n    }\nprivate:\n    static constexpr int bucket_size\
    \ = sizeof(u64) * 8;\n    static constexpr int bslog = log2p1(bucket_size) - 1;\n\
    \    static constexpr u64 bcut(const u64 n, const int l)\n    {\n        return\
    \ (l == 0 ? 0ULL : (n << (64 - l) >> (64 - l)));\n    }\n    static constexpr\
    \ int wind(const int n)\n    {\n        return n >> (bslog);\n    }\n    static\
    \ constexpr int bind(const int n)\n    {\n        return bcut(n, bslog);\n   \
    \ }\n    class FID\n    {\n    private:\n        int m_size, m_bn;\n        Vec<u64>\
    \ m_datas;\n        Vec<int> m_larges;\n    public:\n        FID() : m_size{0}\
    \ {}\n        FID(const int b)\n            : m_size{b},\n              m_bn{wind(m_size)\
    \ + 2},\n              m_datas(m_bn, 0),\n              m_larges(m_bn, 0)\n  \
    \      {}\n        void build()\n        {\n            for (int i : range(1,\
    \ m_larges.size())) {\n                m_larges[i] = m_larges[i - 1] + popcount(m_datas[i\
    \ - 1]);\n            }\n        }\n        bool operator[](const int n) const\n\
    \        {\n            return btest(m_datas[wind(n)], bind(n));\n        }\n\
    \        void set(const int n, const bool b)\n        {\n            m_datas[wind(n)]\
    \ |= u64{b} << bind(n);\n        }\n        int one(const int n) const\n     \
    \   {\n            return m_larges[wind(n)]\n                   + popcount(bcut(m_datas[wind(n)],\
    \ bind(n)));\n        }\n        int zero(const int n) const\n        {\n    \
    \        return n - one(n);\n        }\n    };\n    int m_size;\n    Arr<int,\
    \ lg> m_zns;\n    Arr<FID, lg> m_tables;\n};\n"
  dependsOn:
  - src/misc/common.hpp
  - src/misc/common/type_alias.hpp
  - src/misc/common/constants.hpp
  - src/misc/common/func_alias.hpp
  - src/misc/common/show.hpp
  - src/misc/common/print/int128_t.hpp
  - src/misc/common/bit_ops.hpp
  - src/misc/common/fixpoint.hpp
  - src/misc/common/nd_vec.hpp
  - src/misc/common/range.hpp
  - src/misc/common/rng.hpp
  - src/misc/common/xoshiro.hpp
  isVerificationFile: false
  path: src/data_structure/wavelet.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/wavelet.hpp
layout: document
redirect_from:
- /library/src/data_structure/wavelet.hpp
- /library/src/data_structure/wavelet.hpp.html
title: src/data_structure/wavelet.hpp
---
