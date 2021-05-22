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
  code: "#pragma once\n#include <iostream>\n\n#include \"../misc/common.hpp\"\nstruct\
    \ modinfo\n{\n    void set_mod(const u32 nmod) { mod = nmod; }\n    u32 mod, root,\
    \ max2p;\n};\ntemplate<const modinfo& info>\nclass modint\n{\npublic:\n    static\
    \ constexpr const u32& mod   = info.mod;\n    static constexpr const u32& root\
    \  = info.root;\n    static constexpr const u32& max2p = info.max2p;\n\n    constexpr\
    \ modint() : m_val{0} {}\n    constexpr modint(const i64 v) : m_val{normll(v)}\
    \ {}\n    constexpr void set_raw(const u32 v) { m_val = v; }\n    constexpr modint\
    \ operator-() const { return modint{0} - (*this); }\n    constexpr modint& operator+=(const\
    \ modint& m) { return m_val = norm(m_val + m()), *this; }\n    constexpr modint&\
    \ operator-=(const modint& m) { return m_val = norm(m_val + mod - m()), *this;\
    \ }\n    constexpr modint& operator*=(const modint& m) { return m_val = normll((i64)m_val\
    \ * (i64)m() % (i64)mod), *this; }\n    constexpr modint& operator/=(const modint&\
    \ m) { return *this *= m.inv(); }\n    constexpr modint operator+(const modint&\
    \ m) const { return modint{*this} += m; }\n    constexpr modint operator-(const\
    \ modint& m) const { return modint{*this} -= m; }\n    constexpr modint operator*(const\
    \ modint& m) const { return modint{*this} *= m; }\n    constexpr modint operator/(const\
    \ modint& m) const { return modint{*this} /= m; }\n    constexpr bool operator==(const\
    \ modint& m) const { return m_val == m(); }\n    constexpr bool operator!=(const\
    \ modint& m) const { return not(*this == m); }\n    friend std::istream& operator>>(std::istream&\
    \ is, modint& m)\n    {\n        i64 v;\n        return is >> v, m = v, is;\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const modint& m)\
    \ { return os << m(); }\n    constexpr u32 get() const { return m_val; }\n   \
    \ constexpr u32 operator()() const { return m_val; }\n    template<typename Int>\n\
    \    constexpr modint pow(Int n) const { return power(*this, n); }\n    constexpr\
    \ modint inv() const { return pow(mod - 2); }\n    static modint sinv(const u32\
    \ n)\n    {\n        static std::vector<modint> is{1, 1};\n        for (u32 i\
    \ = (u32)is.size(); i <= n; i++) { is.push_back(-is[mod % i] * (mod / i)); }\n\
    \        return is[n];\n    }\n    static modint fact(const u32 n)\n    {\n  \
    \      static std::vector<modint> fs{1, 1};\n        for (u32 i = (u32)fs.size();\
    \ i <= n; i++) { fs.push_back(fs.back() * i); }\n        return fs[n];\n    }\n\
    \    static modint ifact(const u32 n)\n    {\n        static std::vector<modint>\
    \ ifs{1, 1};\n        for (u32 i = (u32)ifs.size(); i <= n; i++) { ifs.push_back(ifs.back()\
    \ * sinv(i)); }\n        return ifs[n];\n    }\n    static modint comb(const int\
    \ n, const int k) { return k > n or k < 0 ? modint{0} : fact(n) * ifact(n - k)\
    \ * ifact(k); }\n\nprivate:\n    static constexpr u32 norm(const u32 x) { return\
    \ x < mod ? x : x - mod; }\n    static constexpr u32 normll(const i64 x) { return\
    \ norm(u32(x % (i64)mod + (i64)mod)); }\n    u32 m_val;\n};\nconstexpr modinfo\
    \ modinfo_1000000007 = {1000000007, 5, 1};\nconstexpr modinfo modinfo_998244353\
    \  = {998244353, 3, 23};\nusing modint_1000000007              = modint<modinfo_1000000007>;\n\
    using modint_998244353               = modint<modinfo_998244353>;\n"
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
  path: src/math/modint.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/modint.hpp
layout: document
redirect_from:
- /library/src/math/modint.hpp
- /library/src/math/modint.hpp.html
title: src/math/modint.hpp
---
