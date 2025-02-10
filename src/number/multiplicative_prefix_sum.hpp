#pragma once
#include "../internal.hpp"
#include "prime_power_sum.hpp"
template <typename T, typename F, u32 MAXD = 2> class MultiplicativePrefixSum : public PrimePowerSum<T, MAXD> {
    using PrimePowerSum<T>::id;
    using PrimePowerSum<T>::m_ps;
    using PrimePowerSum<T>::m_ns;
    using PrimePowerSum<T>::m_hss;
public:
    MultiplicativePrefixSum(u64 N, F f, const Arr<T, MAXD + 1>& coeffs)
        : PrimePowerSum<T>{N}, m_buf(m_ns.size(), 0), m_f{f} {
        for (u32 i : rep(m_buf.size())) {
            for (u32 d : rep(MAXD + 1)) {
                m_buf[i] += coeffs[d] * m_hss[d][i];
            }
        }
    }
    auto get(u64 n) const -> T {
        T ans = m_buf[id(n)] + 1;
        for (u32 i : rep(m_ps.size())) {
            ans += dfs(i, 1, m_ps[i], n / m_ps[i], 1);
        }
        return ans;
    }
private:
    auto dfs(u32 i, u32 c, u64 v, u64 lim, T fv) const -> T {
        T ans = fv * m_f(m_ps[i] * v, m_ps[i], c + 1);
        if (lim >= m_ps[i] * m_ps[i]) {
            ans += dfs(i, c + 1, m_ps[i] * v, lim / m_ps[i], fv);
        }
        fv *= m_f(v, m_ps[i], c);
        ans += fv * (m_buf[id(lim)] - m_buf[id(m_ps[i])]);
        for (u32 j = i + 1; j < m_ps.size() and m_ps[j] * m_ps[j] <= lim; j++) {
            ans += dfs(j, 1, m_ps[j], lim / m_ps[j], fv);
        }
        return ans;
    }
    Vec<T> m_buf;
    F m_f;
};
