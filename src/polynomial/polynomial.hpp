#pragma once
#include "../common.hpp"
#include "../numerical/convolution.hpp"
template<typename mint>
class Polynomial : public Vec<mint>
{
    using Vec<mint>::resize;
    using Vec<mint>::push_back;
    using Vec<mint>::pop_back;
    using Vec<mint>::back;

public:
    using Vec<mint>::vector;
    Polynomial(const Vec<mint>& vs) : Vec<mint>{vs} { optimize(); }
    int size() const { return (int)Vec<mint>::size(); }
    int deg() const { return size() - 1; }
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
    Polynomial operator-() const
    {
        Polynomial ans = *this;
        for (auto& v : ans) { v = -v; }
        return ans;
    }
    Polynomial& operator+=(const Polynomial& f)
    {
        for (int i : rep(f.size())) { (*this)[i] += f[i]; }
        return *this;
    }
    Polynomial& operator-=(const Polynomial& f)
    {
        for (int i : rep(f.size())) { (*this)[i] -= f[i]; }
        return *this;
    }
    Polynomial& operator*=(const Polynomial& f) { return (*this) = (*this) * f; }
    Polynomial operator+(const Polynomial& f) const { return Polynomial(*this) += f; }
    Polynomial operator-(const Polynomial& f) const { return Polynomial(*this) -= f; }
    Polynomial operator*(const Polynomial& f) const { return mult(f, size() + f.size() - 1); }
    bool isZero() const { return (size() == 1) and ((*this)[0] == 0); }
    friend Ostream& operator<<(Ostream& os, const Polynomial& f)
    {
        return os << static_cast<Vec<mint>>(f);
    }
    Polynomial mult(const Polynomial& f) const { return Polynomial{convolute_mod(*this, f)}; }
    template<typename I>
    Polynomial pow(I n) const
    {
        return powerMonoid(*this, n, {1});
    }
    mint eval(const mint& x) const
    {
        mint ans = 0;
        mint p = 1;
        for (int i : rep(size())) {
            ans += p * (*this)[i];
            p *= x;
        }
        return ans;
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
