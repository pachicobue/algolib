#pragma once
#include "../common.hpp"
#include "../numerical/convolution.hpp"
template<typename mint>
class FormalPowerSeries : public Vec<mint>
{
    using Vec<mint>::resize;
    using Vec<mint>::push_back;
    using Vec<mint>::pop_back;
    using Vec<mint>::back;

public:
    using typename Vec<mint>::vector;
    FormalPowerSeries(const Vec<mint>& vs) : Vec<mint>{vs} { optimize(); }
    int size() const { return (int)Vec<mint>::size(); }
    int deg() const { return size() - 1; }
    template<typename I>
    void shrink(I n)
    {
        if (n >= (I)size()) { return; }
        Vec<mint>::resize(n);
        optimize();
    }
    template<typename I>
    FormalPowerSeries low(I n) const
    {
        const I sz = std::min(n, (I)size());
        return FormalPowerSeries{this->begin(), this->begin() + (int)sz};
    }
    mint& operator[](const int n)
    {
        if (n >= size()) { resize(n + 1, 0); }
        return Vec<mint>::operator[](n);
    }
    template<typename I>
    mint at(const I n) const
    {
        return (n < size() ? (*this)[n] : mint{0});
    }
    FormalPowerSeries operator-() const
    {
        FormalPowerSeries ans = *this;
        for (auto& v : ans) { v = -v; }
        return ans;
    }
    FormalPowerSeries& operator+=(const FormalPowerSeries& f)
    {
        for (int i : rep(f.size())) { (*this)[i] += f[i]; }
        return *this;
    }
    FormalPowerSeries& operator-=(const FormalPowerSeries& f)
    {
        for (int i : rep(f.size())) { (*this)[i] -= f[i]; }
        return *this;
    }
    FormalPowerSeries& operator*=(const FormalPowerSeries& f) { return (*this) = (*this) * f; }
    FormalPowerSeries& operator<<=(const int s) { return *this = (*this << s); }
    FormalPowerSeries& operator>>=(const int s) { return *this = (*this >> s); }
    FormalPowerSeries operator+(const FormalPowerSeries& f) const
    {
        return FormalPowerSeries(*this) += f;
    }
    FormalPowerSeries operator-(const FormalPowerSeries& f) const
    {
        return FormalPowerSeries(*this) -= f;
    }
    FormalPowerSeries operator*(const FormalPowerSeries& f) const
    {
        return mult(f, size() + f.size() - 1);
    }
    FormalPowerSeries operator>>(int shift) const
    {
        FormalPowerSeries ans(size() + shift);
        for (int i : rep(size())) { ans[i + shift] = (*this)[i]; }
        return ans;
    }
    FormalPowerSeries operator<<(int shift) const
    {
        FormalPowerSeries ans;
        for (int i : irange(shift, size())) { ans[i - shift] = (*this)[i]; }
        return ans;
    }
    int lsb() const
    {
        for (int i : rep(size())) {
            if ((*this)[i] != 0) { return i; }
        }
        return size();
    }
    bool isZero() const { return (size() == 1) and ((*this)[0] == 0); }
    friend Ostream& operator<<(Ostream& os, const FormalPowerSeries& f)
    {
        return os << static_cast<Vec<mint>>(f);
    }
    FormalPowerSeries derivative() const
    {
        FormalPowerSeries ans;
        for (int i : irange(1, size())) { ans[i - 1] = (*this)[i] * i; }
        return ans;
    }
    FormalPowerSeries integral() const
    {
        FormalPowerSeries ans;
        for (int i : irange(1, size() + 1)) { ans[i] = (*this)[i - 1] * mint::sinv(i); }
        return ans;
    }
    FormalPowerSeries mult(const FormalPowerSeries& f, int size) const
    {
        assert(size > 0);
        return FormalPowerSeries{convolute_mod(*this, f)}.low(size);
    }
    FormalPowerSeries inv(int size) const
    {
        assert(size > 0);
        assert((*this)[0].val() != 0);
        FormalPowerSeries g{(*this)[0].inv()};
        for (int m = 1; m < size; m *= 2) {
            auto f = low(m * 2);
            g = (FormalPowerSeries{2} - f.mult(g, m * 2)).mult(g, 2 * m);
        }
        return g.low(size);
    }
    FormalPowerSeries log(int size) const
    {
        assert(size > 0);
        assert((*this)[0] == 1);
        return derivative().mult(inv(size), size).integral().low(size);
    }
    FormalPowerSeries exp(int size) const
    {
        assert(size > 0);
        assert((*this)[0] == 0);
        FormalPowerSeries g{1};
        for (int m = 1; m < size; m *= 2) {
            auto f = low(m * 2);
            g = g.mult(FormalPowerSeries{1} - g.log(m * 2) + f, 2 * m);
        }
        return g.low(size);
    }
    template<typename I>
    FormalPowerSeries pow(I n) const
    {
        return pow(n, deg() * n + 1);
    }
    template<typename I>
    FormalPowerSeries pow(I n, int size) const
    {
        assert(size > 0);
        if (n == 0) { return FormalPowerSeries{1}; }
        if (isZero()) { return FormalPowerSeries{0}; }
        const int k = lsb();
        if (k >= ((I)size + n - 1) / n) { return FormalPowerSeries{}; }
        size -= k * n;
        auto f = ((*this) << k).low(size);
        const mint c = f[0];
        f *= FormalPowerSeries{c.inv()};
        return ((f.log(size) * FormalPowerSeries{n}).exp(size) * FormalPowerSeries{c.pow(n)})
               >> (k * n);
    }

private:
    const mint& operator[](const int n) const
    {
        assert(n < size());
        return Vec<mint>::operator[](n);
    }
    void optimize()
    {
        while (size() > 0) {
            if (back() != 0) { return; }
            pop_back();
        }
        if (size() == 0) { push_back(0); }
    }
};
