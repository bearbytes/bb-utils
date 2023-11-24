#pragma once

#include <bb/basic-types.h>

namespace bb
{

template <class T>
inline constexpr auto as_size( T v ) noexcept -> size
{
    return static_cast<size>( v );
}

template <class T>
inline constexpr auto as_u8( T v ) noexcept -> u8
{
    return static_cast<u8>( v );
}

template <class T>
inline constexpr auto as_i8( T v ) noexcept -> i8
{
    return static_cast<i8>( v );
}

template <class T>
inline constexpr auto as_u16( T v ) noexcept -> u16
{
    return static_cast<u16>( v );
}

template <class T>
inline constexpr auto as_i16( T v ) noexcept -> i16
{
    return static_cast<i16>( v );
}

template <class T>
inline constexpr auto as_u32( T v ) noexcept -> u32
{
    return static_cast<u32>( v );
}

template <class T>
inline constexpr auto as_i32( T v ) noexcept -> i32
{
    return static_cast<i32>( v );
}

template <class T>
inline constexpr auto as_u64( T v ) noexcept -> u64
{
    return static_cast<u64>( v );
}

template <class T>
inline constexpr auto as_i64( T v ) noexcept -> i64
{
    return static_cast<i64>( v );
}

template <class T>
inline constexpr auto as_f32( T v ) noexcept -> f32
{
    return static_cast<f32>( v );
}

template <class T>
inline constexpr auto as_f64( T v ) noexcept -> f64
{
    return static_cast<f64>( v );
}

} // namespace bb
