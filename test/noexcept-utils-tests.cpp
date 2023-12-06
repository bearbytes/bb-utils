#include <bb/noexcept-utils.h>

#include "utils/dummy-structs.h"

using namespace bb;
using namespace bb::test;

auto main() -> int
{
    static_assert( is_noexcept_default_constructible<f64>() );
    static_assert( is_noexcept_destructible<f64>() );
    static_assert( is_noexcept_copy_constructible<f64>() );
    static_assert( is_noexcept_move_constructible<f64>() );
    static_assert( is_noexcept_copy_assignable<f64>() );
    static_assert( is_noexcept_move_assignable<f64>() );
    static_assert( is_noexcept_eq_comparable<f64>() );

    static_assert( is_noexcept_default_constructible<S>() );
    static_assert( is_noexcept_destructible<S>() );
    static_assert( not is_noexcept_copy_constructible<S>() );
    static_assert( is_noexcept_move_constructible<S>() );
    static_assert( not is_noexcept_copy_assignable<S>() );
    static_assert( is_noexcept_move_assignable<S>() );
    static_assert( is_noexcept_eq_comparable<S>() );
}
