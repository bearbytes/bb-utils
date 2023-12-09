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
    u8 idx = 0;
    bool const _ [[maybe_unused]] = ( ( is_same<T, Ts> ? true : ( ++idx, false ) ) or ... );
    return idx;
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
    static constexpr u8 invalid_index = u8_max;

    constexpr auto copy_construct( variant const & other ) noexcept( noexcept_copy_constructible<Ts...>() ) -> void
    {
        bool const _ [[maybe_unused]] =
        ( ( other.index_ == detail::index_of<Ts, Ts...>()
            ? ( copy_construct<Ts>( other.as<Ts>(), other.index_ ), true )
            : false ) or
          ... );
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto copy_construct( T const & t, u8 type_index ) noexcept( noexcept_copy_constructible<T>() )
    -> void
    {
        new ( &placeholder_, custom_new ) T{ t };
        index_ = type_index;
    }

    constexpr auto copy_assign( variant const & other ) noexcept( noexcept_copy_assignable<Ts...>() ) -> void
    {
        bool const _ [[maybe_unused]] =
        ( ( other.index_ == detail::index_of<Ts, Ts...>()
            ? ( copy_assign<Ts>( other.as<Ts>(), other.index_ ), true )
            : false ) or
          ... );
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto copy_assign( T const & t, u8 type_index ) noexcept( noexcept_copy_assignable<T>() ) -> void
    {
        as<T>() = t;
        index_ = type_index;
    }

    constexpr auto move_construct( variant && other ) noexcept( noexcept_move_constructible<Ts...>() ) -> void
    {
        bool const _ [[maybe_unused]] =
        ( ( other.index_ == detail::index_of<Ts, Ts...>()
            ? ( move_construct<Ts>( as_movable( other.as<Ts>() ), other.index_ ), true )
            : false ) or
          ... );

        // Invalidate other variant to make sure we don't try to call destructor twice.
        other.index_ = invalid_index;
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto move_construct( T && t, u8 type_index ) noexcept( noexcept_move_constructible<T>() ) -> void
    {
        new ( &placeholder_, custom_new ) T{ as_forwarding<T>( t ) };
        index_ = type_index;
    }

    constexpr auto move_assign( variant && other ) noexcept( noexcept_move_assignable<Ts...>() ) -> void
    {
        bool const _ [[maybe_unused]] =
        ( ( other.index_ == detail::index_of<Ts, Ts...>()
            ? ( move_assign<Ts>( as_movable( other.as<Ts>() ), other.index_ ), true )
            : false ) or
          ... );

        // Invalidate other variant to make sure we don't try to call destructor twice.
        other.index_ = invalid_index;
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto move_assign( T && t, u8 type_index ) noexcept( noexcept_move_assignable<T>() ) -> void
    {
        as<T>() = as_forwarding<T>( t );
        index_ = type_index;
    }

    constexpr auto destroy() noexcept( noexcept_destructible<Ts...>() ) -> void
    {
        bool const _ [[maybe_unused]] =
        ( ( index_ == detail::index_of<Ts, Ts...>() ? ( destroy<Ts>(), true ) : false ) or ... );
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto destroy() noexcept( noexcept_destructible<T>() ) -> void
    {
        reinterpret_cast<T *>( &placeholder_ )->~T();
        index_ = invalid_index;
    }

    u8 index_{ invalid_index };
    u8 placeholder_[detail::max_size<Ts...>()]{};

public:
    constexpr variant() noexcept = default;

    constexpr variant( invalid_variant_t /*v*/ ) noexcept {}

    constexpr variant( variant const & other ) noexcept( noexcept_copy_constructible<Ts...>() ) :
    index_{ other.index_ }
    {
        if ( other.is_valid() ) {
            copy_construct( other );
        }
    }

    constexpr variant( variant && other ) noexcept( noexcept_move_constructible<Ts...>() ) :
    index_{ other.index_ }
    {
        if ( other.is_valid() ) {
            move_construct( as_movable( other ) );
        }
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr variant( T const & t ) noexcept( noexcept_copy_constructible<T>() )
    {
        copy_construct<T>( t, detail::index_of<T, Ts...>() );
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr variant( T && t ) noexcept( noexcept_move_constructible<T>() )
    {
        move_construct<T>( as_forwarding<T>( t ), detail::index_of<T, Ts...>() );
    }

    constexpr ~variant() noexcept( noexcept_destructible<Ts...>() ) { reset(); }

    auto operator=( variant const & other ) noexcept(
    noexcept_destructible<Ts...>() and noexcept_copy_constructible<Ts...>() and
    noexcept_copy_assignable<Ts...>() ) -> variant &
    {
        if ( this == &other or ( !is_valid() and !other.is_valid() ) ) {
            return *this;
        }

        if ( is_valid() ) {
            // Copy-assign if indices match, destroy this data otherwise
            bool const _ [[maybe_unused]] =
            ( ( index_ == detail::index_of<Ts, Ts...>()
                ? ( ( index_ == other.index_ ? copy_assign<Ts>( other.as<Ts>(), index_ ) : destroy<Ts>() ), true )
                : false ) or
              ... );
        }

        if ( other.is_valid() ) {
            copy_construct( other );
        }

        return *this;
    }

    constexpr auto operator=( variant && other ) noexcept(
    noexcept_destructible<Ts...>() and noexcept_move_constructible<Ts...>() and
    noexcept_move_assignable<Ts...>() ) -> variant &
    {
        if ( this == &other or ( !this->is_valid() and !other.is_valid() ) ) {
            return *this;
        }

        if ( is_valid() ) {
            // Move-assign if indices match, destroy this data otherwise
            bool const _ [[maybe_unused]] =
            ( ( index_ == detail::index_of<Ts, Ts...>()
                ? ( ( index_ == other.index_ ? ( move_assign<Ts>( as_movable( other.as<Ts>() ), index_ ),
                                                 bb::as<void>( other.index_ = invalid_index ) )
                                             : destroy<Ts>() ),
                    true )
                : false ) or
              ... );
        }

        if ( other.is_valid() ) {
            move_construct( as_movable( other ) );
        }

        return *this;
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto operator=( T const & t ) noexcept(
    noexcept_destructible<Ts...>() and noexcept_copy_constructible<T>() and noexcept_copy_assignable<T>() )
    -> variant &
    {
        constexpr u8 index = detail::index_of<T, Ts...>();
        if ( index == index_ ) {
            copy_assign<T>( t, index );
        } else {
            reset();
            copy_construct<T>( t, index );
        }
        return *this;
    }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    constexpr auto operator=( T && t ) noexcept(
    noexcept_destructible<Ts...>() and noexcept_move_constructible<T>() and noexcept_move_assignable<T>() )
    -> variant &
    {
        constexpr u8 index = detail::index_of<T, Ts...>();
        if ( index == index_ ) {
            move_assign<T>( as_forwarding<T>( t ), index );
        } else {
            reset();
            move_construct<T>( as_forwarding<T>( t ), index );
        }
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
        return index_ == other.index_ and
               ( index_ == invalid_index or
                 ( ( index_ == detail::index_of<Ts, Ts...>() ? as<Ts>() == other.as<Ts>() : false ) or ... ) );
    }

    [[nodiscard]] constexpr auto is_valid() const noexcept -> bool
    {
        return index_ != invalid_index;
    }

    [[nodiscard]] constexpr auto id() const noexcept -> u8 { return index_; }

    template <class T>
    requires ( is_one_of<T, Ts...> )
    [[nodiscard]] constexpr auto is() const noexcept -> bool
    {
        return index_ == detail::index_of<T, Ts...>();
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

    template <class V, class... Args>
    constexpr auto apply( V && visitor, Args &&... args ) const -> void
    {
        assert( is_valid() );
        bool const _ [[maybe_unused]] =
        ( ( index_ == detail::index_of<Ts, Ts...>() ? ( visitor( as<Ts>( as_forwarding<Args>( args )... ) ), true ) : false ) or
          ... );
    }

    template <class V, class... Args>
    constexpr auto apply( V && visitor, Args &&... args ) -> void
    {
        assert( is_valid() );
        bool const _ [[maybe_unused]] =
        ( ( index_ == detail::index_of<Ts, Ts...>() ? ( visitor( as<Ts>( as_forwarding<Args>( args )... ) ), true ) : false ) or
          ... );
    }
};

} // namespace bb
