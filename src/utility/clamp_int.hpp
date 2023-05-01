#pragma once
#include "../common.hpp"

template<typename T, T min, T max>
class ClampInt
{
public:
    ClampInt() : m_val{} {}
    ClampInt(T x) : m_val{std::clamp(x, min, max)} {}
    friend ClampInt operator+(const ClampInt& v, T x) { return ClampInt{v.m_val + x}; }
    friend ClampInt operator-(const ClampInt& v, T x) { return ClampInt{v.m_val - x}; }
    friend ClampInt operator*(const ClampInt& v, T x) { return ClampInt{mul(v.m_val, x)}; }
    friend ClampInt operator/(const ClampInt& v, T x) { return ClampInt{floorDiv(v.m_val, x)}; }
    friend ClampInt& operator+=(ClampInt& v, T x) { return v = v + x; }
    friend ClampInt& operator-=(ClampInt& v, T x) { return v = v - x; }
    friend ClampInt& operator*=(ClampInt& v, T x) { return v = v * x; }
    friend ClampInt& operator/=(ClampInt& v, T x) { return v = v / x; }
    friend Ostream& operator<<(Ostream& os, const ClampInt& v) { return os << v.m_val; }
    T val() const { return m_val; }

private:
    static T mul(T x, T y)
    {
        if (y < 0) { x *= -1, y *= -1; }
        const T xmin = ceilDiv(min, y);
        const T xmax = floorDiv(max, y);
        if (x < xmin) {
            return min;
        } else if (x > xmax) {
            return max;
        } else {
            return x * y;
        }
    }

    T m_val;
};
