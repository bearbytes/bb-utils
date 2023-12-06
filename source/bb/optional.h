#pragma once

#include <bb/variant.h>

namespace bb
{

template <class T>
class optional {
    variant<T> value_{};

public:
    constexpr optional() noexcept = default;

    constexpr optional( T const & value ) noexcept( noexcept_copy_constructible<T>() ) :
    value_{ value }
    {}

    constexpr optional( optional const & ) noexcept( noexcept_copy_constructible<T>() ) = default;
    constexpr optional( optional && ) noexcept( noexcept_move_constructible<T>() ) = default;

    constexpr ~optional() noexcept( noexcept_default_constructible<T>() ) = default;

    constexpr auto operator=( optional const & ) noexcept( noexcept_copy_assignable<T>() )
    -> optional & = default;
    constexpr auto operator=( optional && ) noexcept( noexcept_move_assignable<T>() ) -> optional & = default;

    [[nodiscard]] constexpr auto operator==( optional const & ) const
    noexcept( noexcept_eq_comparable<T>() ) -> bool = default;

    explicit constexpr operator bool() const noexcept { return has_value(); }

    constexpr auto operator*() const noexcept -> T const &
    {
        assert( has_value() );
        return value();
    }

    [[nodiscard]] constexpr auto value() const noexcept -> T const &
    {
        assert( value_.is_valid() );
        return value_.template as<T>();
    }

    [[nodiscard]] constexpr auto has_value() const noexcept -> bool { return value_.is_valid(); }

    constexpr auto reset() noexcept( noexcept_destructible<T>() ) -> void { value_ = {}; }
};

template <class T>
optional( T ) -> optional<T>;

} // namespace bb
