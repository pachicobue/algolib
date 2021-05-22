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
  bundledCode: "#line 2 \"src/math/complex.hpp\"\n#include <cmath>\n#include <iostream>\n\
    template<typename T>\nstruct complex\n{\n    constexpr complex() : real{T{0}},\
    \ imag{T{0}} {}\n    constexpr complex(const T r, const T i) : real{r}, imag{i}\
    \ {}\n    constexpr complex polar(const T r, const T s) { real = r * std::cos(s),\
    \ imag = r * std::sin(s); }\n    constexpr complex conj() const { return complex{real,\
    \ -imag}; }\n    constexpr T norm() const { return real * real + imag * imag;\
    \ }\n    constexpr T abs() const { return std::sqrt(norm()); }\n    constexpr\
    \ T arg() const { return std::atan2(imag, real); }\n    complex operator-() {\
    \ return complex{-real, -imag}; }\n    complex operator+(const complex& c) const\
    \ { return complex{*this} += c; }\n    complex operator-(const complex& c) const\
    \ { return complex{*this} -= c; }\n    complex operator*(const complex& c) const\
    \ { return complex{real * c.real - imag * c.imag, real * c.imag + imag * c.real};\
    \ }\n    complex operator/(const complex& c) const { return (*this) * c.conj()\
    \ / c.norm(); }\n    complex operator+(const T v) const { return complex{*this}\
    \ += v; }\n    complex operator-(const T v) const { return complex{*this} -= v;\
    \ }\n    complex operator*(const T v) const { return complex{*this} *= v; }\n\
    \    complex operator/(const T v) const { return complex{*this} /= v; }\n    friend\
    \ complex operator+(const T v, const complex& c) { return complex{v + c.real,\
    \ c.imag}; }\n    friend complex operator-(const T v, const complex& c) { return\
    \ complex{v - c.real, -c.imag}; }\n    friend complex operator*(const T v, const\
    \ complex& c) { return complex{v * c.real, v * c.imag}; }\n    friend complex\
    \ operator/(const T v, const complex& c) { return v * c.conj() / c.norm(); }\n\
    \    complex& operator+=(const complex& c) { return real += c.real, imag += c.imag,\
    \ *this; }\n    complex& operator-=(const complex& c) { return real -= c.real,\
    \ imag -= c.imag, *this; }\n    complex& operator*=(const complex& c) { return\
    \ (*this) = (*this) * c; }\n    complex& operator/=(const complex& c) { return\
    \ (*this) = (*this) / c; }\n    complex& operator+=(const T v) { return real +=\
    \ v, *this; }\n    complex& operator-=(const T v) { return real -= v, *this; }\n\
    \    complex& operator*=(const T v) { return real *= v, imag *= v, *this; }\n\
    \    complex& operator/=(const T v) { return real /= v, imag /= v, *this; }\n\
    \    bool operator==(const complex& c) const { return real == c.real and imag\
    \ == c.imag; }\n    bool operator!=(const complex& c) const { return not(*this\
    \ == c); }\n    friend std::ostream& operator<<(std::ostream& os, const complex&\
    \ c) { return os << c.real << \"+\" << c.imag << \"I\"; }\n    T real, imag;\n\
    };\n"
  code: "#pragma once\n#include <cmath>\n#include <iostream>\ntemplate<typename T>\n\
    struct complex\n{\n    constexpr complex() : real{T{0}}, imag{T{0}} {}\n    constexpr\
    \ complex(const T r, const T i) : real{r}, imag{i} {}\n    constexpr complex polar(const\
    \ T r, const T s) { real = r * std::cos(s), imag = r * std::sin(s); }\n    constexpr\
    \ complex conj() const { return complex{real, -imag}; }\n    constexpr T norm()\
    \ const { return real * real + imag * imag; }\n    constexpr T abs() const { return\
    \ std::sqrt(norm()); }\n    constexpr T arg() const { return std::atan2(imag,\
    \ real); }\n    complex operator-() { return complex{-real, -imag}; }\n    complex\
    \ operator+(const complex& c) const { return complex{*this} += c; }\n    complex\
    \ operator-(const complex& c) const { return complex{*this} -= c; }\n    complex\
    \ operator*(const complex& c) const { return complex{real * c.real - imag * c.imag,\
    \ real * c.imag + imag * c.real}; }\n    complex operator/(const complex& c) const\
    \ { return (*this) * c.conj() / c.norm(); }\n    complex operator+(const T v)\
    \ const { return complex{*this} += v; }\n    complex operator-(const T v) const\
    \ { return complex{*this} -= v; }\n    complex operator*(const T v) const { return\
    \ complex{*this} *= v; }\n    complex operator/(const T v) const { return complex{*this}\
    \ /= v; }\n    friend complex operator+(const T v, const complex& c) { return\
    \ complex{v + c.real, c.imag}; }\n    friend complex operator-(const T v, const\
    \ complex& c) { return complex{v - c.real, -c.imag}; }\n    friend complex operator*(const\
    \ T v, const complex& c) { return complex{v * c.real, v * c.imag}; }\n    friend\
    \ complex operator/(const T v, const complex& c) { return v * c.conj() / c.norm();\
    \ }\n    complex& operator+=(const complex& c) { return real += c.real, imag +=\
    \ c.imag, *this; }\n    complex& operator-=(const complex& c) { return real -=\
    \ c.real, imag -= c.imag, *this; }\n    complex& operator*=(const complex& c)\
    \ { return (*this) = (*this) * c; }\n    complex& operator/=(const complex& c)\
    \ { return (*this) = (*this) / c; }\n    complex& operator+=(const T v) { return\
    \ real += v, *this; }\n    complex& operator-=(const T v) { return real -= v,\
    \ *this; }\n    complex& operator*=(const T v) { return real *= v, imag *= v,\
    \ *this; }\n    complex& operator/=(const T v) { return real /= v, imag /= v,\
    \ *this; }\n    bool operator==(const complex& c) const { return real == c.real\
    \ and imag == c.imag; }\n    bool operator!=(const complex& c) const { return\
    \ not(*this == c); }\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ complex& c) { return os << c.real << \"+\" << c.imag << \"I\"; }\n    T real,\
    \ imag;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/complex.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/complex.hpp
layout: document
redirect_from:
- /library/src/math/complex.hpp
- /library/src/math/complex.hpp.html
title: src/math/complex.hpp
---
