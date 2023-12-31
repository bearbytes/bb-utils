#pragma once

#include <bb/basic-types-utils.h>

namespace bb
{

inline constexpr size size_min = 0x00'00'00'00'00'00'00'00;
inline constexpr size size_max = 0xFF'FF'FF'FF'FF'FF'FF'FF;

inline constexpr u8 u8_min = 0x00; // 0
inline constexpr u8 u8_max = 0xFF; // 255

inline constexpr i8 i8_min = as_i8( 0x80 ); // -128
inline constexpr i8 i8_max = 0x7F; // 127

inline constexpr u16 u16_min = 0x00'00; // 0
inline constexpr u16 u16_max = 0xFF'FF; // 65'535

inline constexpr i16 i16_min = as_i16( 0x80'00 ); // -32'768
inline constexpr i16 i16_max = 0x7F'FF; // 32'767

inline constexpr u32 u32_min = 0x00'00'00'00; // 0
inline constexpr u32 u32_max = 0xFF'FF'FF'FF; // 4'294'967'295

inline constexpr i32 i32_min = as_i32( 0x80'00'00'00 ); // -2'147'483'648
inline constexpr i32 i32_max = 0x7F'FF'FF'FF; // 2'147'483'647

inline constexpr u64 u64_min = 0x00'00'00'00'00'00'00'00; // 0
inline constexpr u64 u64_max = 0xFF'FF'FF'FF'FF'FF'FF'FF; // 18'446'744'073'709'551'615

inline constexpr i64 i64_min = as_i64( 0x80'00'00'00'00'00'00'00 ); // -9'223'372'036'854'775'808
inline constexpr i64 i64_max = 0x7F'FF'FF'FF'FF'FF'FF'FF; // 9'223'372'036'854'775'807

inline constexpr f32 f32_nan = as_f32( __builtin_nan( "0" ) );
inline constexpr f32 f32_inf = as_f32( __builtin_huge_val() );

inline constexpr f64 f64_nan = __builtin_nan( "0" );
inline constexpr f64 f64_inf = __builtin_huge_val();

} // namespace bb
