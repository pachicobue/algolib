#pragma once
#include "../type.hpp"
#include "../macro.hpp"

template<typename Vs, typename V>
constexpr void fillAll(Vs& arr, const V& v)
{
    if constexpr (std::is_convertible<V, Vs>::value) {
        arr = v;
    } else {
        for (auto& subarr : arr) { fillAll(subarr, v); }
    }
}
