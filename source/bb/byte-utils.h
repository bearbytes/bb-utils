#pragma once

#include <bb/array.h>
#include <bb/byte.h>

namespace bb
{

inline constexpr char const byte_chars[16] = {
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

inline constexpr char const byte_chars_upper[16] = {
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

using byte_bin_str = array<char const, 9>;
using byte_hex_str = array<char const, 3>;

inline constexpr char to_digit( clamped<u8, 0, 9> value ) { return value + '0'; }

inline constexpr byte_bin_str as_binary_str( byte b )
{
    return {
    to_digit( ( as_u8( b ) & 0b1000'0000 ) >> 7 ),
    to_digit( ( as_u8( b ) & 0b0100'0000 ) >> 6 ),
    to_digit( ( as_u8( b ) & 0b0010'0000 ) >> 5 ),
    to_digit( ( as_u8( b ) & 0b0001'0000 ) >> 4 ),
    to_digit( ( as_u8( b ) & 0b0000'1000 ) >> 3 ),
    to_digit( ( as_u8( b ) & 0b0000'0100 ) >> 2 ),
    to_digit( ( as_u8( b ) & 0b0000'0010 ) >> 1 ),
    to_digit( ( as_u8( b ) & 0b0000'0001 ) >> 0 ),
    '\0' };
}

inline constexpr byte_hex_str as_hex_str( byte b )
{
    return { byte_chars[as_u8( b >> 4 )], byte_chars[as_u8( b & 0x0f )], '\0' };
}

inline constexpr byte_hex_str as_hex_str_upper( byte b )
{
    return { byte_chars_upper[as_u8( b >> 4 )], byte_chars_upper[as_u8( b & 0x0f )], '\0' };
}

} // namespace bb
