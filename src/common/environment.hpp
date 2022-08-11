#pragma once
#ifdef HOGEPACHI
constexpr bool LOCAL = true;
#else
constexpr bool LOCAL = false;
#endif
constexpr bool OJ = not LOCAL;

template<typename T>
static constexpr T OjLocal(T oj, T local)
{
    return LOCAL ? local : oj;
}
