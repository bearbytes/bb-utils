#pragma once

namespace bb
{

namespace detail
{

inline auto run_time_assert( bool condition, char const * msg [[maybe_unused]] = nullptr ) noexcept -> void
{
    if ( !condition ) {
        // Crash program execution with segmentation fault
        *reinterpret_cast<int volatile *>( 0 ) = 0;
    }
}

inline constexpr auto compile_time_assert( bool condition, char const * msg = nullptr ) noexcept -> void
{
    if ( !condition ) {
        // Crash compilation execution with a call to non-constexpr function from a const-evaluated
        // expression
        run_time_assert( condition, msg );
    }
}

} // namespace detail

inline constexpr auto assert( bool condition, char const * msg = nullptr ) noexcept -> void
{
    if consteval {
        detail::compile_time_assert( condition, msg );
    } else {
        detail::run_time_assert( condition, msg );
    }
}

} // namespace bb
