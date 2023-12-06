#include <bb/assert.h>
#include <bb/variant.h>

using namespace bb;

auto main() -> int
{
    constexpr variant<int> v1{};
    static_assert( !v1.is_valid() );

    constexpr variant<bool, int, char, double> v2{};
    static_assert( !v2.is_valid() );
    static_assert( !v2.is<int>() );
    static_assert( !v2.is<double>() );
    static_assert( v2.id() == u8_max );

    variant<int> v3{ 5 };
    assert( v3.is_valid() );
    assert( v3.is<int>() );
    assert( v3.as<int>() == 5 );

    variant<int, double> v4{ 5 };
    assert( v4.is_valid() );
    assert( v4.id() == 0 );
    assert( v4.is<int>() );
    assert( v4.as<int>() == 5 );

    v4 = 2.0;
    assert( v4.is_valid() );
    assert( v4.id() == 1 );
    assert( v4.is<double>() );
    assert( v4.as<double>() == 2.0 );
}
