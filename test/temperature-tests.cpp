#include <bb/temperature.h>

using namespace bb;

auto main() -> int
{
    constexpr temperature zero_k = temperature::from_kelvin( 0 );
    constexpr temperature zero_c = temperature::from_celsius( 0 );
    constexpr temperature zero_f = temperature::from_fahrenheit( 0 );

    static_assert( zero_k < zero_c );
    static_assert( zero_k < zero_f );
    static_assert( zero_f < zero_c );

    static_assert( zero_c == temperature::from_millikelvin( 273'150 ) );
    static_assert( zero_c == temperature::from_fahrenheit( 32 ) );
    static_assert( temperature::from_celsius( 100 ) == temperature::from_fahrenheit( 212 ) );
}
