#include <bb/on-scope-exit.h>

#include "utils/dynamic-assert.h"

using namespace bb;
using namespace bb::test;

int global_value = 0;
auto function() -> void { global_value = 15; }

auto main() -> int
{
    int value = 5;
    {
        auto guard = on_scope_exit( [&value] { value = 10; } );
    }
    dynamic_assert( value == 10 );

    {
        auto guard = on_scope_exit( function );
    }
    dynamic_assert( global_value == 15 );
}
