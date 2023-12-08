#pragma once

#include <bb/basic-types.h>
#include <bb/casting-utils.h>

namespace bb
{

template <class T>
inline constexpr auto as_size( T v ) noexcept -> size
{
    return as<size>( v );
}

template <class T>
inline constexpr auto as_u8( T v ) noexcept -> u8
{
    return as<u8>( v );
}

template <class T>
inline constexpr auto as_i8( T v ) noexcept -> i8
{
    return as<i8>( v );
}

template <class T>
inline constexpr auto as_u16( T v ) noexcept -> u16
{
    return as<u16>( v );
}

template <class T>
inline constexpr auto as_i16( T v ) noexcept -> i16
{
    return as<i16>( v );
}

template <class T>
inline constexpr auto as_u32( T v ) noexcept -> u32
{
    return as<u32>( v );
}

template <class T>
inline constexpr auto as_i32( T v ) noexcept -> i32
{
    return as<i32>( v );
}

template <class T>
inline constexpr auto as_u64( T v ) noexcept -> u64
{
    return as<u64>( v );
}

template <class T>
inline constexpr auto as_i64( T v ) noexcept -> i64
{
    return as<i64>( v );
}

template <class T>
inline constexpr auto as_f32( T v ) noexcept -> f32
{
    return as<f32>( v );
}

template <class T>
inline constexpr auto as_f64( T v ) noexcept -> f64
{
    return as<f64>( v );
}

} // namespace bb
