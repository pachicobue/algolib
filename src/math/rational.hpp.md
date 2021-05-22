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
  bundledCode: "#line 2 \"src/math/rational.hpp\"\n#include <cassert>\n#include <cmath>\n\
    #include <iostream>\n#include <numeric>\ntemplate<typename T>\nstruct rational\n\
    {\n    rational() : num{0}, den{1} {}\n    rational(const T n) : num{n}, den{1}\
    \ {}\n    rational(const T n, const T d) : num{n}, den{d}\n    {\n        if (den\
    \ < 0) { num = -num, den = -den; }\n        const T d = std::gcd(den, num);\n\
    \        num /= g, den /= g;\n    }\n    rational operator-() const\n    {\n \
    \       rational ans = *this;\n        ans.num      = -ans.num;\n        return\
    \ ans;\n    }\n    rational operator+(const rational& r) const\n    {\n      \
    \  if (den == 0) { return (*this); }\n        if (r.den == 0) { return r; }\n\
    \        const auto [n1, d1] = *this;\n        const auto [n2, d2] = r;\n    \
    \    const T d = std::lcm(d1, d2), n = n1 * (d / d1) + n2 * (d / d2);\n      \
    \  return {n, d};\n    }\n    rational operator-(const rational& r) const { return\
    \ (*this) + -r; }\n    rational operator*(const rational& r) const\n    {\n  \
    \      if (num == 0 or r.num == 0) { return 0; }\n        if (den == 0 or r.den\
    \ == 0) { return {(num > 0) * (r.num > 0), 0}; }\n        const auto [n1, d1]\
    \ = *this;\n        const auto [n2, d2] = r;\n        const T d = std::lcm(d1,\
    \ d2), n = n1 * (d / d1) + n2 * (d / d2);\n        return {n, d};\n    }\n   \
    \ T num, den;\n};\n// #include \"../misc/constants.hpp\"\n// template<typename\
    \ T>\n// class rational\n// {\n// private:\n//     T num, den;\n//     static\
    \ T comp(const rational& r1, const rational& r2) { return (r1 - r2).num; }\n\n\
    // public:\n//     friend rational operator+(const rational& r1, const rational&\
    \ r2)\n//     {\n//         const T n1 = (r1.den != 0 ? r1.num : r1.num < 0 ?\
    \ -inf_v<T> : inf_v<T>);\n//         const T n2 = (r2.den != 0 ? r2.num : r2.num\
    \ < 0 ? -inf_v<T> : inf_v<T>);\n//         if (r1.den == 0 or r2.den == 0) { return\
    \ rational{n1 + n2, (n1 + n2 == 0 ? T(1) : T(0))}; }\n//         const T D = std::lcm(r1.den,\
    \ r2.den), N = r1.num * (D / r1.den) + r2.num * (D / r2.den);\n//         return\
    \ rational{N, D};\n//     }\n//     friend rational operator+(const T v1, const\
    \ rational& r2) { return rational{v1} + r2; }\n//     friend rational operator+(const\
    \ rational& r1, const T v2) { return r1 + rational{v2}; }\n//     friend rational\
    \ operator-(const rational& r1, const rational& r2) { return r1 + (-r2); }\n//\
    \     friend rational operator-(const T v1, const rational& r2) { return rational{v1}\
    \ - r2; }\n//     friend rational operator-(const rational r1, const T v2) { return\
    \ r1 - rational{v2}; }\n//     friend rational operator*(const rational& r1, const\
    \ rational& r2)\n//     {\n//         const T g1 = std::gcd(r1.num, r2.den), g2\
    \ = std::gcd(r1.den, r2.num), D = (r1.den / g2) * (r2.den / g1), N = (r1.num /\
    \ g1) * (r2.num / g2);\n//         return rational{N, D};\n//     }\n//     friend\
    \ rational operator*(const T v1, const rational& r2) { return rational{v1} * r2;\
    \ }\n//     friend rational operator*(const rational& r1, const T v2) { return\
    \ r1 * rational{v2}; }\n//     friend rational operator/(const rational& r1, const\
    \ rational& r2) { return r1 * rational{r2.den, r2.num}; }\n//     friend rational\
    \ operator/(const T v1, const rational& r2) { return rational{v1} / r2; }\n//\
    \     friend rational operator/(const rational r1, const T v2) { return r1 / rational{v2};\
    \ }\n//     friend rational& operator+=(rational& r1, const rational& r2) { return\
    \ r1 = r1 + r2; }\n//     friend rational& operator+=(rational& r1, const T v2)\
    \ { return r1 = r1 + v2; }\n//     friend rational& operator-=(rational& r1, const\
    \ rational& r2) { return r1 = r1 - r2; }\n//     friend rational& operator-=(rational&\
    \ r1, const T v2) { return r1 = r1 - v2; }\n//     friend rational& operator*=(rational&\
    \ r1, const rational& r2) { return r1 = r1 * r2; }\n//     friend rational& operator*=(rational&\
    \ r1, const T v2) { return r1 = r1 * v2; }\n//     friend rational& operator/=(rational&\
    \ r1, const rational& r2) { return r1 = r1 / r2; }\n//     friend rational& operator/=(rational&\
    \ r1, const T v2) { return r1 = r1 / v2; }\n//     friend bool operator==(const\
    \ rational& r1, const rational& r2) { return r1.den == r2.den and r1.num == r2.num;\
    \ }\n//     friend bool operator==(const rational& r1, const T v2) { return r1.den\
    \ == T(1) and r1.num == v2; }\n//     friend bool operator==(const T v1, const\
    \ rational& r2) { return r2.den == T(1) and r2.num == v1; }\n//     friend bool\
    \ operator!=(const rational& r1, const rational& r2) { return not(r1 == r2); }\n\
    //     friend bool operator!=(const rational& r1, const T v2) { return not(r1\
    \ == v2); }\n//     friend bool operator!=(const T v1, const rational& r2) { return\
    \ not(v1 == r2); }\n//     friend bool operator<(const rational& r1, const rational&\
    \ r2) { return comp(r1, r2) < T(0); }\n//     friend bool operator<(const rational&\
    \ r1, const T v2) { return r1.num < r1.den * v2; }\n//     friend bool operator<(const\
    \ T v1, const rational& r2) { return v1 * r2.den < r2.num; }\n//     friend bool\
    \ operator>(const rational& r1, const rational& r2) { return comp(r2, r1) < T(0);\
    \ }\n//     friend bool operator>(const rational& r1, const T v2) { return r1.num\
    \ > r1.den * v2; }\n//     friend bool operator>(const T v1, const rational& r2)\
    \ { return v1 * r2.den > r2.num; }\n//     friend bool operator<=(const rational&\
    \ r1, const rational& r2) { return not(r1 > r2); }\n//     friend bool operator<=(const\
    \ rational& r1, const T v2) { return not(r1 > v2); }\n//     friend bool operator<=(const\
    \ T v1, const rational& r2) { return not(v1 > r2); }\n//     friend bool operator>=(const\
    \ rational& r1, const rational& r2) { return not(r1 < r2); }\n//     friend bool\
    \ operator>=(const rational& r1, const T v2) { return not(r1 < v2); }\n//    \
    \ friend bool operator>=(const T v1, const rational& r2) { return not(v1 < r2);\
    \ }\n//     friend std::ostream& operator<<(std::ostream& os, const rational&\
    \ r) { return os << r.num << \"/\" << r.den; }\n//     T n() const { return num;\
    \ }\n//     T d() const { return den; }\n// };\n"
  code: "#pragma once\n#include <cassert>\n#include <cmath>\n#include <iostream>\n\
    #include <numeric>\ntemplate<typename T>\nstruct rational\n{\n    rational() :\
    \ num{0}, den{1} {}\n    rational(const T n) : num{n}, den{1} {}\n    rational(const\
    \ T n, const T d) : num{n}, den{d}\n    {\n        if (den < 0) { num = -num,\
    \ den = -den; }\n        const T d = std::gcd(den, num);\n        num /= g, den\
    \ /= g;\n    }\n    rational operator-() const\n    {\n        rational ans =\
    \ *this;\n        ans.num      = -ans.num;\n        return ans;\n    }\n    rational\
    \ operator+(const rational& r) const\n    {\n        if (den == 0) { return (*this);\
    \ }\n        if (r.den == 0) { return r; }\n        const auto [n1, d1] = *this;\n\
    \        const auto [n2, d2] = r;\n        const T d = std::lcm(d1, d2), n = n1\
    \ * (d / d1) + n2 * (d / d2);\n        return {n, d};\n    }\n    rational operator-(const\
    \ rational& r) const { return (*this) + -r; }\n    rational operator*(const rational&\
    \ r) const\n    {\n        if (num == 0 or r.num == 0) { return 0; }\n       \
    \ if (den == 0 or r.den == 0) { return {(num > 0) * (r.num > 0), 0}; }\n     \
    \   const auto [n1, d1] = *this;\n        const auto [n2, d2] = r;\n        const\
    \ T d = std::lcm(d1, d2), n = n1 * (d / d1) + n2 * (d / d2);\n        return {n,\
    \ d};\n    }\n    T num, den;\n};\n// #include \"../misc/constants.hpp\"\n// template<typename\
    \ T>\n// class rational\n// {\n// private:\n//     T num, den;\n//     static\
    \ T comp(const rational& r1, const rational& r2) { return (r1 - r2).num; }\n\n\
    // public:\n//     friend rational operator+(const rational& r1, const rational&\
    \ r2)\n//     {\n//         const T n1 = (r1.den != 0 ? r1.num : r1.num < 0 ?\
    \ -inf_v<T> : inf_v<T>);\n//         const T n2 = (r2.den != 0 ? r2.num : r2.num\
    \ < 0 ? -inf_v<T> : inf_v<T>);\n//         if (r1.den == 0 or r2.den == 0) { return\
    \ rational{n1 + n2, (n1 + n2 == 0 ? T(1) : T(0))}; }\n//         const T D = std::lcm(r1.den,\
    \ r2.den), N = r1.num * (D / r1.den) + r2.num * (D / r2.den);\n//         return\
    \ rational{N, D};\n//     }\n//     friend rational operator+(const T v1, const\
    \ rational& r2) { return rational{v1} + r2; }\n//     friend rational operator+(const\
    \ rational& r1, const T v2) { return r1 + rational{v2}; }\n//     friend rational\
    \ operator-(const rational& r1, const rational& r2) { return r1 + (-r2); }\n//\
    \     friend rational operator-(const T v1, const rational& r2) { return rational{v1}\
    \ - r2; }\n//     friend rational operator-(const rational r1, const T v2) { return\
    \ r1 - rational{v2}; }\n//     friend rational operator*(const rational& r1, const\
    \ rational& r2)\n//     {\n//         const T g1 = std::gcd(r1.num, r2.den), g2\
    \ = std::gcd(r1.den, r2.num), D = (r1.den / g2) * (r2.den / g1), N = (r1.num /\
    \ g1) * (r2.num / g2);\n//         return rational{N, D};\n//     }\n//     friend\
    \ rational operator*(const T v1, const rational& r2) { return rational{v1} * r2;\
    \ }\n//     friend rational operator*(const rational& r1, const T v2) { return\
    \ r1 * rational{v2}; }\n//     friend rational operator/(const rational& r1, const\
    \ rational& r2) { return r1 * rational{r2.den, r2.num}; }\n//     friend rational\
    \ operator/(const T v1, const rational& r2) { return rational{v1} / r2; }\n//\
    \     friend rational operator/(const rational r1, const T v2) { return r1 / rational{v2};\
    \ }\n//     friend rational& operator+=(rational& r1, const rational& r2) { return\
    \ r1 = r1 + r2; }\n//     friend rational& operator+=(rational& r1, const T v2)\
    \ { return r1 = r1 + v2; }\n//     friend rational& operator-=(rational& r1, const\
    \ rational& r2) { return r1 = r1 - r2; }\n//     friend rational& operator-=(rational&\
    \ r1, const T v2) { return r1 = r1 - v2; }\n//     friend rational& operator*=(rational&\
    \ r1, const rational& r2) { return r1 = r1 * r2; }\n//     friend rational& operator*=(rational&\
    \ r1, const T v2) { return r1 = r1 * v2; }\n//     friend rational& operator/=(rational&\
    \ r1, const rational& r2) { return r1 = r1 / r2; }\n//     friend rational& operator/=(rational&\
    \ r1, const T v2) { return r1 = r1 / v2; }\n//     friend bool operator==(const\
    \ rational& r1, const rational& r2) { return r1.den == r2.den and r1.num == r2.num;\
    \ }\n//     friend bool operator==(const rational& r1, const T v2) { return r1.den\
    \ == T(1) and r1.num == v2; }\n//     friend bool operator==(const T v1, const\
    \ rational& r2) { return r2.den == T(1) and r2.num == v1; }\n//     friend bool\
    \ operator!=(const rational& r1, const rational& r2) { return not(r1 == r2); }\n\
    //     friend bool operator!=(const rational& r1, const T v2) { return not(r1\
    \ == v2); }\n//     friend bool operator!=(const T v1, const rational& r2) { return\
    \ not(v1 == r2); }\n//     friend bool operator<(const rational& r1, const rational&\
    \ r2) { return comp(r1, r2) < T(0); }\n//     friend bool operator<(const rational&\
    \ r1, const T v2) { return r1.num < r1.den * v2; }\n//     friend bool operator<(const\
    \ T v1, const rational& r2) { return v1 * r2.den < r2.num; }\n//     friend bool\
    \ operator>(const rational& r1, const rational& r2) { return comp(r2, r1) < T(0);\
    \ }\n//     friend bool operator>(const rational& r1, const T v2) { return r1.num\
    \ > r1.den * v2; }\n//     friend bool operator>(const T v1, const rational& r2)\
    \ { return v1 * r2.den > r2.num; }\n//     friend bool operator<=(const rational&\
    \ r1, const rational& r2) { return not(r1 > r2); }\n//     friend bool operator<=(const\
    \ rational& r1, const T v2) { return not(r1 > v2); }\n//     friend bool operator<=(const\
    \ T v1, const rational& r2) { return not(v1 > r2); }\n//     friend bool operator>=(const\
    \ rational& r1, const rational& r2) { return not(r1 < r2); }\n//     friend bool\
    \ operator>=(const rational& r1, const T v2) { return not(r1 < v2); }\n//    \
    \ friend bool operator>=(const T v1, const rational& r2) { return not(v1 < r2);\
    \ }\n//     friend std::ostream& operator<<(std::ostream& os, const rational&\
    \ r) { return os << r.num << \"/\" << r.den; }\n//     T n() const { return num;\
    \ }\n//     T d() const { return den; }\n// };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/rational.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/rational.hpp
layout: document
redirect_from:
- /library/src/math/rational.hpp
- /library/src/math/rational.hpp.html
title: src/math/rational.hpp
---
