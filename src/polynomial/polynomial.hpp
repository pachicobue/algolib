#pragma once
#include "../common.hpp"
#include "../numerical/convolution.hpp"
/**
 * @brief 多項式
 * 
 * @tparam modintのみサポート
 */
template<typename mint> class Polynomial : public Vec<mint>
{
    using Vec<mint>::resize;
    using Vec<mint>::push_back;
    using Vec<mint>::pop_back;
    using Vec<mint>::back;
public:
    using Vec<mint>::size;
    /**
     * @brief コンストラクタ
     * @attention 末尾かつ係数0の項は消されるので注意(x^0 の項は残す)
     * 
     * @param args Vec<T>のコンストラクタに渡す引数
     */
    Polynomial(const auto&... args) : Vec<mint>{args...} {}

    /**
     * @brief 数列としての参照(constのみ)
     * 
     * @return const Vec<T>& 数列としての参照
     */
    const Vec<mint>& asVec() const { return static_cast<const Vec<mint>&>(*this); }
    /**
     * @brief 次数
     * 
     * @return int deg(F)
     */
    int deg() const { return (int)size() - 1; }
    /**
     * @brief F(x) <- F(x) mod x^n
     * 
     * @param n 指数
     */
    void shrink(i64 n)
    {
        if (n >= (i64)size()) { return; }
        resize(n), normalize();
    }
    /**
     * @brief F(x) mod x^n
     * 
     * @param n 指数
     * @return Polynomial F(x) mod x^n
     */
    Polynomial low(i64 n) const
    {
        const int sz = (int)std::min(n, (i64)size());
        return Polynomial{this->begin(), this->begin() + (int)sz};
    }
    /**
     * @brief F(x)[x^n]
     * 
     * @param n 指数
     * @return T& F(x)[x^n]
     */
    mint& operator[](int n)
    {
        if (n >= (int)size()) { resize(n + 1, mint{}); }
        return Vec<mint>::operator[](n);
    }
    /**
     * @brief F(x)[x^n]
     * 
     * @param n 指数
     * @return T F(x)[x^n]
     */
    mint at(i64 n) const { return (n < (i64)size() ? (*this)[n] : mint{0}); }
    /**
     * @brief -F(x)
     * 
     * @param F
     * @return Polynomial -F(x)
     */
    friend Polynomial operator-(const Polynomial& F)
    {
        Polynomial ans = F;
        for (auto& v : ans) { v = -v; }
        return ans;
    }
    /**
     * @brief F(x) <- F(x)+G(x)
     * 
     * @param F 
     * @param G 
     * @return Polynomial& F(x)
     */
    friend Polynomial& operator+=(Polynomial& F, const Polynomial& G)
    {
        for (int i : rep(G.size())) { F[i] += G[i]; }
        return F;
    }
    /**
     * @brief F(x) <- F(x)-G(x)
     * 
     * @param F 
     * @param G 
     * @return Polynomial& F(x)
     */
    friend Polynomial& operator-=(Polynomial& F, const Polynomial& G)
    {
        for (int i : rep(G.size())) { F[i] -= G[i]; }
        return F;
    }
    /**
     * @brief F(x) <- F(x)*G(x)
     * 
     * @param F 
     * @param G 
     * @return Polynomial& F(x)
     */
    friend Polynomial& operator*=(Polynomial& F, const Polynomial& G) { return F = F * G; }
    /**
     * @brief F(x) <- F(x)/G(x) (余り付き除算)
     * 
     * @param F 
     * @param G 
     * @return Polynomial& F(x)/G(x)
     */
    friend Polynomial& operator/=(Polynomial& F, const Polynomial& G) { return F = F / G; }
    /**
     * @brief F(x) <- F(x)%G(x)
     * 
     * @param F 
     * @param G 
     * @return Polynomial& F(x)%G(x)
     */
    friend Polynomial& operator%=(Polynomial& F, const Polynomial& G) { return F = F % G; }
    /**
     * @brief F(x) <- F(x)/(x^s) (切り捨て)
     * @attention bitシフトと逆向きなので注意(1+x+x^2+x^3 という順で考える)
     * 
     * @param F 
     * @param s シフト幅
     * @return Polynomial& F F(x)
     */
    friend Polynomial& operator<<=(Polynomial& F, int s) { return F = (F << s); }
    /**
     * @brief F(x) <- F(x)*(x^s)
     * @attention bitシフトと逆向きなので注意(1+x+x^2+x^3 という順で考える)
     * 
     * @param F 
     * @param s シフト幅
     * @return Polynomial& F(x)
     */
    friend Polynomial& operator>>=(Polynomial& F, int s) { return F = (F >> s); }
    /**
     * @brief F(x)+G(x)
     * 
     * @param F 
     * @param G 
     * @return Polynomial F(x)+G(x)
     */
    friend Polynomial operator+(const Polynomial& F, const Polynomial& G)
    {
        auto ans{F};
        return ans += G;
    }
    /**
     * @brief F(x)-G(x)
     * 
     * @param F 
     * @param G 
     * @return Polynomial F(x)-G(x)
     */
    friend Polynomial operator-(const Polynomial& F, const Polynomial& G)
    {
        auto ans{F};
        return ans -= G;
    }
    /**
     * @brief F(x)*G(x)
     * 
     * @param F 
     * @param G 
     * @return Polynomial F(x)*G(x)
     */
    friend Polynomial operator*(const Polynomial& F, const Polynomial& G) { return Polynomial{convoluteMod(F, G)}; }
    /**
     * @brief F(x)/G(x) (余り付き除算)
     * 
     * @param F 
     * @param G 
     * @return Polynomial F(x)/G(x)
     */
    friend Polynomial operator/(const Polynomial& F, const Polynomial& G) { return quot(F, G); }
    /**
     * @brief F(x)%G(x)
     * 
     * @param F 
     * @param G 
     * @return Polynomial F(x)%G(x)
     */
    friend Polynomial operator%(const Polynomial& F, const Polynomial& G) { return F - G * (F / G); }
    /**
     * @brief F(x)/(x^s) (切り捨て)
     * @attention bitシフトと逆向きなので注意(1+x+x^2+x^3 という順で考える)
     * 
     * @param F 
     * @param s シフト幅
     * @return Polynomial F F(x)/(x^s)
     */
    friend Polynomial operator<<(const Polynomial& F, int s)
    {
        assert(s >= 0);
        Polynomial ans;
        for (int i : irange(s, (int)F.size())) { ans[i - s] = F[i]; }
        return ans;
    }
    /**
     * @brief F(x)*(x^s)
     * @attention bitシフトと逆向きなので注意(1+x+x^2+x^3 という順で考える)
     * 
     * @param F 
     * @param s シフト幅
     * @return Polynomial F F(x)*(x^s)
     */
    friend Polynomial operator>>(const Polynomial& F, int s)
    {
        assert(s >= 0);
        Polynomial ans;
        for (int i : rep(F.size())) { ans[i + s] = F[i]; }
        return ans;
    }
    /**
     * @brief order(F(x))
     * 
     * @return int order(F(x))
     */
    int order() const
    {
        for (int i : rep(size())) {
            if ((*this)[i] != 0) { return i; }
        }
        return size();
    }
    /**
     * @brief F(x)==0 かどうか
     * 
     * @return true F(x)==0
     * @return false F(x)!=0
     */
    bool isZero() const { return (size() == 1) and ((*this)[0] == 0); }
    /**
     * @brief (d/dx) F(x)
     * 
     * @return Polynomial (d/dx) F(x)
     */
    Polynomial derivative() const
    {
        Polynomial ans;
        for (int i : irange(1, (int)size())) { ans[i - 1] = (*this)[i] * i; }
        return ans;
    }
    /**
     * @brief \int_{x} F(x)
     * 
     * @return Polynomial \int_{x} F(x)
     */
    Polynomial integral() const
    {
        Polynomial ans;
        for (int i : irange(1, (int)size() + 1)) { ans[i] = (*this)[i - 1] / i; }
        return ans;
    }
    /**
     * @brief F(x)G(x)=1 (mod x^n) となる G(x)
     * 
     * @param n 
     * @return Polynomial G(x)
     */
    Polynomial inv(int n) const
    {
        assert(n >= 1);
        assert((*this)[0].val() != 0);
        Polynomial G{(*this)[0].inv()};
        for (int m = 1; m < n; m *= 2) {
            const auto F = low(m * 2);
            G            = ((-(F * G).low(m * 2) + Polynomial{2}) * G).low(2 * m);
        }
        return G.low(n);
    }
    /**
     * @brief log(F(x)) (mod x^n) = \sum_{1<=i<n} (1-F(x))^i/i (mod x^n)
     * @attention F(x)[x^0] == 1 が必要 (N次までの計算が無限級数になるので)
     * 
     * @param n
     * @return Polynomial log(F(x)) (mod x^n)
     */
    Polynomial log(int n) const
    {
        assert(n >= 1);
        if (n == 1) { return Polynomial{0}; }
        assert((*this)[0] == 1);
        return (low(n).derivative() * inv(n)).low(n - 1).integral();
    }
    /**
     * @brief exp(F(x)) (mod x^n) = \sum_{0<=i<n} F(x)^i/(i!) (mod x^n)
     * @attention F(x)[x^0] == 0 が必要 (N次までの計算が無限級数になるので)
     * 
     * @param size 
     * @return Polynomial exp(F(x)) (mod x^n)
     */
    Polynomial exp(int n) const
    {
        assert(n >= 1);
        assert((*this)[0] == 0);
        Polynomial G{1};
        for (int m = 1; m < n; m *= 2) {
            const auto F = low(m * 2);
            G            = (G * (F - G.log(m * 2) + Polynomial{1})).low(m * 2);
        }
        return G.low(n);
    }
    /**
     * @brief F(x)^k (mod x^n)
     * 
     * @param m 指数
     * @param n 
     * @return Polynomial 
     */
    Polynomial pow(i64 m, int n) const
    {
        assert(n >= 1);
        if (m == 0) { return Polynomial{1}; }
        if (isZero()) { return Polynomial{0}; }
        const int k = order();
        if ((i64)k >= ceilDiv((i64)n, m)) { return Polynomial{}; }
        n -= k * m;
        auto f       = ((*this) << k).low(n);
        const mint c = f[0];
        f *= Polynomial{c.inv()};
        return ((f.log(n) * Polynomial{m}).exp(n) * Polynomial{c.pow(m)}) >> (k * m);
    }
    /**
     * @brief G(x)=F(x+c) を満たす G(x)
     * 
     * @param c シフト幅
     * @return Polynomial G(x)=F(x+c) を満たす G(x)
     */
    Polynomial taylorShift(const mint& c) const
    {
        const int N = (int)size();
        Vec<mint> as(N), bs(N);
        for (mint ce = 1; int i : rep(N)) {
            as[i] = ce * mint::ifact(i), bs[i] = (*this)[i] * mint::fact(i);
            ce *= c;
        }
        auto cs = convoluteModReverse(as, bs);
        for (int i : rep(N)) { cs[i] *= mint::ifact(i); }
        return Polynomial{cs};
    }
    /**
     * @brief F(x)の値
     * 
     * @param x 
     * @return mint F(x)の値
     */
    mint eval(const mint& x) const
    {
        mint ans = 0;
        for (mint xe = 1; int i : rep(size())) { ans += xe * (*this)[i], xe *= x; }
        return ans;
    }
#ifdef HOGEPACHI
    friend Ostream& operator<<(Ostream& os, const Polynomial& f) { return os << f.asVec(); }
#endif
private:
    const mint& operator[](const int n) const { return assert(n < (int)size()), Vec<mint>::operator[](n); }
    static Polynomial quot(const Polynomial& F, const Polynomial& G)
    {
        const int A = (int)F.deg(), B = (int)G.deg();
        if (A < B) { return Polynomial{0}; }
        Polynomial Frev = F, Grev = G;
        seqReverse(Frev), seqReverse(Grev);
        Polynomial qrev = (Frev.low(A - B + 1) * Grev.inv(A - B + 1)).low(A - B + 1);
        return seqReverse(qrev), qrev;
    }
    void normalize()
    {
        while (size() > 0 and back() == 0) { pop_back(); }
        if (size() == 0) { push_back(0); }
    }
};
