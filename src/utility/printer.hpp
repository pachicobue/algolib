#pragma once
#include "../common.hpp"
class Printer
{
public:
    Printer(Ostream& os = std::cout) : m_os{os} { m_os << std::fixed << std::setprecision(15); }
    template<typename... Args>
    int operator()(const Args&... args)
    {
        return dump(args...), 0;
    }
    template<typename... Args>
    int ln(const Args&... args)
    {
        return dump(args...), m_os << '\n', 0;
    }
    template<typename... Args>
    int el(const Args&... args)
    {
        return dump(args...), m_os << std::endl, 0;
    }
    int YES(bool b = true) { return ln(b ? "YES" : "NO"); }
    int NO(bool b = true) { return YES(not b); }
    int Yes(bool b = true) { return ln(b ? "Yes" : "No"); }
    int No(bool b = true) { return Yes(not b); }

private:
    template<typename T>
    void dump(const T& v)
    {
        m_os << v;
    }
    template<typename T>
    void dump(const Vec<T>& vs)
    {
        for (int i : rep(vs.size())) { m_os << (i ? " " : ""), dump(vs[i]); }
    }
    template<typename T>
    void dump(const Vec<Vec<T>>& vss)
    {
        for (int i : rep(vss.size())) { m_os << (i ? "\n" : ""), dump(vss[i]); }
    }
    template<typename T, typename... Ts>
    int dump(const T& v, const Ts&... args)
    {
        return dump(v), m_os << ' ', dump(args...), 0;
    }
    Ostream& m_os;
};
inline Printer out;
