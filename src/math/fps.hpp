#pragma once
#include "../misc/common.hpp"
#include "modint.hpp"

template<typename mint>
class FPS : public Vec<mint>
{
public:
    using std::vector<mint>::vector;
    using std::vector<mint>::resize;
    FPS(const Vec<mint>& vs) : Vec<mint>{vs} {}
    int size() const
    {
        return Vec<mint>::size();
    }
    int deg() const
    {
        return size() - 1;
    }
    FPS low(int n) const
    {
        return FPS{this->begin(), this->begin() + std::min(n, size())};
    }
    FPS rev() const
    {
        FPS ans = *this;
        reverseAll(ans);
        return ans;
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
        if (size() < n + 1) { resize(n + 1); }
        return Vec<mint>::operator[](n);
    }
    const mint& operator[](const int n) const
    {
        return Vec<mint>::operator[](n);
    }
    mint at(const int n) const
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
    FPS operator<<(const int s) const
    {
        FPS ans(size() + s);
        for (int i = 0; i < size(); i++) {
            ans[i + s] = (*this)[i];
        }
        return ans;
    }
    FPS operator>>(const int s) const
    {
        FPS ans;
        for (int i : range(s, size())) {
            ans[i - s] = (*this)[i];
        }
        return ans;
    }
    friend Ostream& operator<<(Ostream& os, const FPS& f)
    {
        return os << static_cast<Vec<mint>>(f);
    }

    FPS derivative() const
    {
        FPS ans;
        for (int i = 1; i < size(); i++) {
            ans[i - 1] = (*this)[i] * i;
        }
        return ans;
    }
    FPS integral() const
    {
        FPS ans;
        for (int i = 1; i <= size(); i++) {
            ans[i] = (*this)[i - 1] * mint::sinv(i);
        }
        return ans;
    }
    FPS mult(const FPS& f, int sz) const
    {
        if (sz == 0) { return FPS{}; }
        const int N = std::min(size(), sz) + std::min(f.size(), sz) - 1;
        if (N <= 16) {
            FPS ans(sz);
            for (int i = 0; i < std::min(size(), sz); i++) {
                for (int j = 0; j < f.size() and i + j < sz; j++) {
                    ans[i + j] += (*this)[i] * f[j];
                }
            }
            return ans;
        } else if (N <= (1 << mint::max2p())) {
            auto ans = conv<mint>(*this, f, sz);
            return ans;
        } else {
            const auto cs1 = conv<submint1>(*this, f, sz);
            const auto cs2 = conv<submint2>(*this, f, sz);
            const auto cs3 = conv<submint3>(*this, f, sz);
            FPS ans((int)cs1.size());
            for (int i : rep(cs1.size())) {
                ans[i] = restore(cs1[i].val(), cs2[i].val(), cs3[i].val());
            }
            return ans;
        }
    }
    FPS smult(int p, const mint a, int sz)  // *(1+ax^p) (mod x^sz)
    {
        FPS ans = low(sz);
        for (int i = 0; i + p < sz; i++) {
            ans[i + p] += (*this)[i] * a;
        }
        return ans;
    }
    FPS sdiv(int p, const mint& a, int sz)  // *(1+ax^p)^(-1) (mod x^sz)
    {
        FPS ans = low(sz);
        for (int i = 0; i + p < sz; i++) {
            ans[i + p] -= ans[i] * a;
        }
        return ans;
    }
    FPS inv(int sz) const
    {
        const int n = size();
        assert((*this)[0].val() != 0);
        const int N = n * 2 - 1;
        if (N <= (1 << mint::max2p())) {
            FPS r{(*this)[0].inv()};
            for (int lg = 0, m = 1; m < sz; m <<= 1, lg++) {
                FPS f{this->begin(), this->begin() + std::min(n, 2 * m)};
                FPS g = r;
                f.resize(2 * m), g.resize(2 * m);
                trans(f, lg + 1, false), trans(g, lg + 1, false);
                for (int i : rep(2 * m)) {
                    f[i] *= g[i];
                }
                trans(f, lg + 1, true);
                std::fill(f.begin(), f.begin() + m, 0);
                trans(f, lg + 1, false);
                for (int i : rep(2 * m)) {
                    f[i] *= g[i];
                }
                trans(f, lg + 1, true);
                for (int i = m; i < std::min(2 * m, sz); i++) {
                    r[i] = -f[i];
                }
            }
            return r;
        } else {
            FPS g{(*this)[0].inv()};
            for (int lg = 0, m = 1; m < sz; m <<= 1, lg++) {
                g = FPS{2} * g - this->mult(g.mult(g, 2 * m), 2 * m);
            }
            return g.low(sz);
        }
    }
    FPS log(const int sz) const
    {
        assert((*this)[0].val() == 1);
        auto ans = derivative().mult(inv(sz), sz).integral();
        ans.resize(sz);
        return ans;
    }
    FPS exp(const int sz) const
    {
        const int l = lsb(sz);
        if (l == -1) { return FPS{1}.low(sz); }
        assert((*this)[0].val() == 0);

        const int n = size();
        const int N = n * 2 - 1;
        if (N <= (1 << mint::max2p())) {
            FPS f = {1, (*this)[1]}, g{1}, G{1, 1};
            for (int m = 2, lg = 1; m < sz; m <<= 1, lg++) {
                auto F = f;
                F.resize(2 * m), trans(F, lg + 1, false);
                FPS z(m);
                for (int i : rep(m)) {
                    z[i] = F[i] * G[i];
                }
                trans(z, lg, true);
                std::fill(z.begin(), z.begin() + m / 2, 0);
                trans(z, lg, false);
                for (int i : rep(m)) {
                    z[i] *= G[i];
                }
                trans(z, lg, true);
                for (int i : range(m / 2, m)) {
                    g[i] = -z[i];
                }
                G = g, G.resize(m * 2), trans(G, lg + 1, false);
                auto q = low(m).derivative();
                q.resize(m), trans(q, lg, false);
                for (int i : rep(m)) {
                    q[i] *= F[i];
                }
                trans(q, lg, true);
                const auto df = f.derivative();
                for (int i : rep(m - 1)) {
                    q[i] -= df[i];
                }
                q.resize(m * 2);
                for (int i : rep(m - 1)) {
                    q[m + i] = q[i], q[i] = 0;
                }
                trans(q, lg + 1, false);
                for (int i : rep(m * 2)) {
                    q[i] *= G[i];
                }
                trans(q, lg + 1, true);
                q.pop_back();
                q = q.integral();
                for (int i = m; i < std::min(size(), m * 2); i++) {
                    q[i] += (*this)[i];
                }
                std::fill(q.begin(), q.begin() + m, 0);
                trans(q, lg + 1, false);
                for (int i = 0; i < m * 2; i++) {
                    q[i] *= F[i];
                }
                trans(q, lg + 1, true);
                for (int i = m; i < 2 * m; i++) {
                    f[i] = q[i];
                }
            }
            return f.low(sz);
        } else {
            FPS f{1};
            for (int m = 1; m < sz; m <<= 1) {
                auto g = low(2 * m);
                g[0] += 1;
                f.resize(2 * m);
                g -= f.log(2 * m);
                g = f.mult(g, 2 * m);
                for (int i = m; i < std::min(2 * m, g.size()); i++) {
                    f[i] = g[i];
                }
            }
            return f.low(sz);
        }
    }
    template<typename I>
    FPS pow(I n) const
    {
        return pow(n, deg() * n + 1);
    }
    template<typename I>
    FPS pow(I n, int sz) const
    {
        if (n == 0) { return FPS{1}.low(sz); }
        if (size() == 0) { return FPS{}; }
        const int p = lsb((size() - 1) / n);
        if (p == -1) { return FPS{}; }
        const mint a = (*this)[p];
        FPS f = (*this) >> p;
        for (auto& c : f) {
            c /= a;
        }
        f = f.log(sz - p * n);
        for (auto& c : f) {
            c *= n;
        }
        f = f.exp(sz - p * n);
        FPS g;
        for (int i : rep(f.size())) {
            g[i + p * n] = f[i] * a.pow(n);
        }
        return g;
    }
    FPS tshift(const mint& c) const
    {
        const int N = size();
        FPS f(N), d(N);
        for (int i = 0; i < N; i++) {
            d[i] = c.pow(N - 1 - i) * mint::ifact(N - 1 - i);
        }
        for (int i = 0; i < N; i++) {
            f[i] = (*this)[i] * mint::fact(i);
        }
        f = f * d;
        FPS g(N);
        for (int i = 0; i < N; i++) {
            g[i] = f[i + N - 1] * mint::ifact(i);
        }
        return g;
    }
    FPS quot(const FPS& g) const
    {
        const int N = size(), M = g.size();
        if (N < M) { return FPS{}; }
        const auto fR = rev(), gR = g.rev();
        return fR.mult(gR.inv(N - M + 1), N - M + 1).rev();
    }
    FPS rem(const FPS& g) const
    {
        return (*this) - g * quot(g);
    }

private:
    int lsb() const
    {
        return lsb(deg());
    }
    int lsb(int sz) const
    {
        for (int p : rep(sz + 1)) {
            if ((*this)[p].val() != 0) { return p; }
        }
        return -1;
    }

    using submint1 = modint<469762049, 3, 26>;
    using submint2 = modint<167772161, 3, 25>;
    using submint3 = modint<754974721, 11, 24>;
    template<typename submint>
    static void trans(Vec<submint>& as, int lg, bool rev)
    {
        const int N = 1 << lg;
        assert((int)as.size() == N);
        Vec<submint> rs, irs;
        if (rs.empty()) {
            const submint r = submint(submint::root()), ir = r.inv();
            rs.resize(submint::max2p() + 1), irs.resize(submint::max2p() + 1);
            rs.back() = -r.pow((submint::mod() - 1) >> submint::max2p()),
            irs.back() = -ir.pow((submint::mod() - 1) >> submint::max2p());
            for (uint i = submint::max2p(); i >= 1; i--) {
                rs[i - 1] = -(rs[i] * rs[i]);
                irs[i - 1] = -(irs[i] * irs[i]);
            }
        }
        const auto drange = (rev ? rep(lg) : per(lg));
        for (const int d : drange) {
            const int width = 1 << d;
            submint e = 1;
            for (int i = 0, j = 1; i < N; i += width * 2, j++) {
                for (int l = i, r = i + width; l < i + width; l++, r++) {
                    if (rev) {
                        as[l] = as[l] + as[r], as[r] = (as[l] - as[r]) * e;
                        e *= irs[lsbp1(j) + 1];
                    } else {
                        as[l] = as[l] + as[r] * e, as[r] = as[l] - as[r] * e;
                        e *= rs[lsbp1(j) + 1];
                    }
                }
            }
        }
        if (rev) {
            const submint iN = submint{N}.inv();
            for (auto& a : as) {
                a *= iN;
            }
        }
    }
    template<typename submint>
    static Vec<submint> conv(const Vec<mint>& as, const Vec<mint>& bs, int sz)
    {
        const int M
            = std::min((int)as.size(), sz) + std::min((int)bs.size(), sz) - 1;
        const int lg = clog(M);
        const int L = 1 << lg;
        Vec<submint> As(L), Bs(L);
        for (int i = 0; i < std::min((int)as.size(), sz); i++) {
            As[i] = as[i].val();
        }
        for (int i = 0; i < std::min((int)bs.size(), sz); i++) {
            Bs[i] = bs[i].val();
        }
        trans(As, lg, false), trans(Bs, lg, false);
        for (int i : rep(L)) {
            As[i] *= Bs[i];
        }
        trans(As, lg, true);
        const int N = std::min(sz, (int)as.size() + (int)bs.size() - 1);
        As.resize(N);
        return As;
    }
    static constexpr submint2 ip1 = submint2{submint1::mod()}.inv();
    static constexpr submint3 ip2 = submint3{submint2::mod()}.inv();
    static constexpr submint3 ip1p2
        = submint3{submint1::mod()}.inv() * submint3{submint2::mod()}.inv();
    static constexpr mint p1 = mint{submint1::mod()};
    static constexpr mint p1p2 = mint{submint1::mod()} * mint{submint2::mod()};
    static constexpr mint restore(int x1, int x2, int x3)
    {
        const int k0 = x1;
        const int k1 = (ip1 * (x2 - k0)).val();
        const int k2 = (ip1p2 * (x3 - k0) - ip2 * k1).val();
        return p1p2 * k2 + p1 * k1 + k0;
    }
};
