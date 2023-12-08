#include <bb/assert.h>
#include <bb/optional.h>

using namespace bb;

auto main() -> int
{
    constexpr optional<i32> o1{};
    static_assert( !o1.has_value() );
    static_assert( !o1 );

    optional o2 = 10;
    assert( as<bool>( o2 ) );
    assert( o2.has_value() );
    assert( o2.value() == 10 );

    o2 = 20;
    assert( o2.has_value() );
    assert( o2.value() == 20 );

    optional o3 = 20;
    assert( o2 == o3 );
    assert( *o3 == 20 );

    o3.reset();
    assert( !o3.has_value() );
}
