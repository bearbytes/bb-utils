#pragma once

#include <bb/restricted.h>

namespace bb
{

template <class T, size N>
struct array {
    static_assert( N > 0 );

    using index = restricted<size, 0, N - 1>;

    T data[N]{};

    constexpr auto first() const noexcept -> T const & { return data[0]; }
    constexpr auto last() const noexcept -> T const & { return data[N - 1]; }

    constexpr auto first() noexcept -> T & { return data[0]; }
    constexpr auto last() noexcept -> T & { return data[N - 1]; }

    constexpr auto begin() const noexcept -> T const * { return data; }
    constexpr auto end() const noexcept -> T const * { return data + N; }

    constexpr auto begin() noexcept -> T * { return data; }
    constexpr auto end() noexcept -> T * { return data + N; }

    [[nodiscard]] constexpr auto size() const noexcept -> bb::size { return N; }

    constexpr auto contains( T const & element ) const noexcept( noexcept_eq_comparable<T>() ) -> bool
    {
        for ( T const & item : *this ) {
            if ( item == element ) {
                return true;
            }
        }
        return false;
    }

    constexpr auto fill( T const & value ) noexcept( noexcept_copy_assignable<T>() ) -> void
    {
        for ( T & item : *this ) {
            item = value;
        }
    }

    constexpr operator T *() noexcept { return data; }
    constexpr operator T const *() const noexcept { return data; }

    constexpr auto operator[]( bb::size n ) const noexcept -> T const & { return data[index( n )]; }
    constexpr auto operator[]( bb::size n ) noexcept -> T & { return data[index( n )]; }
};

template <class T, typename... Ts>
array( T, Ts... ) -> array<T, 1 + sizeof...( Ts )>;

} // namespace bb
