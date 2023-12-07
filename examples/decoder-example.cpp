#include <bb/array.h>
#include <bb/byte.h>
#include <bb/span.h>
#include <bb/variant.h>

#include <print>

using namespace bb;

struct frame_a {
    static constexpr byte id{ 0x01 };

    u8 magic_value{};
};

struct frame_b {
    static constexpr byte id{ 0x02 };

    u8 magic_value{};
};

struct frame_c {
    static constexpr byte id{ 0x03 };

    u8 magic_value{};
};

auto read_bytes() noexcept -> span<byte const>
{
    static array<byte, 1024> buffer = { frame_c::id, byte{ 42 } };
    size const bytes_count = 2;

    return { buffer.data, bytes_count };
}

template <class... Frames>
auto decode( span<byte const> bytes ) -> variant<Frames...>
{
    if ( bytes.is_empty() ) {
        return invalid_variant;
    }

    byte const id = bytes.take_first();

    variant<Frames...> result = invalid_variant;
    bool const _ [[maybe_unused]] =
    ( ( id == Frames::id ? ( result = Frames{ as_u8( bytes.take_first() ) }, true ) : false ) or ... );

    return result;
}

template <class Frame>
auto print_magic( Frame const & frame, char const * suffix = "" ) noexcept -> void
{
    std::println( "magic value: {} {}", frame.magic_value, suffix );
}

auto main() -> int
{
    auto const bytes = read_bytes();
    std::println( "Read {} bytes", bytes.size() );

    auto maybe_frame = decode<frame_a, frame_b, frame_c>( bytes );
    if ( maybe_frame.is_valid() ) {
        if ( maybe_frame.is<frame_a>() ) {
            std::print( "Frame a, " );
        } else if ( maybe_frame.is<frame_b>() ) {
            std::print( "Frame b, " );
        } else if ( maybe_frame.is<frame_c>() ) {
            std::print( "Frame c, " );
        }

        maybe_frame.apply( []( auto const & frame ) { print_magic( frame, "millions" ); } );
    }
}
