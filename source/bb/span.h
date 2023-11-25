#pragma once

#include <bb/constexpr-utils.h>

namespace bb
{

template <class T>
class span {
    T * data_{};
    size length_{};

public:
    span() = default;
    ~span() = default;

    span( span const & ) = default;
    span( span && ) = default;

    auto operator=( span const & ) -> span & = default;
    auto operator=( span && ) -> span & = default;

    constexpr span( T * data, size length ) : data_{ data }, length_{ length } {}

    template <size N>
    constexpr span( T ( &array )[N] ) : span{ &( array[0] ), N }
    {}

    constexpr auto first() const noexcept -> T const & { return data_[0]; }
    constexpr auto last() const noexcept -> T const & { return data_[length_ - 1]; }

    constexpr auto first() noexcept -> T & { return data_[0]; }
    constexpr auto last() noexcept -> T & { return data_[length_ - 1]; }

    constexpr auto begin() const noexcept -> T const * { return data_; }
    constexpr auto end() const noexcept -> T const * { return data_ + length_; }

    constexpr auto begin() noexcept -> T * { return data_; }
    constexpr auto end() noexcept -> T * { return data_ + length_; }

    [[nodiscard]] constexpr auto size() const noexcept -> bb::size { return length_; }
    [[nodiscard]] constexpr auto is_empty() const noexcept -> bool { return length_ == 0; }

    constexpr auto take_first() noexcept( is_noexcept_copy_assignable<T>() ) -> T
    {
        T & tmp = first();
        ++data_;
        --length_;
        return tmp;
    }

    constexpr auto take_last() noexcept( is_noexcept_copy_assignable<T>() ) -> T
    {
        T & tmp = last();
        --length_;
        return tmp;
    }

    constexpr auto shrink_front( bb::size n ) noexcept -> void
    {
        if ( length_ >= n ) {
            data_ += n;
            length_ -= n;
        } else {
            data_ = nullptr;
            length_ = 0;
        }
    }

    constexpr auto shrink_back( bb::size n ) noexcept -> void
    {
        if ( length_ >= n ) {
            length_ -= n;
        } else {
            data_ = nullptr;
            length_ = 0;
        }
    }

    constexpr auto contains( T const & element ) const noexcept( is_noexcept_eq_comparable<T>() ) -> bool
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

    constexpr auto operator[]( bb::size n ) const noexcept -> T const & { return data_[n]; }
    constexpr auto operator[]( bb::size n ) noexcept -> T & { return data_[n]; }
};

} // namespace bb
