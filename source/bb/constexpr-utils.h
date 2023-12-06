#pragma once

#include <bb/basic-types.h>
#include <bb/type-utils.h>

namespace bb
{

template <class T>
inline constexpr auto as_movable( T && v ) noexcept -> without_reference<T> &&
{
    return static_cast<without_reference<T> &&>( v );
}

template <class T>
inline constexpr auto as_forwarding( without_reference<T> & v ) noexcept -> T &&
{
    return static_cast<T &&>( v );
}

template <class T>
inline constexpr auto as_forwarding( without_reference<T> && v ) noexcept -> T &&
{
    return static_cast<T &&>( v );
}

template <class T, class U>
inline constexpr auto exchange( T & t, U && u ) -> T
{
    T temp = t;
    t = as_movable( u );
    return temp;
}

template <class T>
inline consteval auto declval() noexcept -> T &
{
    static_assert( false );
}

template <class T, size N>
inline constexpr auto array_size( T ( & /* a */ )[N] ) noexcept -> size
{
    return N;
}

} // namespace bb
