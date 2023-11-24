#include <bb/byte-utils.h>

using namespace bb;

auto main() -> int
{
    static_assert( to_digit( 0 ) == '0' );
    static_assert( to_digit( 1 ) == '1' );
    static_assert( to_digit( 2 ) == '2' );
    static_assert( to_digit( 3 ) == '3' );
    static_assert( to_digit( 4 ) == '4' );
    static_assert( to_digit( 5 ) == '5' );
    static_assert( to_digit( 6 ) == '6' );
    static_assert( to_digit( 7 ) == '7' );
    static_assert( to_digit( 8 ) == '8' );
    static_assert( to_digit( 9 ) == '9' );

    constexpr byte byte_AB{ 0xAB };
    constexpr byte_hex_str ab = as_hex_str( byte_AB );
    constexpr byte_hex_str AB = as_hex_str_upper( byte_AB );
    static_assert( ab[0] == 'a' and ab[1] == 'b' );
    static_assert( AB[0] == 'A' and AB[1] == 'B' );

    constexpr byte byte_1111{ 0b0000'1111 };
    constexpr byte_bin_str s = as_binary_str( byte_1111 );
    static_assert( s[0] == '0' and s[1] == '0' and s[2] == '0' and s[3] == '0' and s[4] == '1' and
                   s[5] == '1' and s[6] == '1' and s[7] == '1' );
}
