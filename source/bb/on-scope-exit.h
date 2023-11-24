#pragma once

namespace bb
{

template <class F>
class on_scope_exit {
    F action_;

public:
    constexpr on_scope_exit( F action ) : action_{ action } {}

    constexpr ~on_scope_exit() { action_(); }
};

} // namespace bb
