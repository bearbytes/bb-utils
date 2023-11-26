#pragma once

#include <bb/basic-types.h>

namespace bb
{

template <class T>
struct remove_const {
    using type = T;
};

template <class T>
struct remove_const<T const> {
    using type = T;
};

template <class T>
using without_const = typename remove_const<T>::type;

template <class T>
inline constexpr auto declval() noexcept -> T &
{
    static_assert( false );
}

template <class T>
inline constexpr auto is_noexcept_copy_constructible() noexcept -> bool
{
    return noexcept( T( declval<T const &>() ) );
}

template <class T>
inline constexpr auto is_noexcept_copy_assignable() noexcept -> bool
{
    return noexcept( declval<without_const<T> &>() = declval<T const &>() );
}

template <class T>
inline constexpr auto is_noexcept_eq_comparable() noexcept -> bool
{
    return noexcept( declval<T>() == declval<T>() );
}

template <class T, size N>
constexpr auto array_size( T ( & /* a */ )[N] ) -> size
{
    return N;
}

} // namespace bb
