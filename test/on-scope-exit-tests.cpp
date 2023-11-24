#include <bb/on-scope-exit.h>

#include "utils/dynamic-assert.h"

using namespace bb;
using namespace bb::test;

int main()
{
    int value = 5;
    {
        auto guard = on_scope_exit( [&value] { value = 10; } );
    }

    dynamic_assert( value == 10 );
}
