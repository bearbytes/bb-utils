#include <bb/callable.h>

#include "utils/dynamic-assert.h"

using namespace bb;
using namespace bb::test;

int global_value = 0;

auto function_1() -> void { global_value = 1; }
auto function_2() -> int { return ++global_value; }
auto function_3( int p ) -> int { return global_value + p; }

auto main() -> int
{
    callable c1 = function_1;
    dynamic_assert( c1.is_active() && global_value == 0 );
    c1();
    dynamic_assert( global_value == 1 );

    callable c2 = function_2;
    dynamic_assert( c2.is_active() );
    dynamic_assert( c2() == 2 );

    callable c3 = function_3;
    dynamic_assert( c3.is_active() );
    dynamic_assert( c3( 5 ) == 7 );

    callable c4 = c1;
    dynamic_assert( c1.is_active() );
    c4();
    dynamic_assert( global_value == 1 );

    callable c5 = bb::move( c2 );
    dynamic_assert( c5.is_active() && !c2.is_active() );
    dynamic_assert( c5() == 2 );

    callable<int, int> c6{};
    dynamic_assert( !c6.is_active() );
    c6 = c3;
    dynamic_assert( c6.is_active() && c3.is_active() );
    dynamic_assert( c6( 1 ) == 3 );

    callable<int, int> c7{};
    dynamic_assert( !c7.is_active() );
    c7 = move( c6 );
    dynamic_assert( c7.is_active() && !c6.is_active() );
    dynamic_assert( c7( 2 ) == 4 );
}
