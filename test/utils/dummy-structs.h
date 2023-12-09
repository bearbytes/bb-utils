#pragma once

namespace bb::test
{

struct copy_only_t {
    copy_only_t() = default;
    ~copy_only_t() = default;

    copy_only_t( copy_only_t const & ) = default;
    copy_only_t( copy_only_t && ) = delete;

    auto operator=( copy_only_t const & ) -> copy_only_t & = default;
    auto operator=( copy_only_t && ) -> copy_only_t & = delete;
};

struct move_only_t {
    move_only_t() = default;
    ~move_only_t() = default;

    move_only_t( move_only_t const & ) = delete;
    move_only_t( move_only_t && ) = default;

    auto operator=( move_only_t const & ) -> move_only_t & = delete;
    auto operator=( move_only_t && ) -> move_only_t & = default;
};

struct copy_move_t {
    copy_move_t() = default;
    ~copy_move_t() = default;

    copy_move_t( copy_move_t const & ) = default;
    copy_move_t( copy_move_t && ) = default;

    auto operator=( copy_move_t const & ) -> copy_move_t & = default;
    auto operator=( copy_move_t && ) -> copy_move_t & = default;
};

struct no_copy_or_move_t {
    no_copy_or_move_t() = default;
    ~no_copy_or_move_t() = default;

    no_copy_or_move_t( no_copy_or_move_t const & ) = delete;
    no_copy_or_move_t( no_copy_or_move_t && ) = delete;

    auto operator=( no_copy_or_move_t const & ) -> no_copy_or_move_t & = delete;
    auto operator=( no_copy_or_move_t && ) -> no_copy_or_move_t & = delete;
};

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
