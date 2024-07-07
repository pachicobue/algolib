#pragma once
#include <cassert>
#include "../internal.hpp"
#include "../utility/modint_2p61m1.hpp"
class RollingHash {
    using mint = modint_2p61m1;
public:
    template <typename V> RollingHash(const V& vs, i64 base)
        : m_size{(int)std::size(vs)}, m_ps(m_size + 1, 1), m_hs(m_size + 1, 0), m_base{base} {
        for (int i : irange(1, m_size + 1)) { m_ps[i] = m_ps[i - 1] * m_base, m_hs[i] = m_hs[i - 1] * m_base + vs[i - 1]; }
    }
    auto operator()(int l, int r) const -> u64 { return assert(0 <= l and l <= r and r <= m_size), (m_hs[r] - m_hs[l] * m_ps[r - l]).val(); }
private:
    int m_size;
    Vec<mint> m_ps, m_hs;
    mint m_base;
};
