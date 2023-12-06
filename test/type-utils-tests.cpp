#include <bb/basic-types.h>
#include <bb/type-utils.h>

using namespace bb;

auto main() -> int
{
    static_assert( is_same<i32, int> );
    static_assert( not is_same<i32, i16> );
    static_assert( not is_same<i32, u32> );
    static_assert( not is_same<i32, i32 const> );
    static_assert( is_same<void, void> );
    static_assert( is_same<void *, void *> );
    static_assert( not is_same<void *, void * const> );

    static_assert( is_same<i32, without_const<i32>> );
    static_assert( is_same<i32, without_const<i32 const>> );
    static_assert( is_same<void *, without_const<void *>> );
    static_assert( is_same<void *, without_const<void * const>> );
    static_assert( is_same<void const *, without_const<void const * const>> );

    static_assert( is_same<i32 &, i32 &> );
    static_assert( not is_same<i32 &, i32> );
    static_assert( not is_same<i32 const &, i32 &> );
    static_assert( is_same<i32 const &, i32 const &> );
    static_assert( is_same<i32, without_reference<i32 &>> );
    static_assert( is_same<i32 const, without_reference<i32 const &>> );
    static_assert( not is_same<i32, without_reference<i32 const &>> );

    static_assert( is_same<i32, pure<i32>> );
    static_assert( is_same<i32, pure<i32 const>> );
    static_assert( is_same<i32, pure<i32 &>> );
    static_assert( is_same<i32, pure<i32 const &>> );

    static_assert( is_one_of<i32, i8, i16, i32, i64> );
    static_assert( not is_one_of<bool, i8, i16, i32, i64> );

    static_assert( are_unique<i8, i16, i32, i64> );
    static_assert( not are_unique<i8, i16, i32, i64, i8> );
    static_assert( are_unique<char, unsigned char, signed char> );
}
