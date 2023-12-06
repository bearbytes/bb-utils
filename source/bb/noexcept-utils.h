#pragma once

#include <bb/constexpr-utils.h>

namespace bb
{

template <class T>
inline consteval auto is_noexcept_default_constructible() noexcept -> bool
{
    return noexcept( pure<T>{} );
}

template <class T>
inline consteval auto is_noexcept_destructible() noexcept -> bool
{
    return noexcept( declval<pure<T> &>().~pure<T>() );
}

template <class T>
inline consteval auto is_noexcept_copy_constructible() noexcept -> bool
{
    return noexcept( pure<T>( declval<pure<T> const &>() ) );
}

template <class T>
inline consteval auto is_noexcept_move_constructible() noexcept -> bool
{
    return noexcept( pure<T>( as_movable( declval<pure<T>>() ) ) );
}

template <class T>
inline consteval auto is_noexcept_copy_assignable() noexcept -> bool
{
    return noexcept( declval<pure<T> &>() = declval<pure<T> const &>() );
}

template <class T>
inline consteval auto is_noexcept_move_assignable() noexcept -> bool
{
    return noexcept( declval<pure<T> &>() = as_movable( declval<pure<T>>() ) );
}

template <class T>
inline consteval auto is_noexcept_eq_comparable() noexcept -> bool
{
    return noexcept( declval<pure<T> const>() == declval<pure<T> const>() );
}

} // namespace bb
