#pragma once

#include <bb/constexpr-utils.h>

namespace bb
{

template <class T>
inline consteval auto is_noexcept_default_constructible() noexcept -> bool
{
    return noexcept( pure<T>{} );
}

template <class... Ts>
requires ( sizeof...( Ts ) > 0 )
inline consteval auto are_noexcept_default_constructible() noexcept -> bool
{
    return ( noexcept( pure<Ts>{} ) && ... );
}

//

template <class T>
inline consteval auto is_noexcept_destructible() noexcept -> bool
{
    return noexcept( declval<pure<T> &>().~pure<T>() );
}

template <class... Ts>
inline consteval auto are_noexcept_destructible() noexcept -> bool
{
    return ( noexcept( declval<pure<Ts> &>().~pure<Ts>() ) && ... );
}

//

template <class T, class... Args>
inline consteval auto is_noexcept_constructible( Args &&... args ) noexcept -> bool
{
    return noexcept( pure<T>{ as_forwarding<args>( args )... } );
}

//

template <class T>
inline consteval auto is_noexcept_copy_constructible() noexcept -> bool
{
    return noexcept( pure<T>( declval<pure<T> const &>() ) );
}

template <class... Ts>
inline consteval auto are_noexcept_copy_constructible() noexcept -> bool
{
    return ( noexcept( pure<Ts>( declval<pure<Ts> const &>() ) ) && ... );
}

//

template <class T>
inline consteval auto is_noexcept_move_constructible() noexcept -> bool
{
    return noexcept( pure<T>( as_movable( declval<pure<T>>() ) ) );
}

template <class... Ts>
inline consteval auto are_noexcept_move_constructible() noexcept -> bool
{
    return ( noexcept( pure<Ts>( as_movable( declval<pure<Ts>>() ) ) ) && ... );
}

//

template <class T>
inline consteval auto is_noexcept_copy_assignable() noexcept -> bool
{
    return noexcept( declval<pure<T> &>() = declval<pure<T> const &>() );
}

template <class... Ts>
inline consteval auto are_noexcept_copy_assignable() noexcept -> bool
{
    return ( noexcept( declval<pure<Ts> &>() = declval<pure<Ts> const &>() ) && ... );
}

//

template <class T>
inline consteval auto is_noexcept_move_assignable() noexcept -> bool
{
    return noexcept( declval<pure<T> &>() = as_movable( declval<pure<T>>() ) );
}

template <class... Ts>
inline consteval auto are_noexcept_move_assignable() noexcept -> bool
{
    return ( noexcept( declval<pure<Ts> &>() = as_movable( declval<pure<Ts>>() ) ) && ... );
}

//

template <class T>
inline consteval auto is_noexcept_eq_comparable() noexcept -> bool
{
    return noexcept( declval<pure<T> const>() == declval<pure<T> const>() );
}

template <class... Ts>
inline consteval auto are_noexcept_eq_comparable() noexcept -> bool
{
    return ( noexcept( declval<pure<Ts> const>() == declval<pure<Ts> const>() ) && ... );
}

} // namespace bb
