#include <bb/byte.h>

using namespace bb;

auto main() -> int
{
    constexpr byte byte_0{ 0x00 };
    constexpr byte byte_1{ 0x01 };
    constexpr byte byte_2{ 0x02 };

    static_assert( as_u8( byte_2 ) == 2 );
    static_assert( as_byte( 1 ) == byte_1 );

    static_assert( ( byte_0 | byte_1 ) == byte_1 );
    static_assert( ( byte_1 | byte_2 ) == as_byte( 0x03 ) );
    static_assert( ( byte_2 | 0x00 ) == byte_2 );

    static_assert( ( byte_0 & byte_1 ) == byte_0 );
    static_assert( ( byte_1 & byte_2 ) == byte_0 );
    static_assert( ( byte_2 & 0xFF ) == byte_2 );

    static_assert( ( byte_0 ^ byte_1 ) == byte_1 );
    static_assert( ( byte_1 ^ byte_2 ) == as_byte( 0x03 ) );
    static_assert( ( byte_2 ^ 0x03 ) == byte_1 );

    static_assert( ( byte_0 << 1 ) == byte_0 );
    static_assert( ( byte_1 << 1 ) == byte_2 );
    static_assert( ( byte_2 << 7 ) == byte_0 );

    static_assert( ( byte_0 >> 1 ) == byte_0 );
    static_assert( ( byte_1 >> 1 ) == byte_0 );
    static_assert( ( byte_2 >> 1 ) == byte_1 );

    static_assert( ~byte_0 == as_byte( 0xFF ) );
}
