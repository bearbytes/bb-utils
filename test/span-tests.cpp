#include <bb/span.h>

using namespace bb;

auto main() -> int
{
    static_assert( noexcept( span<int>() ) );
    static_assert( noexcept( declval<span<int>>() = span<int>() ) );
    static_assert( noexcept( declval<span<int>>() = declval<span<int>>() ) );

    constexpr span<int> s1{};
    constexpr span s2 = s1;
    static_assert( s1.is_empty() and s2.is_empty() );
    static_assert( s1.size() == 0 and s1.size() == s2.size() );

    constexpr int a[] = { 1, 2, 3, 4, 5 };
    span s3 = a;
    assert( s3.size() == array_size( a ) );
    assert( s3.contains( 1 ) and s3.contains( 3 ) and s3.contains( 5 ) );
    assert( s3.take_first() == 1 );
    assert( s3.size() == 4 );
    assert( s3.take_last() == 5 );
    assert( s3.size() == 3 );
    assert( s3.first() == 2 );
    assert( s3.last() == 4 );
    s3.shrink_front( 2 );
    assert( s3.size() == 1 );
}
