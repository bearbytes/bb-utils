#pragma once

#include <bb/basic-types.h>

// This must be in global scope for placement new to work.
inline constexpr auto operator new( bb::size n [[maybe_unused]], void * p ) noexcept -> void *
{
    return p;
}
