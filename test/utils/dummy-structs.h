#pragma once

namespace bb::test
{

struct S {
    constexpr S() = default;

    constexpr S( S const & ) noexcept( true ) = default;
    constexpr S( S && ) {}

    constexpr auto operator=( S const & ) noexcept( false ) -> S & = default;
    constexpr auto operator=( S && ) -> S & = default;

    constexpr auto operator==( S const & ) const noexcept -> bool { return true; }
};

} // namespace bb::test
