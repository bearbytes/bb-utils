#include <bb/assert.h>
#include <bb/basic-types-limits.h>
#include <bb/basic-types-utils.h>
#include <bb/basic-types.h>

using namespace bb;

auto main() -> int
{
    // Casts to u8, i8, u16, and i16 must be given because C++ implicitly
    // promotes types (casts them into int).
    static_assert( as_u8( u8_max + 1 ) == u8_min );
    static_assert( as_u16( u16_max + 1 ) == u16_min );
    static_assert( u32_max + 1 == u32_min );
    static_assert( u64_max + 1 == u64_min );

    static_assert( as_u8( u8_min - 1 ) == u8_max );
    static_assert( as_u16( u16_min - 1 ) == u16_max );
    static_assert( u32_min - 1 == u32_max );
    static_assert( u64_min - 1 == u64_max );

    // Assertions for i32 and i64 must be done at runtime because signed
    // integer overflow is a non-constexpr undefined behavior.
    static_assert( as_i8( i8_max + 1 ) == i8_min );
    static_assert( as_i16( i16_max + 1 ) == i16_min );
    assert( as_i32( ( unsigned )i32_max + 1 ) == i32_min );
    assert( as_i64( ( unsigned long )i64_max + 1 ) == i64_min );

    static_assert( as_i8( i8_min - 1 ) == i8_max );
    static_assert( as_i16( i16_min - 1 ) == i16_max );
    assert( as_i32( ( unsigned )i32_min - 1 ) == i32_max );
    assert( as_i64( ( unsigned long )i64_min - 1 ) == i64_max );

    static_assert( as_u8( u16_max ) == u8_max );
    static_assert( as_u8( u32_max ) == u8_max );
    static_assert( as_u8( u64_max ) == u8_max );
    static_assert( as_u16( u32_max ) == u16_max );
    static_assert( as_u16( u64_max ) == u16_max );
    static_assert( as_u32( u64_max ) == u32_max );

    static_assert( as_u8( u16_min ) == u8_min );
    static_assert( as_u8( u32_min ) == u8_min );
    static_assert( as_u8( u64_min ) == u8_min );
    static_assert( as_u16( u32_min ) == u16_min );
    static_assert( as_u16( u64_min ) == u16_min );
    static_assert( as_u32( u64_min ) == u32_min );

    static_assert( as_i8( i16_max ) == as_i8( u8_max ) );
    static_assert( as_i8( i32_max ) == as_i8( u8_max ) );
    static_assert( as_i8( i64_max ) == as_i8( u8_max ) );
    static_assert( as_i16( i32_max ) == as_i16( u16_max ) );
    static_assert( as_i16( i64_max ) == as_i16( u16_max ) );
    static_assert( as_i32( i64_max ) == as_i32( u32_max ) );

    static_assert( as_i8( i16_min ) == as_i8( u8_min ) );
    static_assert( as_i8( i32_min ) == as_i8( u8_min ) );
    static_assert( as_i8( i64_min ) == as_i8( u8_min ) );
    static_assert( as_i16( i32_min ) == as_i16( u16_min ) );
    static_assert( as_i16( i64_min ) == as_i16( u16_min ) );
    static_assert( as_i32( i64_min ) == as_i32( u32_min ) );

    static_assert( f32_nan != f32_nan );
    static_assert( f32_nan != f32_inf );
    static_assert( f32_inf == f32_inf );

    static_assert( f64_nan != f64_nan );
    static_assert( f64_nan != f64_inf );
    static_assert( f64_inf == f64_inf );
}
