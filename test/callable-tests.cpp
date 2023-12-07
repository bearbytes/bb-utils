#include <bb/assert.h>
#include <bb/callable.h>

using namespace bb;

int global_value = 0;

auto function_1() -> void { global_value = 1; }
auto function_2() -> int { return ++global_value; }
auto function_3( int p ) -> int { return global_value + p; }

auto main() -> int
{
    callable c1 = function_1;
    assert( c1.is_valid() and global_value == 0 );
    c1();
    assert( global_value == 1 );

    callable c2 = function_2;
    assert( c2.is_valid() );
    assert( c2() == 2 );

    callable c3 = function_3;
    assert( c3.is_valid() );
    assert( c3( 5 ) == 7 );

    callable c4 = c1;
    assert( c1.is_valid() );
    c4();
    assert( global_value == 1 );

    callable c5 = bb::as_movable( c2 );
    assert( c5.is_valid() and !c2.is_valid() );
    assert( c5() == 2 );

    callable<int, int> c6{};
    assert( !c6.is_valid() );
    c6 = c3;
    assert( c6.is_valid() and c3.is_valid() );
    assert( c6( 1 ) == 3 );

    callable<int, int> c7{};
    assert( !c7.is_valid() );
    c7 = as_movable( c6 );
    assert( c7.is_valid() and !c6.is_valid() );
    assert( c7( 2 ) == 4 );
    c7.reset();
    assert( !c7.is_valid() );
}
