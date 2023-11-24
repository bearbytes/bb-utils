#pragma once

#include <cassert>

namespace bb::test
{

constexpr auto dynamic_assert( bool condition ) noexcept -> void { assert( condition ); }

}
