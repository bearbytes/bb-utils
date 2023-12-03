#pragma once

#include <cassert>

namespace bb
{

template <class T, T min, T max>
class restricted {
    static_assert( max >= min );

    static auto value_out_of_bounds() {}
    static constexpr auto restrict( T value ) -> T
    {
        if ( value > max or value < min ) {
            if consteval {
                value_out_of_bounds();
            } else {
                assert( false );
            }
        }
        return value;
    }

    T value_{ min };

public:
    constexpr restricted( T value ) noexcept : value_{ restrict( value ) } {}

    constexpr operator T() { return value_; }
};

} // namespace bb
