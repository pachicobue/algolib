#pragma once
#include "type.hpp"
template<typename F>
struct Fix : F
{
    constexpr Fix(F&& f) : F{std::forward<F>(f)} {}
    template<typename... Args>
    constexpr auto operator()(Args&&... args) const
    {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};
