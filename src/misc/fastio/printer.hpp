#pragma once
#include "../common.hpp"
#pragma region FastIO Printer
class printer
{
public:
    printer() {}
    template<typename... Args>
    int operator()(const Args&... args)
    {
        dump(args...);
        return 0;
    }
    template<typename... Args>
    int ln(const Args&... args)
    {
        dump(args...), putchar('\n');
        return 0;
    }

private:
    template<typename T>
    void dump(T v)
    {
        static char tmp[30];
        if (v < 0) {
            putchar('-');
            v = -v;
        }
        int i = 0;
        do {
            tmp[i++] = v % T{10} + '0';
            v /= T{10};
        } while (v);
        while (i) {
            putchar(tmp[--i]);
        }
    }
    void dump(bool b)
    {
        dump<int>(b);
    }
    void dump(char c)
    {
        putchar(c);
    }
    void dump(const Str& cs)
    {
        for (char c : cs) {
            dump(c);
        }
    }
    template<typename T>
    void dump(const Vec<T>& vs)
    {
        for (const int i : rep(vs.size())) {
            if (i) { putchar(' '); }
            dump(vs[i]);
        }
    }
    template<typename T>
    void dump(const Vec<Vec<T>>& vss)
    {
        for (const int i : rep(vss.size())) {
            if (i) { putchar('\n'); }
            dump(vss[i]);
        }
    }
    template<typename T, typename... Ts>
    int dump(const T& v, const Ts&... args)
    {
        dump(v), putchar(' '), dump(args...);
        return 0;
    }
    static inline void putchar(char c)
    {
        putchar_unlocked(c);
    }
} out;
#pragma endregion
