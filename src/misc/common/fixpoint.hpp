#pragma once
#include "type_alias.hpp"
#pragma region FixPoint
template<typename F>
struct Fix : F
{
    Fix(F&& f) : F{std::forward<F>(f)} {}
    template<typename... Args>
    auto operator()(Args&&... args) const
    {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};
#pragma endregion
