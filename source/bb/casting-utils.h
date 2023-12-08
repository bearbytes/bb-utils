#pragma once

#include <bb/type-utils.h>

namespace bb
{

template <class U, class T>
inline constexpr auto as( T v ) -> U
{
    return static_cast<U>( v );
}

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

} // namespace bb
