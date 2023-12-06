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
struct remove_reference {
    using type = T;
};

template <class T>
struct remove_reference<T &> {
    using type = T;
};

template <class T>
struct remove_reference<T &&> {
    using type = T;
};

template <class T>
using without_reference = remove_reference<T>::type;

template <class T>
using pure = without_const<without_reference<T>>;

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

template <class T, class U>
inline constexpr auto exchange( T & t, U && u ) -> T
{
    T temp = t;
    t = as_movable( u );
    return temp;
}

template <class T>
inline constexpr auto declval() noexcept -> T &
{
    // declval can only be used in non-evaluated context
    static_assert( false );
}

template <class T, size N>
inline constexpr auto array_size( T ( & /* a */ )[N] ) noexcept -> size
{
    return N;
}

} // namespace bb
