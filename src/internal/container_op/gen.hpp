#pragma once
#include "../type.hpp"
#include "../macro.hpp"

template<typename T, typename F>
constexpr Vec<T> genVec(int n, F gen)
{
    Vec<T> ans;
    std::generate_n(std::back_inserter(ans), n, gen);
    return ans;
}
