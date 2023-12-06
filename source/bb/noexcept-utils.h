#pragma once

#include <bb/constexpr-utils.h>

namespace bb
{

template <class... Ts>
requires ( sizeof...( Ts ) > 0 )
inline consteval auto noexcept_default_constructible() noexcept -> bool
{
    return ( noexcept( pure<Ts>{} ) && ... );
}

template <class... Ts>
requires ( sizeof...( Ts ) > 0 )
inline consteval auto noexcept_destructible() noexcept -> bool
{
    return ( noexcept( declval<pure<Ts> &>().~pure<Ts>() ) && ... );
}

template <class T, class... Args>
inline consteval auto noexcept_constructible( Args &&... args ) noexcept -> bool
{
    return noexcept( pure<T>{ as_forwarding<args>( args )... } );
}

template <class... Ts>
requires ( sizeof...( Ts ) > 0 )
inline consteval auto noexcept_copy_constructible() noexcept -> bool
{
    return ( noexcept( pure<Ts>( declval<pure<Ts> const &>() ) ) && ... );
}

template <class... Ts>
requires ( sizeof...( Ts ) > 0 )
inline consteval auto noexcept_move_constructible() noexcept -> bool
{
    return ( noexcept( pure<Ts>( as_movable( declval<pure<Ts>>() ) ) ) && ... );
}

template <class... Ts>
requires ( sizeof...( Ts ) > 0 )
inline consteval auto noexcept_copy_assignable() noexcept -> bool
{
    return ( noexcept( declval<pure<Ts> &>() = declval<pure<Ts> const &>() ) && ... );
}

template <class... Ts>
requires ( sizeof...( Ts ) > 0 )
inline consteval auto noexcept_move_assignable() noexcept -> bool
{
    return ( noexcept( declval<pure<Ts> &>() = as_movable( declval<pure<Ts>>() ) ) && ... );
}

template <class... Ts>
requires ( sizeof...( Ts ) > 0 )
inline consteval auto noexcept_eq_comparable() noexcept -> bool
{
    return ( noexcept( declval<pure<Ts> const>() == declval<pure<Ts> const>() ) && ... ) &&
           ( noexcept( declval<pure<Ts> const>() != declval<pure<Ts> const>() ) && ... );
}

} // namespace bb
