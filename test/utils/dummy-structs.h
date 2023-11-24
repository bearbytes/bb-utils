#pragma once

namespace bb::test
{

struct S {
    constexpr S() {}

    constexpr S( S const & ) noexcept( true ) {}
    constexpr S( S && ) {}

    constexpr S & operator=( S const & ) noexcept( false ) { return *this; }
    constexpr S & operator=( S && ) { return *this; }

    constexpr auto operator==( S const & ) const noexcept -> bool { return true; }
};

} // namespace bb::test
