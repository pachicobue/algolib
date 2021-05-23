#pragma once
#include "../common.hpp"
#pragma region FastIO Scanner
class Scanner
{
public:
    Scanner() {}
    template<typename T>
    T val()
    {
        T ans = 0;
        bool neg = false;
        char c = getchar();
        if (c < '0') {
            neg = true;
        } else {
            ans = c - '0';
        }
        while (true) {
            c = getchar();
            if (c < '0') { break; }
            ans = ans * T{10} + (c - '0');
        }
        if (neg) { ans = -ans; }
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
    Vec<Vec<T>> vvec(int n, int m, T offset)
    {
        return genVec<Vec<T>>(n, [&]() { return vec<T>(m, offset); });
    }
    template<typename... Args>
    auto tup()
    {
        return std::tuple<Args...>{val<Args>()...};
    }
    template<typename... Args>
    auto tup(const Args&... offsets)
    {
        return std::tuple<Args...>{val<Args>(offsets)...};
    }

private:
    static inline char getchar()
    {
        return getchar_unlocked();
    }
} in;
template<>
char Scanner::val()
{
    return Scanner::getchar();
}
template<>
Str Scanner::val()
{
    Str ans;
    while (true) {
        const char c = Scanner::getchar();
        if (c == ' ' or c == '\n' or c == EOF) { break; }
        ans.push_back(c);
    }
    return ans;
}

// #pragma endregion
