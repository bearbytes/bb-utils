#pragma once

#include <bb/basic-types-limits.h>

namespace bb
{

class duration {
    constexpr explicit duration( i64 nanoseconds ) noexcept : nanoseconds_{ nanoseconds } {}

    static constexpr i64 us_to_ns = 1000;
    static constexpr i64 ms_to_ns = 1'000'000;
    static constexpr i64 s_to_ns = 1'000'000'000;
    static constexpr i64 m_to_ns = 60'000'000'000;
    static constexpr i64 h_to_ns = 3'600'000'000'000;

    i64 nanoseconds_;

public:
    static constexpr auto from_nanoseconds( i64 ns ) noexcept -> duration { return duration{ ns }; }

    static constexpr auto from_microseconds( i64 us ) noexcept -> duration
    {
        return duration{ us * us_to_ns };
    }

    static constexpr auto from_milliseconds( i64 ms ) noexcept -> duration
    {
        return duration{ ms * ms_to_ns };
    }

    static constexpr auto from_seconds( i64 s ) noexcept -> duration
    {
        return duration{ s * s_to_ns };
    }

    static constexpr auto from_minutes( i64 m ) noexcept -> duration
    {
        return duration{ m * m_to_ns };
    }

    static constexpr auto from_hours( i64 h ) noexcept -> duration
    {
        return duration{ h * h_to_ns };
    }

    static constexpr auto zero() noexcept -> duration { return duration{ 0 }; }

    static constexpr auto infinity() noexcept -> duration { return duration{ i64_max }; }

    [[nodiscard]] constexpr auto as_nanoseconds() const noexcept -> i64 { return nanoseconds_; }

    [[nodiscard]] constexpr auto as_microseconds() const noexcept -> i64
    {
        return nanoseconds_ / us_to_ns;
    }

    [[nodiscard]] constexpr auto as_milliseconds() const noexcept -> i64
    {
        return nanoseconds_ / ms_to_ns;
    }

    [[nodiscard]] constexpr auto as_seconds() const noexcept -> i64
    {
        return nanoseconds_ / s_to_ns;
    }

    [[nodiscard]] constexpr auto as_minutes() const noexcept -> i64
    {
        return nanoseconds_ / m_to_ns;
    }

    [[nodiscard]] constexpr auto as_hours() const noexcept -> i64 { return nanoseconds_ / h_to_ns; }

    [[nodiscard]] constexpr auto is_zero() const noexcept -> bool { return nanoseconds_ == 0; }

    [[nodiscard]] constexpr auto is_infinity() const noexcept -> bool
    {
        return nanoseconds_ == i64_max;
    }

    constexpr auto operator+( duration const & other ) const noexcept -> duration
    {
        return duration::from_nanoseconds( nanoseconds_ + other.nanoseconds_ );
    }

    constexpr auto operator-( duration const & other ) const noexcept -> duration
    {
        return duration::from_nanoseconds( nanoseconds_ - other.nanoseconds_ );
    }

    constexpr auto operator+=( duration const & other ) noexcept -> duration
    {
        return duration::from_nanoseconds( nanoseconds_ += other.nanoseconds_ );
    }

    constexpr auto operator-=( duration const & other ) noexcept -> duration
    {
        return duration::from_nanoseconds( nanoseconds_ -= other.nanoseconds_ );
    }

    constexpr auto operator<=>( duration const & other ) const noexcept -> i64
    {
        return nanoseconds_ - other.nanoseconds_;
    }

    constexpr auto operator==( duration const & other ) const noexcept -> bool = default;
};

} // namespace bb
