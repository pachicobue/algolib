#pragma once
#include "../misc/common.hpp"
#include "complex.hpp"
#include "modint.hpp"
template<typename R>
class FFT
{
private:
    static constexpr R pi = PI<R>;
    static constexpr int D = 30;
    static constexpr int B = 14;
    static void trans(Vec<complex<R>>& as, const int lg, const bool rev)
    {
        const int N = as.size();
        static Vec<complex<R>> root[D];
        if (root[lg].empty()) {
            root[lg].resize(N);
            for (int i = 0; i < N; i++) {
                const R theta = pi * R(2 * i) / R(N);
                root[lg][i] = complex<R>(std::cos(theta), std::sin(theta));
            }
        }
        Vec<complex<R>> tmp(N);
        for (int w = (N >> 1); w > 0; w >>= 1) {
            for (int y = 0; y < (N >> 1); y += w) {
                const complex<R> r = rev ? root[lg][y].conj() : root[lg][y];
                for (int x = 0; x < w; x++) {
                    const auto u = as[y << 1 | x], v = as[y << 1 | x | w] * r;
                    tmp[y | x] = u + v, tmp[y | x | (N >> 1)] = u - v;
                }
            }
            std::swap(tmp, as);
        }
    }

public:
    FFT() = delete;
    template<typename T, typename V = T>
    static Vec<V> convolute(const Vec<T>& as, const Vec<T>& bs)
    {
        const int need = as.size() + bs.size() - 1;
        const int lg = clog(need);
        const int sz = 1UL << lg;
        Vec<complex<R>> xs(sz), ys(sz);
        for (int i : rep(as.size())) {
            xs[i] = {(R)as[i], (R)0};
        }
        for (int i : rep(bs.size())) {
            ys[i] = {(R)bs[i], (R)0};
        }
        trans(xs, lg, false), trans(ys, lg, false);
        for (int i : rep(sz)) {
            xs[i] *= ys[i];
        }
        trans(xs, lg, true);
        Vec<T> ans(need);
        for (int i : rep(need)) {
            ans[i] = (T)std::round(xs[i].real / (R)sz);
        }
        return ans;
    }
};
