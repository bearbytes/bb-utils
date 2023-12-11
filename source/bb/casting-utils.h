#pragma once

#include <bb/type-utils.h>

namespace bb
{

template <class To, class From>
concept convertible_to = requires ( From f ) { static_cast<To>( f ); };

//

template <class T, class U>
requires ( convertible_to<T, U> )
inline constexpr auto as( U v ) -> T
{
    return static_cast<T>( v );
}

//

template <class T>
inline constexpr auto as_const( T & v ) -> T const &
{
    return static_cast<T const &>( v );
}

template <class T>
inline constexpr auto as_const( T const & v ) -> T const &
{
    return v;
}

template <class T>
inline constexpr auto as_const( T * v ) -> T const *
{
    return static_cast<T const *>( v );
}

template <class T>
inline constexpr auto as_const( T const * v ) -> T const *
{
    return v;
}

//

template <class T>
inline constexpr auto as_mutable( T & v ) noexcept -> T &
{
    return v;
}

template <class T>
inline constexpr auto as_mutable( T const & v ) noexcept -> T &
{
    return const_cast<T &>( v );
}

template <class T>
inline constexpr auto as_mutable( T * v ) noexcept -> T *
{
    return v;
}

template <class T>
inline constexpr auto as_mutable( T const * v ) noexcept -> T *
{
    return const_cast<T *>( v );
}

//

template <class T, class U>
requires ( convertible_to<T *, U *> )
inline constexpr auto as_ptr_to( U * v ) noexcept -> T *
{
    return static_cast<T *>( v );
}

template <class T, class U>
requires ( convertible_to<T *, U *> )
inline constexpr auto as_ptr_to( U const * v ) noexcept -> T const *
{
    return static_cast<T const *>( v );
}

template <class T, class U>
inline constexpr auto as_ptr_to( U * v ) noexcept
{
    if constexpr ( is_volatile<U> ) {
        return reinterpret_cast<T volatile *>( v );
    } else {
        return reinterpret_cast<T *>( v );
    }
}

template <class T, class U>
inline constexpr auto as_ptr_to( U const * v ) noexcept
{
    if constexpr ( is_volatile<U> ) {
        return reinterpret_cast<T const volatile *>( v );
    } else {
        return reinterpret_cast<T const *>( v );
    }
}

//

template <class T>
requires ( !is_const<T> )
inline constexpr auto as_movable( T && v ) noexcept -> without_reference<T> &&
{
    return static_cast<without_reference<T> &&>( v );
}

//

template <class T>
requires ( !is_const<T> )
inline constexpr auto as_forwarding( without_reference<T> & v ) noexcept -> T &&
{
    return static_cast<T &&>( v );
}

template <class T>
requires ( !is_const<T> )
inline constexpr auto as_forwarding( without_reference<T> volatile & v ) noexcept -> T volatile &&
{
    return static_cast<T volatile &&>( v );
}

template <class T>
requires ( !is_const<T> )
inline constexpr auto as_forwarding( without_reference<T> && v ) noexcept -> T &&
{
    return static_cast<T &&>( v );
}

template <class T>
requires ( !is_const<T> )
inline constexpr auto as_forwarding( without_reference<T> volatile && v ) noexcept -> T volatile &&
{
    return static_cast<T volatile &&>( v );
}

} // namespace bb
