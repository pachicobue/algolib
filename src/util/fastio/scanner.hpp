#pragma once
#include "../../common.hpp"
class Scanner
{
public:
    Scanner() { fillAll(m_memory, 0); }
    template<typename T>
    T val()
    {
        if (m_tail - m_head < 40) { diskRead(); }
        while (m_memory[m_head] < '0' and m_memory[m_head] != '-') { m_head++; }
        T ans{};
        if constexpr (std::is_arithmetic_v<T>) {
            m_head = std::from_chars(m_memory + m_head, m_memory + m_tail, ans).ptr - m_memory;
        } else {
            i64 x{};
            m_head = std::from_chars(m_memory + m_head, m_memory + m_tail, x).ptr - m_memory;
            ans = x;
        }
        return ans;
    }
    template<typename T>
    T val(T offset)
    {
        return val<T>() - offset;
    }
    template<typename T>
    Vec<T> vec(int n)
    {
        return genVec<T>(n, [&]() { return val<T>(); });
    }
    template<typename T>
    Vec<T> vec(int n, T offset)
    {
        return genVec<T>(n, [&]() { return val<T>(offset); });
    }
    template<typename T>
    Vec<Vec<T>> vvec(int n, int m)
    {
        return genVec<Vec<T>>(n, [&]() { return vec<T>(m); });
    }
    template<typename T>
    Vec<Vec<T>> vvec(int n, int m, const T offset)
    {
        return genVec<Vec<T>>(n, [&]() { return vec<T>(m, offset); });
    }
    template<typename... Args>
    auto tup()
    {
        return Tup<Args...>{val<Args>()...};
    }
    template<typename... Args>
    auto tup(const Args&... offsets)
    {
        return Tup<Args...>{val<Args>(offsets)...};
    }
    void debug() const
    {
        SHOW(m_head, m_tail);
        SHOW(std::string_view(m_memory, C));
    }

private:
    void diskRead()
    {
        std::copy(m_memory + m_head, m_memory + m_tail, m_memory);
        m_tail -= m_head, m_head = 0;
        m_tail += fread(m_memory + m_tail, 1, C - m_tail, stdin);
    }
    static constexpr int C = 1 << 20;
    int m_head = 0, m_tail = 0;
    char m_memory[C];
} in;
