#include <bb/assert.h>
#include <bb/noexcept-utils.h>
#include <bb/on-scope-exit.h>

using namespace bb;

int global_value = 0;
auto function() -> void { global_value = 15; }

auto main() -> int
{
    int value = 5;
    {
        auto guard = on_scope_exit( [&value] { value = 10; } );
    }
    assert( value == 10 );

    {
        auto guard = on_scope_exit( function );
    }
    assert( global_value == 15 );
}
