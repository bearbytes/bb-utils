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

    variant<bool, char> v5{};
    assert( !v5.is_valid() );
    v5 = false;
    assert( v5.is_valid() );
    assert( v5.is<bool>() );
    assert( !v5.as<bool>() );
    v5 = 'a';
    assert( v5.is_valid() );
    assert( v5.is<char>() );
    assert( v5.as<char>() == 'a' );

    variant v6 = v5;
    assert( v6.is_valid() );
    assert( v6.is<char>() );
    assert( v6.as<char>() == 'a' );

    v5 = v6;
    assert( v5.is_valid() );
    assert( v5.is<char>() );
    assert( v5.as<char>() == 'a' );

    v6 = variant<bool, char>{};
    assert( !v6.is_valid() );
    v6 = as_movable( v5 );
    assert( !v5.is_valid() );

    variant<bool, i32, f64> v7 = 10;
    variant<bool, i32, f64> v8 = 10;
    assert( v7 == v8 );
    v8 = 15;
    assert( v7 != v8 );
    v8 = 2.0;
    assert( v7 != v8 );
    v7 = v8 = {};
    assert( v7 == v8 );

    v8 = 3.14;
    assert( v8.is<f64>() );
    v8.reset();
    assert( !v8.is_valid() );
}
