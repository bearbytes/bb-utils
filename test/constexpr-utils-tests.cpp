#include <bb/constexpr-utils.h>

#include "utils/dummy-structs.h"

using namespace bb;
using namespace bb::test;

auto main() -> int
{
    static_assert( is_noexcept_copy_constructible<S>() );
    static_assert( !is_noexcept_copy_assignable<S>() );
    static_assert( is_noexcept_eq_comparable<S>() );

    constexpr int a[] = { 1, 2, 3, 4, 5 };
    static_assert( array_size( a ) == 5 );
}
