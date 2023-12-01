#pragma once

namespace bb
{

inline void consteval_assert_false() {}

template <class T, T min, T max>
constexpr auto clamp( T value ) -> T
{
    if consteval {
        if ( value > max or value < min ) {
            consteval_assert_false();
        }
    }
    return value < min ? min : value > max ? max : value;
}

template <class T, T min, T max>
class clamped {
    static_assert( max >= min );

    T value_{ min };

public:
    constexpr clamped( T value ) noexcept : value_{ clamp<T, min, max>( value ) } {}

    constexpr operator T() { return value_; }
};

} // namespace bb
