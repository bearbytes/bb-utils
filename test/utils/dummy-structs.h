#pragma once

namespace bb::test
{

struct S {
    constexpr S() = default;
    constexpr ~S() = default;

    constexpr S( S const & /*s*/ ) noexcept( false ) = default;
    constexpr S( S && /*s*/ ) noexcept( true ) {}

    constexpr auto operator=( S const & ) noexcept( false ) -> S & = default;
    constexpr auto operator=( S && ) noexcept( true ) -> S & = default;

    constexpr auto operator==( S const & /*s*/ ) const noexcept -> bool { return true; }
};

} // namespace bb::test
