#pragma once

#include <bb/basic-types-utils.h>
#include <bb/basic-types.h>
#include <bb/restricted.h>

namespace bb
{

enum class byte : u8 {};

using bit_index = restricted<u8, 0, 7>;

inline constexpr auto as_byte( u8 b ) noexcept -> byte { return static_cast<byte>( b ); }

constexpr auto operator|( byte l, u8 r ) noexcept -> byte { return as_byte( as_u8( l ) | r ); }
constexpr auto operator|( byte l, byte r ) noexcept -> byte { return l | as_u8( r ); }
constexpr auto operator|=( byte & l, u8 r ) noexcept -> byte { return l = l | r; }
constexpr auto operator|=( byte & l, byte r ) noexcept -> byte { return l = l | r; }

constexpr auto operator&( byte l, u8 r ) noexcept -> byte { return as_byte( as_u8( l ) & r ); }
constexpr auto operator&( byte l, byte r ) noexcept -> byte { return l & as_u8( r ); }
constexpr auto operator&=( byte & l, u8 r ) noexcept -> byte { return l = l & r; }
constexpr auto operator&=( byte & l, byte r ) noexcept -> byte { return l = l & r; }

constexpr auto operator^( byte l, u8 r ) noexcept -> byte { return as_byte( as_u8( l ) ^ r ); }
constexpr auto operator^( byte l, byte r ) noexcept -> byte { return l ^ as_u8( r ); }
constexpr auto operator^=( byte & l, u8 r ) noexcept -> byte { return l = l ^ r; }
constexpr auto operator^=( byte & l, byte r ) noexcept -> byte { return l = l & r; }

// clang-format off
constexpr auto operator<<( byte b, bit_index n ) noexcept -> byte { return as_byte( as_u8( b ) << n ); }
constexpr auto operator>>( byte b, bit_index n ) noexcept -> byte { return as_byte( as_u8( b ) >> n ); }
// clang-format on
constexpr auto operator<<=( byte & b, bit_index n ) noexcept -> byte { return b = b << n; }
constexpr auto operator>>=( byte & b, bit_index n ) noexcept -> byte { return b = b >> n; }

constexpr auto operator~( byte b ) noexcept -> byte { return as_byte( ~as_u8( b ) ); }

} // namespace bb
