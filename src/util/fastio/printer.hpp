#pragma once
#include "../../common.hpp"
class Printer
{
public:
    Printer() { fillAll(m_memory, 0); }
    ~Printer() { flush(); }
    template<typename... Args>
    int ln(const Args&... args)
    {
        return dump(args...), putChar('\n'), 0;
    }
    template<typename... Args>
    int el(const Args&... args)
    {
        return dump(args...), putChar('\n'), flush(), 0;
    }

private:
    void flush() { fwrite(m_memory, 1, m_tail, stdout), m_tail = 0; }
    void putChar(const char c) { m_memory[m_tail++] = c; }
    template<typename T>
    void dump(T v)
    {
        if (C - m_tail < 40) { flush(); }
        if constexpr (std::is_arithmetic_v<T>) {
            m_tail = std::to_chars(m_memory + m_tail, m_memory + C, v).ptr - m_memory;
        } else {
            m_tail = std::to_chars(m_memory + m_tail, m_memory + C, v.val()).ptr - m_memory;
        }
    }
    template<typename T>
    void dump(const std::vector<T>& vs)
    {
        for (int i : rep(vs.size())) {
            if (i > 0) { putChar(' '); }
            dump(vs[i]);
        }
    }
    template<typename T>
    void dump(const std::vector<std::vector<T>>& vss)
    {
        for (int i : rep(vss.size())) {
            if (i > 0) { putChar('\n'); }
            dump(vss[i]);
        }
    }
    template<typename T, typename... Args>
    void dump(const T& v, const Args&... args)
    {
        return dump(v), putChar(' '), dump(args...), void(0);
    }
    static constexpr int C = 1 << 20;
    int m_tail = 0;
    char m_memory[C];
} out;
