#pragma once

#include <bb/assert.h>
#include <bb/constexpr-utils.h>
#include <bb/noexcept-utils.h>

namespace bb
{

template <class T>
class span {
    T * data_{ nullptr };
    size length_{ 0 };

    [[nodiscard]] constexpr auto is_not_empty() const noexcept -> bool
    {
        return data_ != nullptr and length_ > 0;
    }

public:
    constexpr span() noexcept = default;
    constexpr ~span() noexcept = default;

    constexpr span( span const & ) noexcept = default;
    constexpr span( span && ) noexcept = default;

    constexpr auto operator=( span const & ) noexcept -> span & = default;
    constexpr auto operator=( span && ) noexcept -> span & = default;

    constexpr span( T * data, size length ) : data_{ data }, length_{ length } {}

    template <size N>
    constexpr span( T ( &array )[N] ) : span{ &( array[0] ), N }
    {}

    constexpr auto first() const noexcept -> T const &
    {
        assert( is_not_empty() );
        return data_[0];
    }
    constexpr auto last() const noexcept -> T const &
    {
        assert( is_not_empty() );
        return data_[length_ - 1];
    }

    constexpr auto first() noexcept -> T &
    {
        assert( is_not_empty() );
        return data_[0];
    }
    constexpr auto last() noexcept -> T &
    {
        assert( is_not_empty() );
        return data_[length_ - 1];
    }

    constexpr auto begin() const noexcept -> T const * { return data_; }
    constexpr auto end() const noexcept -> T const * { return data_ + length_; }

    constexpr auto begin() noexcept -> T * { return data_; }
    constexpr auto end() noexcept -> T * { return data_ + length_; }

    [[nodiscard]] constexpr auto size() const noexcept -> bb::size { return length_; }
    [[nodiscard]] constexpr auto is_empty() const noexcept -> bool { return length_ == 0; }

    constexpr auto take_first() noexcept( noexcept_copy_constructible<T>() ) -> T
    {
        assert( is_not_empty() );
        T & tmp = first();
        ++data_;
        --length_;
        return tmp;
    }

    constexpr auto take_last() noexcept( noexcept_copy_constructible<T>() ) -> T
    {
        assert( is_not_empty() );
        T & tmp = last();
        --length_;
        return tmp;
    }

    constexpr auto shrink_front( bb::size n ) noexcept -> void
    {
        assert( data_ != nullptr );
        if ( n < length_ ) {
            data_ += n;
            length_ -= n;
        } else {
            data_ = nullptr;
            length_ = 0;
        }
    }

    constexpr auto shrink_back( bb::size n ) noexcept -> void
    {
        if ( n < length_ ) {
            length_ -= n;
        } else {
            data_ = nullptr;
            length_ = 0;
        }
    }

    constexpr auto contains( T const & element ) const noexcept( noexcept_eq_comparable<T>() ) -> bool
    {
        for ( T const & item : *this ) {
            if ( item == element ) {
                return true;
            }
        }
        return false;
    }

    constexpr operator T const *() const noexcept { return data_; }
    constexpr operator T *() noexcept { return data_; }

    constexpr auto operator[]( bb::size n ) const noexcept -> T const &
    {
        assert( n < length_ );
        assert( data_ != nullptr );
        return data_[n];
    }
    constexpr auto operator[]( bb::size n ) noexcept -> T &
    {
        assert( n < length_ );
        assert( data_ != nullptr );
        return data_[n];
    }
};

} // namespace bb
