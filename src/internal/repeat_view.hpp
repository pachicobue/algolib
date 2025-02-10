#pragma once
#include <concepts>
#include <iterator>
#include <ranges>
#include <type_traits>
#include "type.hpp"

/**
 * @brief 同じ値を繰り返すView
 *
 * @tparam T 要素型
 * @note C++23では std::ranges::repeat_view が追加される
 */
template <std::move_constructible T>
requires(std::is_object_v<T> && std::same_as<T, std::remove_cv_t<T>>)
class repeat_view : public std::ranges::view_interface<repeat_view<T>> {
public:
    struct Itr {
        const T& operator*() const {
            return *x;
        }
        Itr& operator++() {
            return (cnt++), *this;
        }
        Itr operator++(int) {
            return {cnt++, *x};
        }
        bool operator==(const Itr& itr) const {
            return cnt == itr.cnt;
        }
        using difference_type = i64;
        using value_type = T;
        using iterator_concept = std::input_iterator_tag;

        i64 cnt;
        const T* x;
    };
    repeat_view() = default;
    repeat_view(const T& x, i64 N)
        : m_x{x}, m_N{N} {
    }
    Itr begin() const {
        return {0, &m_x};
    }
    Itr end() const {
        return {m_N, &m_x};
    }
    i64 size() const {
        return m_N;
    }
private:
    T m_x;
    i64 m_N;
};
