#include <bb/duration.h>

using namespace bb;

auto main() -> int
{
    constexpr duration zero = duration::zero();
    constexpr duration one_ns = duration::from_nanoseconds( 1 );
    constexpr duration one_us = duration::from_microseconds( 1 );
    constexpr duration one_ms = duration::from_milliseconds( 1 );
    constexpr duration one_s = duration::from_seconds( 1 );
    constexpr duration one_m = duration::from_minutes( 1 );
    constexpr duration one_h = duration::from_hours( 1 );
    constexpr duration inf = duration::infinity();

    static_assert( one_ns > zero );
    static_assert( one_us > zero );
    static_assert( one_ms > zero );
    static_assert( one_s > zero );
    static_assert( one_m > zero );
    static_assert( one_h > zero );

    static_assert( one_us > one_ns );
    static_assert( one_ms > one_ns );
    static_assert( one_s > one_ns );
    static_assert( one_m > one_ns );
    static_assert( one_h > one_ns );

    static_assert( one_ms > one_us );
    static_assert( one_s > one_us );
    static_assert( one_m > one_us );
    static_assert( one_h > one_us );

    static_assert( one_s > one_ms );
    static_assert( one_m > one_ms );
    static_assert( one_h > one_ms );

    static_assert( one_m > one_s );
    static_assert( one_h > one_s );

    static_assert( one_h > one_m );

    static_assert( one_ns < inf );
    static_assert( one_us < inf );
    static_assert( one_ms < inf );
    static_assert( one_s < inf );
    static_assert( one_m < inf );
    static_assert( one_h < inf );

    static_assert( one_us == duration::from_nanoseconds( 1000 ) );
    static_assert( one_ms == duration::from_microseconds( 1000 ) );
    static_assert( one_s == duration::from_milliseconds( 1000 ) );
    static_assert( one_m == duration::from_seconds( 60 ) );
    static_assert( one_h == duration::from_minutes( 60 ) );

    static_assert( one_us - duration::from_nanoseconds( 1000 ) == zero );
    static_assert( one_ms - duration::from_microseconds( 1000 ) == zero );
    static_assert( one_s - duration::from_milliseconds( 1000 ) == zero );
    static_assert( one_m - duration::from_seconds( 60 ) == zero );
    static_assert( one_h - duration::from_minutes( 60 ) == zero );

    static_assert( duration::from_nanoseconds( 1000 ) - one_ns < one_us );
    static_assert( duration::from_microseconds( 1000 ) - one_ns < one_ms );
    static_assert( duration::from_milliseconds( 1000 ) - one_ns < one_s );
    static_assert( duration::from_seconds( 60 ) - one_ns < one_m );
    static_assert( duration::from_minutes( 60 ) - one_ns < one_h );

    static_assert( ( one_ms - duration::from_nanoseconds( 1'000'000 ) ).is_zero() );
    static_assert( inf.is_infinity() );
}
