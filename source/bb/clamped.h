#pragma once

namespace bb
{

template <class T, T min, T max>
class clamped {
    static_assert( max >= min );

    T value_{ min };

public:
    constexpr clamped( T value ) noexcept : value_{ value > max ? max : value < min ? min : value }
    {}

    constexpr operator T() { return value_; }
};

} // namespace bb
