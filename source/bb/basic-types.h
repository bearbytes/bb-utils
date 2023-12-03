#pragma once

namespace bb
{

using size = unsigned long int;

using u8 = unsigned char;
using i8 = signed char;

using u16 = unsigned short int;
using i16 = signed short int;

using u32 = unsigned int;
using i32 = signed int;

using u64 = unsigned long int;
using i64 = signed long int;

using f32 = float;
using f64 = double;

static_assert( sizeof( u8 ) == 1 );
static_assert( sizeof( i8 ) == 1 );

static_assert( sizeof( u16 ) == 2 );
static_assert( sizeof( i16 ) == 2 );

static_assert( sizeof( u32 ) == 4 );
static_assert( sizeof( i32 ) == 4 );

static_assert( sizeof( u64 ) == 8 );
static_assert( sizeof( i64 ) == 8 );

static_assert( sizeof( f32 ) == 4 );
static_assert( sizeof( f64 ) == 8 );

} // namespace bb
