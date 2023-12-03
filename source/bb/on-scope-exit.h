#pragma once

#include <bb/constexpr-utils.h>

namespace bb
{

template <class F>
class on_scope_exit {
    F action_;

public:
    constexpr on_scope_exit( F action ) noexcept( is_noexcept_copy_constructible<F>() ) :
    action_{ action }
    {}

    // TODO: noexcept if F dtor is noexcept
    constexpr ~on_scope_exit() noexcept( noexcept( declval<F>()() ) ) { action_(); }
};

} // namespace bb
