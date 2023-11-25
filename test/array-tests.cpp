#include <bb/array.h>

#include "utils/dummy-structs.h"

using namespace bb;
using namespace bb::test;

static constexpr auto zeroed_array() -> array<int, 5>
{
    array a = { 1, 2, 3, 4, 5 };
    a.fill( 0 );
    return a;
}

auto main() -> int
{
    constexpr array<int, 5> a = { 1, 2, 3, 4, 5 };
    static_assert( a.size() == 5 );
    static_assert( a[0] == a.first() );
    static_assert( a[4] == a.last() );
    static_assert( a.end() == a.begin() + 5 );
    static_assert( a.contains( 1 ) and a.contains( 3 ) and a.contains( 5 ) );
    static_assert( noexcept( declval<array<int, 5>>() = a ) );

    constexpr array b = { S{}, S{}, S{} };
    static_assert( noexcept( b.contains( declval<S &>() ) ) );
    static_assert( !noexcept( declval<array<S, 2>>().fill( declval<S const &>() ) ) );

    constexpr array c = zeroed_array();
    static_assert( c[0] == 0 and c.first() == 0 );
    static_assert( c[4] == 0 and c.last() == 0 );
}
