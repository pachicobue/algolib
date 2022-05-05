#pragma once
#include "../misc/common.hpp"
#include "convolution.hpp"

template<typename mint>
class FPS : public Vec<mint>
{
    using std::vector<mint>::resize;
    using std::vector<mint>::push_back;
    using std::vector<mint>::pop_back;
    using std::vector<mint>::back;

public:
    using std::vector<mint>::vector;
    using std::vector<mint>::size;
    FPS(const Vec<mint>& vs) : Vec<mint>{vs}
    {
        optimize();
    }
    int size() const
    {
        return std::vector<mint>::size();
    }
    int deg() const
    {
        return size() - 1;
    }
    void shrink(int n)
    {
        if (n >= size()) { return; }
        std::vector<mint>::resize(n);
        optimize();
    }
    FPS low(int n) const
    {
        return FPS{this->begin(), this->begin() + std::min(n, size())};
    }
    mint eval(const mint& x) const
    {
        mint ans = 0;
        mint power = 1;
        for (int i : rep(size())) {
            ans += power * (*this)[i];
            power *= x;
        }
        return ans;
    }
    mint& operator[](const int n)
    {
        if (n >= size()) { resize(n + 1, 0); }
        return Vec<mint>::operator[](n);
    }
    const mint& operator[](const int n) const
    {
        assert(n < size());
        return Vec<mint>::operator[](n);
    }
    template<typename I>
    mint at(const I n) const
    {
        return (n < size() ? (*this)[n] : mint{0});
    }
    FPS operator-() const
    {
        FPS ans = *this;
        for (auto& v : ans) {
            v = -v;
        }
        return ans;
    }
    FPS& operator+=(const FPS& f)
    {
        for (int i : rep(f.size())) {
            (*this)[i] += f[i];
        }
        return *this;
    }
    FPS& operator-=(const FPS& f)
    {
        for (int i : rep(f.size())) {
            (*this)[i] -= f[i];
        }
        return *this;
    }
    FPS& operator*=(const FPS& f)
    {
        return (*this) = (*this) * f;
    }
    FPS& operator<<=(const int s)
    {
        return *this = (*this << s);
    }
    FPS& operator>>=(const int s)
    {
        return *this = (*this >> s);
    }
    FPS operator+(const FPS& f) const
    {
        return FPS(*this) += f;
    }
    FPS operator-(const FPS& f) const
    {
        return FPS(*this) -= f;
    }
    FPS operator*(const FPS& f) const
    {
        return mult(f, size() + f.size() - 1);
    }
    FPS operator>>(const int s) const
    {
        FPS ans(size() + s);
        for (int i : rep(size())) {
            ans[i + s] = (*this)[i];
        }
        return ans;
    }
    FPS operator<<(const int s) const
    {
        FPS ans;
        for (int i : irange(s, size())) {
            ans[i - s] = (*this)[i];
        }
        return ans;
    }
    int lsb() const
    {
        for (int i : rep(size())) {
            if ((*this)[i] != 0) { return i; }
        }
        return size();
    }
    bool isZero() const
    {
        return (size() == 1) and ((*this)[0] == 0);
    }
    friend Ostream& operator<<(Ostream& os, const FPS& f)
    {
        return os << static_cast<Vec<mint>>(f);
    }

    FPS derivative() const
    {
        FPS ans;
        for (int i : irange(1, size())) {
            ans[i - 1] = (*this)[i] * i;
        }
        return ans;
    }
    FPS integral() const
    {
        FPS ans;
        for (int i : irange(1, size() + 1)) {
            ans[i] = (*this)[i - 1] * mint::sinv(i);
        }
        return ans;
    }
    FPS mult(const FPS& f, int sz) const
    {
        if (sz == 0) { return FPS{}; }
        return FPS{convolute_mod(*this, f)}.low(sz);
    }
    FPS inv(int sz) const
    {
        assert((*this)[0].val() != 0);
        FPS g{(*this)[0].inv()};
        for (int m = 1; m < sz; m *= 2) {
            auto f = low(m * 2);
            g = (FPS{2} - f.mult(g, m * 2)).mult(g, 2 * m);
        }
        return g.low(sz);
    }
    FPS log(const int sz) const
    {
        assert((*this)[0] == 1);
        return derivative().mult(inv(sz), sz).integral().low(sz);
    }
    FPS exp(const int sz) const
    {
        assert((*this)[0] == 0);
        FPS g{1};
        for (int m = 1; m < sz; m *= 2) {
            auto f = low(m * 2);
            g = g.mult(FPS{1} - g.log(m * 2) + f, 2 * m);
        }
        return g.low(sz);
    }
    FPS tshift(const mint& c) const
    {
        const int N = size();
        FPS f(N), d(N);
        for (int i : rep(N)) {
            d[i] = c.pow(N - 1 - i) * mint::ifact(N - 1 - i);
        }
        for (int i : rep(N)) {
            f[i] = (*this)[i] * mint::fact(i);
        }
        f = f * d;
        FPS g(N);
        for (int i : rep(N)) {
            g[i] = f[i + N - 1] * mint::ifact(i);
        }
        return g;
    }
    template<typename I>
    FPS pow(I n) const
    {
        return pow(n, deg() * n + 1);
    }
    template<typename I>
    FPS pow(I n, int sz) const
    {
        if (n == 0) { return FPS{1}; }
        if (isZero()) { return FPS{0}; }
        const int k = lsb();
        if (k >= ((I)sz + n - 1) / n) { return FPS{}; }
        sz -= k * n;
        auto f = ((*this) << k).low(sz);
        const mint c = f[0];
        f *= FPS{c.inv()};
        return ((f.log(sz) * FPS{n}).exp(sz) * FPS{c.pow(n)}) >> (k * n);
    }
    FPS quot(const FPS& g) const
    {
        assert(not g.isZero());
        const int N = size(), M = g.size();
        if (N < M) { return FPS{}; }
        const auto fR = reversed(), gR = g.rev();
        return fR.mult(gR.inv(N - M + 1), N - M + 1).rev();
    }
    FPS rem(const FPS& g) const
    {
        assert(not g.isZero());
        return (*this) - g * quot(g);
    }

private:
    void optimize()
    {
        while (size() > 0) {
            if (back() != 0) { return; }
            pop_back();
        }
        if (size() == 0) { push_back(0); }
    }
    FPS reversed() const
    {
        FPS ans = *this;
        reverseAll(ans);
        return ans;
    }
};
