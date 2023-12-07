#pragma once

#include <bb/basic-types.h>

inline constexpr struct custom_new_tag {
} custom_new;

// This must be in global scope for placement new to work.
[[nodiscard]] inline constexpr auto operator new(
bb::size n [[maybe_unused]], void * p, custom_new_tag /* t */ ) noexcept -> void *
{
    return p;
}
