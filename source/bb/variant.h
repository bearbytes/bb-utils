#pragma once

#include <bb/basic-types-limits.h>
#include <bb/constexpr-utils.h>
#include <bb/new.h>

namespace bb
{

template <class T, class U>
constexpr bool is_same = false;

template <class T>
constexpr bool is_same<T, T> = true;

template <class T, class... Ts>
constexpr bool is_one_of = ( is_same<T, Ts> || ... );

template <class T, class... Ts>
constexpr bool are_types_unique = !is_one_of<T, Ts...> && are_types_unique<Ts...>;

template <class T>
constexpr bool are_types_unique<T> = true;

template <class... Ts>
requires ( sizeof...( Ts ) > 0 )
consteval auto max_size() -> size
{
    size result = 0;
    ( ( result = sizeof( Ts ) > result ? sizeof( Ts ) : result ), ... );
    return result;
}

template <class T, class... Ts>
consteval auto index_of() -> u8
{
    u8 r = u8_max;
    u8 x = 0;
    bool const _ [[maybe_unused]] = ( ( is_same<T, Ts> ? ( r = x, true ) : ( x++, false ) ) || ... );
    return r;
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

template <class... Ts>
requires ( sizeof...( Ts ) > 0 and sizeof...( Ts ) < u8_max and are_types_unique<Ts...> )
class variant {
    static constexpr u8 invalid_variant_index = u8_max;

    template <class T>
    constexpr auto construct( T && t ) noexcept -> void
    {
        new ( &placeholder_ ) T{ as_forwarding<T>( t ) };
        variant_index_ = index_of<T, Ts...>();
    }

    constexpr auto destroy() -> void
    {
        bool const _ [[maybe_unused]] =
        ( ( variant_index_ == index_of<Ts, Ts...>() ? ( destroy_type<Ts>(), true ) : false ) || ... );
    }

    template <class T>
    constexpr auto destroy_type() -> void
    {
        reinterpret_cast<T *>( &placeholder_ )->~T();
    }

    u8 variant_index_{ invalid_variant_index };
    u8 placeholder_[max_size<Ts...>()]{};

public:
    constexpr variant() noexcept = default;

    // TODO
    constexpr variant( variant const & other ) = delete;
    constexpr variant( variant && other ) = delete;

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr variant( T && t ) : variant_index_( index_of<T, Ts...>() )
    {
        construct( as_forwarding<T>( t ) );
    }

    constexpr ~variant()
    {
        if ( is_valid() ) {
            destroy();
        }
    }

    // TODO
    auto operator=( variant const & other ) -> variant & = delete;
    auto operator=( variant && other ) -> variant & = delete;

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto operator=( T && value ) -> variant &
    {
        if ( is_valid() ) {
            destroy();
        }
        construct( as_forwarding<T>( value ) );
        return *this;
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
        return variant_index_ == index_of<T, Ts...>();
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto as() noexcept -> T &
    {
        constexpr u8 index = index_of<T, Ts...>();
        return *reinterpret_cast<type_of_index<index, Ts...> *>( placeholder_ );
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto as() const noexcept -> T const &
    {
        constexpr u8 index = index_of<T, Ts...>();
        return *reinterpret_cast<type_of_index<index, Ts...> const *>( placeholder_ );
    }
};

} // namespace bb
