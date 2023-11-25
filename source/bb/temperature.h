#pragma once

#include <bb/basic-types-utils.h>
#include <bb/basic-types.h>

namespace bb
{

class temperature {
    constexpr explicit temperature( u32 millikelvin ) noexcept : millikelvin_{ millikelvin } {}

    u32 millikelvin_;

public:
    static constexpr auto from_millikelvin( u32 mk ) noexcept -> temperature
    {
        return temperature{ mk };
    }

    static constexpr auto from_kelvin( u32 k ) noexcept -> temperature
    {
        return from_millikelvin( k * 1000 );
    }

    static constexpr auto from_millicelsius( i32 mc ) noexcept -> temperature
    {
        return temperature{ as_u32( mc + 273'150 ) };
    }

    static constexpr auto from_celsius( i32 c ) noexcept -> temperature
    {
        return from_millicelsius( c * 1000 );
    }

    static constexpr auto from_millifahrneheit( i32 mf ) noexcept -> temperature
    {
        return temperature{ as_u32( ( mf + 459'670 ) * 5 / 9 ) };
    }

    static constexpr auto from_fahrenheit( i32 f ) noexcept -> temperature
    {
        return from_millifahrneheit( f * 1000 );
    }

    [[nodiscard]] constexpr auto as_millikelvin() const noexcept -> i32 { return millikelvin_; }

    [[nodiscard]] constexpr auto as_kelvin() const noexcept -> i32
    {
        return as_millikelvin() / 1000;
    }

    [[nodiscard]] constexpr auto as_millicelsius() const noexcept -> i32
    {
        return millikelvin_ - 273'150;
    }

    [[nodiscard]] constexpr auto as_celsius() const noexcept -> i32
    {
        return as_millicelsius() / 1000;
    }

    [[nodiscard]] constexpr auto as_millifahrneheit() const noexcept -> i32
    {
        return ( millikelvin_ * 9 - 2'298'350 ) / 5;
    }

    [[nodiscard]] constexpr auto get_fahrenheit() const noexcept -> i32
    {
        return as_millifahrneheit() / 1000;
    }

    constexpr auto operator<=>( temperature const & other ) const noexcept -> i64
    {
        return as_i64( millikelvin_ ) - as_i64( other.millikelvin_ );
    }

    constexpr auto operator==( temperature const & other ) const noexcept -> bool = default;
};

} // namespace bb
