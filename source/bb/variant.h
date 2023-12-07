#pragma once

#include <bb/basic-types-limits.h>
#include <bb/new.h>
#include <bb/noexcept-utils.h>

namespace bb
{

namespace detail
{

template <class... Ts>
requires ( sizeof...( Ts ) > 0 )
inline consteval auto max_size() noexcept -> size
{
    size result = 0;
    ( ( result = sizeof( Ts ) > result ? sizeof( Ts ) : result ), ... );
    return result;
}

template <class T, class... Ts>
requires ( is_one_of<T, Ts...> )
inline consteval auto index_of() noexcept -> u8
{
    u8 result = u8_max;
    u8 x = 0;
    bool const _ [[maybe_unused]] = ( ( is_same<T, Ts> ? ( result = x, true ) : ( x++, false ) ) || ... );
    return result;
}

template <u8 I, class... Ts>
struct index_to_type;

template <class T, class... Ts>
struct index_to_type<0, T, Ts...> {
    using type = T;
};

template <u8 I, class T, class... Ts>
struct index_to_type<I, T, Ts...> {
    using type = index_to_type<I - 1, Ts...>::type;
};

template <u8 I, class... Ts>
using type_of_index = index_to_type<I, Ts...>::type;

} // namespace detail

inline constexpr struct invalid_variant_t {
} invalid_variant;

template <class... Ts>
requires ( sizeof...( Ts ) > 0 and sizeof...( Ts ) < u8_max and are_unique<Ts...> )
class variant {
    static constexpr u8 invalid_variant_index = u8_max;

    constexpr auto copy( variant const & other ) noexcept( noexcept_copy_constructible<Ts...>() ) -> void
    {
        bool const _ [[maybe_unused]] =
        ( ( other.variant_index_ == detail::index_of<Ts, Ts...>() ? ( copy_construct<Ts>( other.as<Ts>() ), true ) : false ) ||
          ... );
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto copy_construct( T const & t ) noexcept( noexcept_copy_constructible<T>() ) -> void
    {
        new ( &placeholder_, custom_new ) T{ t };
        variant_index_ = detail::index_of<T, Ts...>();
    }

    constexpr auto move( variant && other ) noexcept( noexcept_move_constructible<Ts...>() ) -> void
    {
        bool const _ [[maybe_unused]] =
        ( ( other.variant_index_ == detail::index_of<Ts, Ts...>()
            ? ( move_construct<Ts>( as_movable( other.as<Ts>() ) ), other.variant_index_ = invalid_variant_index, true )
            : false ) ||
          ... );
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto move_construct( T && t ) noexcept( noexcept_move_constructible<T>() ) -> void
    {
        new ( &placeholder_, custom_new ) T{ as_movable( t ) };
        variant_index_ = detail::index_of<T, Ts...>();
    }

    constexpr auto destroy() noexcept( noexcept_destructible<Ts...>() ) -> void
    {
        bool const _ [[maybe_unused]] =
        ( ( variant_index_ == detail::index_of<Ts, Ts...>() ? ( destroy_type<Ts>(), true ) : false ) || ... );
        variant_index_ = invalid_variant_index;
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto destroy_type() noexcept( noexcept_destructible<T>() ) -> void
    {
        reinterpret_cast<T *>( &placeholder_ )->~T();
    }

    u8 variant_index_{ invalid_variant_index };
    u8 placeholder_[detail::max_size<Ts...>()]{};

public:
    constexpr variant() noexcept = default;

    constexpr variant( invalid_variant_t /*v*/ ) noexcept {}

    constexpr variant( variant const & other ) noexcept( noexcept_copy_constructible<Ts...>() )
    {
        if ( other.is_valid() ) {
            copy( other );
        }
    }

    constexpr variant( variant && other ) noexcept( noexcept_move_assignable<Ts...>() )
    {
        if ( other.is_valid() ) {
            move( as_movable( other ) );
        }
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr variant( T const & t ) noexcept( noexcept_copy_constructible<T>() )
    {
        copy_construct( t );
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr variant( T && t ) noexcept( noexcept_move_constructible<T>() )
    {
        move_construct( as_movable( t ) );
    }

    constexpr ~variant() noexcept( noexcept_destructible<Ts...>() )
    {
        if ( is_valid() ) {
            destroy();
        }
    }

    auto operator=( variant const & other ) noexcept(
    noexcept_destructible<Ts...>() && noexcept_copy_constructible<Ts...>() ) -> variant &
    {
        if ( this == &other ) {
            return *this;
        }

        if ( is_valid() ) {
            destroy();
        }

        if ( !other.is_valid() ) {
            return *this;
        }

        copy( other );

        return *this;
    }

    constexpr auto operator=( variant && other ) noexcept( noexcept_move_assignable<Ts...>() ) -> variant &
    {
        if ( this == &other ) {
            return *this;
        }

        if ( is_valid() ) {
            destroy();
        }

        if ( !other.is_valid() ) {
            return *this;
        }

        move( as_movable( other ) );

        return *this;
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto operator=( T const & value ) noexcept(
    noexcept_destructible<Ts...>() and noexcept_copy_constructible<T>() ) -> variant &
    {
        if ( is_valid() ) {
            destroy();
        }
        copy_construct( value );
        return *this;
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto operator=( T && value ) noexcept(
    noexcept_destructible<Ts...>() and noexcept_move_constructible<T>() ) -> variant &
    {
        if ( is_valid() ) {
            destroy();
        }
        move( as_movable( value ) );
        return *this;
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    [[nodiscard]] constexpr auto operator==( T const & value ) const
    noexcept( noexcept_eq_comparable<T>() ) -> bool
    {
        if ( !is<T>() ) {
            return false;
        }
        return as<T>() == value;
    }

    [[nodiscard]] constexpr auto operator==( variant const & other ) const
    noexcept( noexcept_eq_comparable<Ts...>() ) -> bool
    {
        return variant_index_ == other.variant_index_ and
               ( variant_index_ == invalid_variant_index or
                 ( ( variant_index_ == detail::index_of<Ts, Ts...>() ? as<Ts>() == other.as<Ts>() : false ) or ... ) );
    }

    [[nodiscard]] constexpr auto is_valid() const noexcept -> bool
    {
        return variant_index_ != invalid_variant_index;
    }

    [[nodiscard]] constexpr auto id() const noexcept -> u8 { return variant_index_; }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    [[nodiscard]] constexpr auto is() const noexcept -> bool
    {
        return variant_index_ == detail::index_of<T, Ts...>();
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto as() noexcept -> T &
    {
        constexpr u8 index = detail::index_of<T, Ts...>();
        return *reinterpret_cast<detail::type_of_index<index, Ts...> *>( placeholder_ );
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto as() const noexcept -> T const &
    {
        constexpr u8 index = detail::index_of<T, Ts...>();
        return *reinterpret_cast<detail::type_of_index<index, Ts...> const *>( placeholder_ );
    }

    constexpr auto reset() noexcept( noexcept_destructible<Ts...>() ) -> void
    {
        if ( is_valid() ) {
            destroy();
        }
    }
};

} // namespace bb
