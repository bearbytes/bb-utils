#pragma once

#include <bb/assert.h>
#include <bb/constexpr-utils.h>
#include <bb/noexcept-utils.h>

namespace bb
{

template <class T, T min, T max>
class restricted {
    static_assert( max >= min );

    T value_;

public:
    constexpr restricted( T value ) noexcept( noexcept_copy_constructible<T>() ) : value_{ value }
    {
        assert( value >= min and value <= max, "Value out of bounds" );
    }

    constexpr operator T() const noexcept( noexcept_copy_constructible<T>() ) { return value_; }
};

} // namespace bb
