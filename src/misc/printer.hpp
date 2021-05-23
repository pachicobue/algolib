#pragma once
#include "common.hpp"
#pragma region Printer
class Printer
{
public:
    Printer(Ostream& os = std::cout) : m_os{os}
    {
        m_os << std::fixed << std::setprecision(15);
    }
    template<typename... Args>
    int operator()(const Args&... args)
    {
        dump(args...);
        return 0;
    }
    template<typename... Args>
    int ln(const Args&... args)
    {
        dump(args...), m_os << '\n';
        return 0;
    }
    template<typename... Args>
    int el(const Args&... args)
    {
        dump(args...), m_os << std::endl;
        return 0;
    }

private:
    template<typename T>
    void dump(const T& v)
    {
        m_os << v;
    }
    template<typename T>
    void dump(const Vec<T>& vs)
    {
        for (const int i : rep(vs.size())) {
            m_os << (i ? " " : ""), dump(vs[i]);
        }
    }
    template<typename T>
    void dump(const Vec<Vec<T>>& vss)
    {
        for (const int i : rep(vss.size())) {
            m_os << (i ? "" : "\n"), dump(vss[i]);
        }
    }
    template<typename T, typename... Ts>
    int dump(const T& v, const Ts&... args)
    {
        dump(v), m_os << ' ', dump(args...);
        return 0;
    }
    Ostream& m_os;
};
Printer out;
#pragma endregion
