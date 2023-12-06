#include <bb/constexpr-utils.h>

using namespace bb;

auto main() -> int
{
    constexpr int a[] = { 1, 2, 3, 4, 5 };
    static_assert( array_size( a ) == 5 );
}
