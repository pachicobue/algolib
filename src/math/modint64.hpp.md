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
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include \"../misc/types.hpp\"\
    \nstruct modinfo64\n{\n    void set_mod(const u64 nmod) { mod = nmod; }\n    u64\
    \ mod;\n};\ntemplate<const modinfo64& info>\nclass modint64\n{\npublic:\n    static\
    \ constexpr const u64& mod = info.mod;\n    constexpr modint64() : m_val{0} {}\n\
    \    constexpr modint64(const ll v) : m_val{normll(v)} {}\n    constexpr void\
    \ set_raw(const u64 v) { m_val = v; }\n    constexpr modint64 operator+() const\
    \ { return *this; }\n    constexpr modint64 operator-() const { return modint64{0}\
    \ - (*this); }\n    constexpr modint64& operator+=(const modint64& m) { return\
    \ m_val = norm(m_val + m()), *this; }\n    constexpr modint64& operator-=(const\
    \ modint64& m) { return m_val = norm(m_val + mod - m()), *this; }\n    constexpr\
    \ modint64& operator*=(const modint64& m)\n    {\n        const i64 ans = m_val\
    \ * m.m_val - (i64)((f80)m_val * m.m_val / mod + 0.5) * mod;\n        return m_val\
    \  = (u64)(ans < 0 ? ans + mod : ans), *this;\n    }\n    constexpr modint64&\
    \ operator/=(const modint64& m) { return *this *= m.inv(); }\n    constexpr modint64\
    \ operator+(const modint64& m) const { return modint64{*this} += m; }\n    constexpr\
    \ modint64 operator-(const modint64& m) const { return modint64{*this} -= m; }\n\
    \    constexpr modint64 operator*(const modint64& m) const { return modint64{*this}\
    \ *= m; }\n    constexpr modint64 operator/(const modint64& m) const { return\
    \ modint64{*this} /= m; }\n    constexpr bool operator==(const modint64& m) const\
    \ { return m_val == m(); }\n    constexpr bool operator!=(const modint64& m) const\
    \ { return not(*this == m); }\n    friend std::istream& operator>>(std::istream&\
    \ is, modint64& m)\n    {\n        ll v;\n        return is >> v, m = v, is;\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const modint64&\
    \ m) { return os << m(); }\n    constexpr u64 get() const { return m_val; }\n\
    \    constexpr u64 operator()() const { return m_val; }\n    constexpr modint64\
    \ pow(u128 n) const\n    {\n        modint64 ans = 1;\n        for (modint64 x\
    \ = *this; n > 0; n >>= 1, x *= x) {\n            if (n & 1) { ans *= x; }\n \
    \       }\n        return ans;\n    }\n    constexpr modint64 inv() const { return\
    \ pow(mod - 2); }\n    modint64 sinv() const { return sinv(m_val); }\n    static\
    \ modint64 fact(const uint n)\n    {\n        static std::vector<modint64> fs{1,\
    \ 1};\n        for (uint i = (uint)fs.size(); i <= n; i++) { fs.push_back(fs.back()\
    \ * i); }\n        return fs[n];\n    }\n    static modint64 ifact(const uint\
    \ n)\n    {\n        static std::vector<modint64> ifs{1, 1};\n        for (uint\
    \ i = (uint)ifs.size(); i <= n; i++) { ifs.push_back(ifs.back() * sinv(i)); }\n\
    \        return ifs[n];\n    }\n    static modint64 perm(const int n, const int\
    \ k) { return k > n or k < 0 ? modint64{0} : fact(n) * ifact(n - k); }\n    static\
    \ modint64 comb(const int n, const int k) { return k > n or k < 0 ? modint64{0}\
    \ : fact(n) * ifact(n - k) * ifact(k); }\n\nprivate:\n    static constexpr u64\
    \ norm(const u64 x) { return x < mod ? x : x - mod; }\n    static constexpr u64\
    \ normll(const ll x) { return norm(u64(x % (ll)mod + (ll)mod)); }\n    static\
    \ modint64 sinv(const uint n)\n    {\n        static std::vector<modint64> is{1,\
    \ 1};\n        for (uint i = (uint)is.size(); i <= n; i++) { is.push_back(-is[mod\
    \ % i] * (mod / i)); }\n        return is[n];\n    }\n    u64 m_val;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/modint64.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/modint64.hpp
layout: document
redirect_from:
- /library/src/math/modint64.hpp
- /library/src/math/modint64.hpp.html
title: src/math/modint64.hpp
---
