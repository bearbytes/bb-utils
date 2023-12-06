#include <bb/span.h>

using namespace bb;

constexpr int a[5] = { 1, 2, 3, 4, 5 };

constexpr auto shrink_front( span<i32 const> s, size n ) noexcept -> span<i32 const>
{
    s.shrink_front( n );
    return s;
}

constexpr auto shrink_back( span<i32 const> s, size n ) noexcept -> span<i32 const>
{
    s.shrink_back( n );
    return s;
}

auto main() -> int
{
    static_assert( noexcept_default_constructible<span<int>>() );
    static_assert( noexcept_copy_constructible<span<int>>() );
    static_assert( noexcept_move_constructible<span<int>>() );

    constexpr span<int> s1{};
    static_assert( s1.is_empty() );
    static_assert( s1.size() == 0 );
    static_assert( s1.begin() == nullptr );
    static_assert( s1.end() == nullptr );

    constexpr span s2 = s1;
    static_assert( s2.is_empty() );
    static_assert( s2.size() == 0 );
    static_assert( s2.begin() == nullptr );
    static_assert( s2.end() == nullptr );

    constexpr span s3 = a;
    static_assert( !s3.is_empty() );
    static_assert( s3.size() == 5 );
    static_assert( s3.begin() == a );
    static_assert( s3.contains( 1 ) and s3.contains( 3 ) and s3.contains( 5 ) );

    constexpr span s4 = shrink_front( s3, 2 );
    static_assert( s4.size() == 3 );
    static_assert( s4.contains( 3 ) and s3.contains( 4 ) and s3.contains( 5 ) );

    constexpr span s5 = shrink_back( s4, 3 );
    static_assert( s5.is_empty() );
}
